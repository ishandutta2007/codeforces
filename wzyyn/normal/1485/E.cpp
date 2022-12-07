#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;


const int N=200005;
int n,mx,c[N];
int fa[N],d[N];
vector<int> e[N],v[N];
ll f[N];
void dfs(int x){
	mx=max(mx,d[x]);
	for (auto i:e[x]){
		d[i]=d[x]+1;
		dfs(i);
	}
}
void solve(){
	mx=0;
	scanf("%d",&n);
	For(i,1,n) e[i].resize(0);
	For(i,1,n) v[i].resize(0);
	For(i,2,n) scanf("%d",&fa[i]),e[fa[i]].PB(i);
	For(i,2,n) scanf("%d",&c[i]);
	dfs(1);
	For(i,2,n) v[d[i]].PB(i);
	memset(f,233,sizeof(f));
	for (auto i:v[1]) f[i]=0;
	For(i,1,mx-1){
		ll v1,v2;
		v1=-(1ll<<60),v2=-(1ll<<60);
		for (auto j:v[i]){
			v1=max(v1,f[j]-c[j]);
			v2=max(v2,f[j]+c[j]);
		}
		for (auto j:v[i+1])
			f[j]=max(v1+c[fa[j]],v2-c[fa[j]]);
		int mn=1<<30,mx=-(1<<30);
		for (auto j:v[i])
			mn=min(mn,c[j]),mx=max(mx,c[j]);
		for (auto j:v[i]){
			ll val=f[j]+max(c[j]-mn,mx-c[j]);
			for (auto k:e[j]) f[k]=max(f[k],val);
		}
	}
	int mn=1<<30,mx=-(1<<30);
	for (auto j:v[::mx])
		mn=min(mn,c[j]),mx=max(mx,c[j]);
	ll res=-(1ll<<60);
	for (auto j:v[::mx])
		res=max(res,f[j]+max(c[j]-mn,mx-c[j]));
	cout<<res<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}