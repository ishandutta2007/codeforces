#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define CL(a,x) memset(a, x, sizeof(a))
#define ar6 array<int, 6>
typedef long long LL;
const int P = 1e9+7;
const int N = 1e5+5, K = 4, M = 380;
const double PI = acos(-1);
mt19937 rng(time(0));

struct E{
	int to,w;
};
unordered_map<int,int> mp;
vector<E> g[N];
int n, m, x, y, w, tot;
int val[N], feat[N], cmb[M][M], f[M], f1[M];
char vis[N], conn[N];
ar6 a;

void insert(ar6 &a, int num){
	int ii = -1;
	rrep(i,K,0) if(num>>i&1){
		if(a[i]) num ^= a[i];
		else{
			rrep(j,i-1,0) if(num>>j&1) num ^= a[j];
			rep(j,i+1,K) if(a[j]>>i&1) a[j] ^= num;
			a[i] = num;
			return;
		}
	}
	a[K+1] = -1;
}

void dfs(int x, int fa, int num){
	val[x] = num, vis[x] = 1;
	for(auto ele:g[x]){
		int u = ele.to, w = ele.w;
		if(conn[u]) continue;
		if(!vis[u]) dfs(u, x, num^w);
		else if(u!=fa && vis[u]==2) insert(a, w^val[u]^val[x]);
	}
	vis[x] = 2;
}

int calc(ar6 a){
	if(a[K+1]==-1) return -1;
	int res = 0;
	rep(i,0,K) res = (res << i+1) + a[i];
	return res;
}

void precalc(){
	ar6 Q[M];
	Q[tot=1].fill(0);
	mp[0] = 1, mp[-1] = 0;
	rep(i,1,tot){
		ar6 x = Q[i], y;
		rep(j,1,31){
			y = x, insert(y, j);
			int key = calc(y);
			if(!mp.count(key)){
				++tot, mp[key] = tot, Q[tot] = y;
			}
		}
	}
	rep(i,1,tot) rep(j,1,i){
		ar6 x = Q[i], y = Q[j];
		rep(u,0,K) if(y[u]) insert(x, y[u]);
		cmb[i][j] = cmb[j][i] = mp[calc(x)];
	}
}

void add(int &x, int y){x+=y; if(x>=P)x-=P;}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	precalc();
	
	memset(conn,0,sizeof conn);
	conn[1] = true;
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d%d",&x,&y,&w);
		if(x>y) swap(x,y);
		g[x].PB({y,w});
		g[y].PB({x,w});
		if(x==1) conn[y] = true;
	}
	
	memset(vis,0,sizeof vis);
	for(auto ele:g[1]){
		int x = ele.to;
		a = {0,0,0,0,0,0};
		dfs(x, 1, ele.w);
		feat[x] = mp[calc(a)];
	}
	
	memset(vis,0,sizeof vis);
	f[1] = 1;
	for(auto ele:g[1]){
		int x = ele.to;
		if(vis[x]) continue;
		
		vis[x] = true;
		int cyc = 0, w = 0, h = feat[x];
		for(auto e2:g[x]){
			int y = e2.to;
			if(!conn[y] || vis[y] || y==1) continue;
			vis[y] = true, cyc = y, w = e2.w;
			break;
		}
		if(cyc) h = cmb[h][feat[cyc]];
		if(!h) continue;
		
		memcpy(f1,f,sizeof f1);
		rep(i,1,tot) add(f1[cmb[i][h]], f[i]);
		if(cyc){
			rep(i,1,tot) add(f1[cmb[i][h]], f[i]);
			ar6 tmp {};
			insert(tmp, val[x] ^ val[cyc] ^ w);
			h = cmb[h][mp[calc(tmp)]];
			if(h) rep(i,1,tot) add(f1[cmb[i][h]], f[i]);
		}
		swap(f, f1);
	}
	int ans = 0;
	rep(i,1,tot) add(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}