#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define glc(u) (u << 1)
#define grc(u) ((u << 1) | 1)

const int N = 3e5;
const int inf = 0x3f3f3f3f;

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
};
using namespace IO;

int n,Q;
int a[N+5],p[N+5];

struct SegTree{
	int maxn[4*N+5],flag[4*N+5];
	In void pushup(int u){
		maxn[u] = max(maxn[glc(u)],maxn[grc(u)]);
	}
	In void pushdown(int u){
		if(!flag[u])return;
		int lc = glc(u),rc = grc(u);
		maxn[lc] += flag[u];
		maxn[rc] += flag[u];
		flag[lc] += flag[u];
		flag[rc] += flag[u];
		flag[u] = 0;
	}
	In void ud(int u,int l,int r,int ql,int qr){
		if(l == ql && r == qr){
			flag[u]++,maxn[u]++;
			return;
		}
		int m = (l + r) >> 1;
		pushdown(u);
		if(qr <= m)ud(glc(u),l,m,ql,qr);
		else if(ql > m)ud(grc(u),m + 1,r,ql,qr);
		else ud(glc(u),l,m,ql,m),ud(grc(u),m + 1,r,m + 1,qr);		
		pushup(u);
	}
	In int query(int u,int l,int r,int x){
		if(l == r)return l;
		int m = (l + r) >> 1;
		pushdown(u);
		if(maxn[grc(u)] >= x)return query(grc(u),m + 1,r,x);
		else return query(glc(u),l,m,x);
	}
}T;

struct CMTree{
	int rt[N+5],cnt,sum[22*N+5],lc[22*N+5],rc[22*N+5];
	In void pushup(int u){
		sum[u] = sum[lc[u]] + sum[rc[u]];
	}
	void ud(int u1,int u2,int l,int r,int pos){
		if(l == r){sum[u2] = sum[u1] + 1;return;}
		int m = (l + r) >> 1;
		if(pos <= m){
			cnt++;
			lc[u2] = cnt,rc[u2] = rc[u1];
			ud(lc[u1],lc[u2],l,m,pos);	
		}
		else{
			cnt++;
			rc[u2] = cnt,lc[u2] = lc[u1];
			ud(rc[u1],rc[u2],m + 1,r,pos);
		}
		pushup(u2);
	}
	int query(int u1,int u2,int l,int r,int ql,int qr){
		if(l == ql && r == qr)return sum[u2] - sum[u1];
		int m = (l + r) >> 1;
		if(qr <= m)return query(lc[u1],lc[u2],l,m,ql,qr);
		else if(ql > m)return query(rc[u1],rc[u2],m + 1,r,ql,qr);
		else return query(lc[u1],lc[u2],l,m,ql,m) + query(rc[u1],rc[u2],m + 1,r,m + 1,qr);
	}
	void init(){
		rt[0] = ++cnt;
		for(rg int i = 1;i <= n;i++){
			rt[i] = ++cnt;
			ud(rt[i-1],rt[i],0,n,p[i]);
		}
	}
}T2;

int main(){
//	freopen("CF1404C.in","r",stdin);
//	freopen("CF1404C.out","w",stdout);

	n = read(),Q = read();
	for(rg int i = 1;i <= n;i++)a[i] = read();
	for(rg int i = 1;i <= n;i++){
		if(a[i] > i)p[i] = 0;
		else if(a[i] == i)p[i] = i;
		else p[i] = T.query(1,0,n,i - a[i]);
		T.ud(1,0,n,0,p[i]);
	}
//for(rg int i = 1;i <= n;i++)cout<<p[i]<<" ";cout<<endl;
	
	T2.init();
	for(rg int i = 1;i <= Q;i++){
		int x = read(),y = read();
		int l = x + 1,r = n - y;
		write(T2.query(T2.rt[l-1],T2.rt[r],0,n,l,n));
		putchar('\n');
	}

	return 0;
}