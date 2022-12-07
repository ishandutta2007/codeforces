#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define rep(i,l,r) for(rg int i = (l);i <= (r);i++)
#define dwn(i,r,l) for(rg int i = (r);i >= (l);i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define glc(u) (u << 1)
#define grc(u) ((u << 1) | 1)

const int N = 3e5;

typedef pair<int,int> pii;

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

In void chkmax(int &x,int y){if(y > x)x = y;}
In void chkmin(int &x,int y){if(y < x)x = y;}

struct seg{
	ll sum[4*N+5],flag[4*N+5];
	
	void pushdown(ll u,ll l,ll r){
		if(!flag[u])return;
		ll m = (l + r) >> 1;
		ll lc = glc(u),rc = grc(u);
		sum[lc] += (m - l + 1) * flag[u];
		sum[rc] += (r - m) * flag[u];
		flag[lc] += flag[u];
		flag[rc] += flag[u];
		flag[u] = 0;
	}
	
	void pushup(ll u){
		sum[u] = sum[glc(u)] + sum[grc(u)];
	}
	
	void build(ll u,ll l,ll r){
		flag[u] = sum[u] = 0;
		if(l == r)return;
		ll m = (l + r) >> 1;
		build(glc(u),l,m);
		build(grc(u),m+1,r);
	}
	
	void ud(ll u,ll l,ll r,ll ql,ll qr,ll dx){
		if(l == ql && r == qr){
			flag[u] += dx;
			sum[u] += (r - l + 1) * dx;
			return;
		}
		ll m = (l + r) >> 1;
		pushdown(u,l,r);
		if(qr <= m)ud(glc(u),l,m,ql,qr,dx);
		else if(ql > m)ud(grc(u),m+1,r,ql,qr,dx);
		else ud(glc(u),l,m,ql,m,dx),ud(grc(u),m+1,r,m+1,qr,dx);
		pushup(u);
	}
	
	ll query(ll u,ll l,ll r,ll ql,ll qr){
		if(ql == l && qr == r)return sum[u];
		pushdown(u,l,r);
		ll m = (l + r) >> 1;
		if(qr <= m)return query(glc(u),l,m,ql,qr);
		else if(ql > m)return query(grc(u),m+1,r,ql,qr);
		else return query(glc(u),l,m,ql,m) + query(grc(u),m+1,r,m+1,qr);
	}
}T;

int n,dn,ans,curans,sz[N+5],dfn[N+5];
vector<int> e1[N+5],e2[N+5];

void dfs1(int u){
//cout<<"u="<<u<<" curans="<<curans<<endl;
	vector<pair<pii,ll> > vc;vc.resize(0);
	ll id = T.query(1,1,n,dfn[u],dfn[u]),preans = curans;
//cout<<"id="<<id<<endl;
	if(id){
		T.ud(1,1,n,dfn[id],dfn[id] + sz[id] - 1,-id);
		T.ud(1,1,n,dfn[u],dfn[u] + sz[u] - 1,u);
		vc.pb(mp(mp(dfn[id],dfn[id]+sz[id]-1),-id));
		vc.pb(mp(mp(dfn[u],dfn[u]+sz[u]-1),u));
	}
	else{
		if(!T.query(1,1,n,dfn[u],dfn[u]+sz[u]-1)){
			T.ud(1,1,n,dfn[u],dfn[u] + sz[u] - 1,u);
			vc.pb(mp(mp(dfn[u],dfn[u]+sz[u]-1),u));
			curans++;
		}
	}
	chkmax(ans,curans);
	for(auto v : e1[u])dfs1(v);
	while(vc.size()){
		pair<pii,ll> p = vc.back();
		T.ud(1,1,n,p.fi.fi,p.fi.se,-p.se);
		vc.pop_back();
	}
	curans = preans;
//cout<<"u="<<u<<" curans="<<curans<<endl;
}
void dfs2(int u){
	sz[u] = 1;
	dfn[u] = ++dn;
	for(auto v : e2[u]){
		dfs2(v);
		sz[u] += sz[v];
	}
}
void solve(){
	n = read();
	T.build(1,1,n);
	rep(i,1,n)e1[i].resize(0),e2[i].resize(0);
	rep(u,2,n)e1[read()].pb(u);
	rep(u,2,n)e2[read()].pb(u);
	dn = 0;dfs2(1);
//rep(u,1,n)cout<<"u="<<u<<" sz="<<sz[u]<<" dfn="<<dfn[u]<<endl;
	ans = curans = 0;dfs1(1);
	write(ans),putchar('\n');
}

int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
// CLEAR
	int Tc = read();
	while(Tc--)solve();
	return 0;
}
// T: Think
// E: Enough array size
// M: Memory limit
// P: Precision
// B: Boundary
// O: Overflow
// T: Time limit
// M: Mod
// F: File