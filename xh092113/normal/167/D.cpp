#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

typedef pair<int,int> pii;

const int N = 1e5;
const ll mod = 1e9 + 9;
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
}
using namespace IO;

int n,m,k;
ll a,b,c,d;
pii p[N+5];

struct CtsTree{
	int fa[N+5],lc[N+5],rc[N+5],f[N+5][2];
	int s[N+5],top;
	int rt;
	void init(int u){
		if(lc[u])init(lc[u]);
		if(rc[u])init(rc[u]);
		pushup(u);
	}
	void build(){
		for(rg int i = 1;i <= n;i++){
			while(top && p[i].second > p[s[top]].second)
				lc[i] = s[top--];
			fa[i] = s[top];
			if(lc[i])fa[lc[i]] = i;
			if(fa[i])rc[fa[i]] = i;
			else rt = i;
			s[++top] = i;
		}
		init(rt);
	}
	In void pushup(int u){
		int l = lc[u],r = rc[u];
		if(l && r){
			f[u][0] = max(f[l][0],f[l][1]) + max(f[r][0],f[r][1]);
			f[u][1] = max(max(f[l][0],f[l][1]) + f[r][0] + 1,
						  max(f[r][0],f[r][1]) + f[l][0] + 1);
		}
		else if(l || r){
			int v = l + r;
			f[u][0] = max(f[v][0],f[v][1]);
			f[u][1] = f[v][0] + 1;
		}
		else f[u][0] = f[u][1] = 0;
	}
	int merge(int u,int v){
		if(!u || !v)return u + v;
		if(p[u].second > p[v].second){
			rc[u] = merge(rc[u],v);
			pushup(u);
			return u;
		}
		else{
			lc[v] = merge(u,lc[v]);
			pushup(v);
			return v;
		}
	}
	void split(int u,int x,int &v,int &w){
		if(!u)v = w = 0;
		else{
			if(u <= x){
				v = u;
				split(rc[u],x,rc[v],w);
			}
			else{
				w = u;
				split(lc[u],x,v,lc[w]);
			}
			pushup(u);
		}
	}
	int query(int l,int r){
		int u,v,w;
		split(rt,r,u,v);
		split(u,l - 1,u,w);
		int ans = max(f[w][0],f[w][1]);
		rt = merge(merge(u,w),v);
		return ans;
	}
}T;

int main(){
//	freopen("CF167D.in","r",stdin);
//	freopen("CF167D.out","w",stdout);

	n = read(),k = read();
	for(rg int i = 1;i <= k;i++)p[i].first = read(),p[i].second = read();
	a = read(),b = read(),c = read(),d = read();
	for(rg int i = k + 1;i <= n;i++){
		p[i].first = (a * p[i-1].first + b) % mod;
		p[i].second = (c * p[i-1].second + d) % mod;
	}

	sort(p + 1,p + n + 1);
	T.build();
	
	m = read();
	while(m--){
		int L = read(),R = read();
		int l = lower_bound(p + 1,p + n + 1,make_pair(L,-inf)) - p;
		int r = lower_bound(p + 1,p + n + 1,make_pair(R,inf)) - p - 1;
		if(l > r)puts("0");
		else write(T.query(l,r)),putchar('\n');
	}

	return 0;
}
/*
T:think
E:enouge size
M:memory
P:precision
B:boundary
O:overflow
T:time
M:mod
F:file
*/