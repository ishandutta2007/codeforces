#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define glc(u) (u << 1)
#define grc(u) ((u << 1) | 1)

const int N = 5e5;
const int inf = 0x3f3f3f3f;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
using namespace IO;

int n,z;
int a[N+5],p[N+5],up[N+5];
vector<int> pos[N+5];

struct SegTree{
	int minn[4*N+5],flag[4*N+5];
	In void pushup(int u){
		minn[u] = min(minn[glc(u)],minn[grc(u)]);
	}
	In void pushdown(int u){
		if(flag[u] == 0)return;
		int lc = glc(u),rc = grc(u);
		flag[lc] += flag[u],minn[lc] += flag[u];
		flag[rc] += flag[u],minn[rc] += flag[u];
		flag[u] = 0;
	}
	void build(int u,int l,int r){
		flag[u] = 0;
		if(l == r){minn[u] = l - 1;return;}
		int m = (l + r) >> 1;
		build(glc(u),l,m),build(grc(u),m + 1,r);
		pushup(u);
	}
	void ud(int u,int l,int r,int ql,int qr,int dx){
		if(l == ql && r == qr){
			flag[u] += dx,minn[u] += dx;
			return;
		}
		pushdown(u);
		int m = (l + r) >> 1;
		if(qr <= m)ud(glc(u),l,m,ql,qr,dx);
		else if(ql > m)ud(grc(u),m + 1,r,ql,qr,dx);
		else ud(glc(u),l,m,ql,m,dx),ud(grc(u),m + 1,r,m + 1,qr,dx);
		pushup(u);
	}
	int query(int u,int l,int r,int ql,int qr){
		if(l == ql && r == qr)return minn[u];
		pushdown(u);
		int m = (l + r) >> 1;
		if(qr <= m)return query(glc(u),l,m,ql,qr);
		else if(ql > m)return query(grc(u),m + 1,r,ql,qr);
		else return min(query(glc(u),l,m,ql,m),query(grc(u),m+1,r,m+1,qr));
	}
}T;

void clear(){
	z = 0;
	up[0] = inf;
	for(rg int i = 1;i <= n + 1;i++)up[i] = -1;
	for(rg int i = 1;i <= n;i++){
		pos[i].resize(0);
		pos[i].push_back(0);
	}
}
void solve(){
	n = read();
	clear();
	for(rg int i = 1;i <= n;i++){
		a[i] = read();	
		if(a[i] == 0)p[++z] = i;
	}
	T.build(1,1,n);
	for(rg int i = 1;i <= z;i++){
		for(rg int j = p[i-1] + 1;j < p[i];j++){
			int id = a[j];
			int lastpos = pos[id][pos[id].size()-1];
			pos[id].push_back(j);
			if(lastpos > p[i-1])continue;
			int L = 1,R = i;
			while(L < R){
				int mid = (L + R) >> 1;
				if(p[mid] <= lastpos)L = mid + 1;
				else R = mid;
			}
			if(L <= i - 1)T.ud(1,1,n,L,i - 1,1);
		}
		if(2 * i - 2 >= z){
			int x = T.query(1,1,n,1,i);
			up[z+1-i] = x + z - i;
		}
	}
	for(rg int i = 1;i <= z;i++)up[i] = min(up[i],up[i-1]);
	int ans = 0;
	while(ans + 1 <= up[ans+1])ans++;
	write(ans),putchar('\n');
}

int main(){
//	freopen("CF1408H.in","r",stdin);
//	freopen("CF1408H.out","w",stdout);
//initialize: never use memset!!!
	int Tc = read();
	while(Tc--)solve();
	return 0;
}