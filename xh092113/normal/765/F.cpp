#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define glc(u) (u << 1)
#define grc(u) ((u << 1) | 1)

const int N = 1e5;
const int M = 3e5;
const int TN = 33 * N;
const int W = 1e9;
const int inf = 0x3f3f3f3f;

typedef pair<int,int>pii;

namespace IO{
	In int read(){
		int s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(int x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

//SegTree
struct ValueSegTree{
	int cnt;
	int lc[TN+5],rc[TN+5],maxn[TN+5];
	In void init(){cnt = 1;}
	In void pushup(int u){
		maxn[u] = max(maxn[lc[u]],maxn[rc[u]]);
	}
	int query(int u,int l,int r,int ql,int qr){
//cout<<"VT::query: u="<<u<<" l="<<l<<" r="<<r<<" ql="<<ql<<" qr="<<qr<<endl;
		if(!u)return 0;		 
		if(ql == l && qr == r)return maxn[u];
		int m = (l + r) >> 1;
		if(qr <= m)return query(lc[u],l,m,ql,qr);
		else if(ql > m)return query(rc[u],m + 1,r,ql,qr);
		else return max(query(lc[u],l,m,ql,m),query(rc[u],m+1,r,m+1,qr));
	}
	void ud(int u,int l,int r,int ax,int x){
//cout<<"VT::ud: u="<<u<<" l="<<l<<" r="<<r<<" ax="<<ax<<" x="<<x<<endl;
		if(l == r){
			maxn[u] = max(maxn[u],x);
			return;
		}
		int m = (l + r) >> 1;
		if(ax <= m){
			if(!lc[u])lc[u] = ++cnt;
			ud(lc[u],l,m,ax,x);	
		}
		else{
			if(!rc[u])rc[u] = ++cnt;
			ud(rc[u],m + 1,r,ax,x);
		}
		pushup(u);
	}
}VT;

struct SegTree{
	int minn[(N<<2)+5];
	In void init(int u,int l,int r){
		minn[u] = inf;
		if(l == r)return;
		int m = (l + r) >> 1;
		init(glc(u),l,m);
		init(grc(u),m + 1,r);
	}
	In void pushup(int u){
		minn[u] = min(minn[glc(u)],minn[grc(u)]);
	}
	void ud(int u,int l,int r,int x,int cur){
//cout<<"T::ud: u="<<u<<" l="<<l<<" r="<<r<<" x="<<x<<" cur="<<cur<<endl;
		if(l == r){
			minn[u] = min(minn[u],cur);
			return;
		}
		int m = (l + r) >> 1;
		if(x <= m)ud(glc(u),l,m,x,cur);
		else ud(grc(u),m + 1,r,x,cur);
		pushup(u);
	}
	int query(int u,int l,int r,int ql,int qr){
//cout<<"T::query: u="<<u<<" l="<<l<<" r="<<r<<" ql="<<ql<<" qr="<<qr<<endl;
		if(l == ql && r == qr)return minn[u];
		int m = (l + r) >> 1;
		if(qr <= m)return query(glc(u),l,m,ql,qr);
		else if(ql > m)return query(grc(u),m + 1,r,ql,qr);
		else return min(query(glc(u),l,m,ql,m),query(grc(u),m+1,r,m+1,qr));
	}
}T;

//main
int a[N+5],ans[M+5];
int n,m;
vector<pii>q[N+5];

int main(){
//	freopen("CF765F.in","r",stdin);
//	freopen("CF765F.out","w",stdout);
	n = read();
	for(rg int i = 1;i <= n;i++)a[i] = read();
	m = read();
	for(rg int i = 1;i <= m;i++){
		int l = read(),r = read();
		q[r].push_back(make_pair(l,i));
	}
	
	VT.init();
	T.init(1,1,n);

	for(rg int r = 1;r <= n;r++){
//cout<<"r="<<r<<endl;
		int L,R = a[r],i;
		i = VT.query(1,0,W,0,R);
//cout<<"part1"<<endl;
//cout<<"i="<<i<<endl;		
		if(i){
			T.ud(1,1,n,i,R - a[i]);
			L = a[i];
			while(L < R){
				i = VT.query(1,0,W,(L+1+R)>>1,R);
//cout<<"i="<<i<<endl;
				if(!i)break;
				T.ud(1,1,n,i,R - a[i]);
				L = a[i];
			}			
		}
		
//cout<<"part2"<<endl;		
		L = a[r];
		i = VT.query(1,0,W,L,W);
//cout<<"i="<<i<<endl;		
		if(i){
			T.ud(1,1,n,i,a[i] - L);
			R = a[i];
			while(L < R){
				i = VT.query(1,0,W,L,(L+R-1)>>1);
//cout<<"i="<<i<<endl;
				if(!i)break;
				T.ud(1,1,n,i,a[i] - L);
				R = a[i];
			}
		}
		VT.ud(1,0,W,a[r],r);
		for(i = 0;i < q[r].size();i++){
			int l = q[r][i].first,id = q[r][i].second;
			ans[id] = T.query(1,1,n,l,r - 1);
		}
	}
	
	for(rg int i = 1;i <= m;i++)write(ans[i]),putchar('\n');
//clock_t s = clock();
//while(clock() - s < 1e8);
	return 0;
}