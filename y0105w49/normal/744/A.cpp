#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const int inf=1e9+99;
const ld eps=1e-10;

const int N=1024;
ll vsz[N],esz[N];
int rk[N],da[N];
int n,m,k;
int c[N];
int a[N],b[N];
bool ex_edge[N][N];
int ngov[N];
int rt(int u) {
	if(u==da[u]) return u;
	return da[u]=rt(da[u]);
}
int un(int u,int v) {
	u=rt(u),v=rt(v);
	if(u==v) return 0;
	if(rk[u]>rk[v]) swap(u,v);
	if(rk[u]==rk[v]) ++rk[v];
	vsz[v]+=vsz[u];
	esz[v]+=esz[u];
	da[u]=v;
	return 1;
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++) scanf("%d",c+i), --c[i];
	for(int i=0;i<n;i++) da[i]=i, vsz[i]=1;
	for(int i=0;i<m;i++) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		un(a,b);
		++esz[rt(a)];
		ex_edge[a][b]=ex_edge[b][a]=1;
	}
	for(int i=0;i<k;i++) ngov[rt(c[i])]++;
	for(int i=0;i<n;i++) assert(ngov[i]==0||ngov[i]==1);
	ll ans=0;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
		if(i==j) continue;
		if(ex_edge[i][j]) continue;
		if(rt(i)!=rt(j)) continue;
		ex_edge[i][j]=ex_edge[j][i]=1;
		++ans;
	}
	vector<ll> free_sz;
	vector<ll> used_sz;
	for(int i=0;i<n;i++) {
		if(i!=rt(i)) continue;
		if(ngov[i]) used_sz.pb(vsz[i]);
		else free_sz.pb(vsz[i]);
	}
	sort(used_sz.begin(),used_sz.end());
	assert(used_sz.size());
	free_sz.pb(used_sz.back());
	sort(free_sz.begin(),free_sz.end());

	ll tom=0;
	for(ll x:free_sz) {
		ans+=tom*x;
		tom+=x;
	}
	cout<<ans<<endl;
}