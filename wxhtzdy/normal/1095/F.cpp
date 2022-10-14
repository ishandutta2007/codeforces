#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=200050;
ll a[N];
int ord[N],par[N];
int Find(int u){return par[u]==u?u:par[u]=Find(par[u]);}
void Unite(int u,int v){par[Find(v)]=Find(u);}
int main(){
	int n,m;scanf("%i%i",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)ord[i]=i;
	sort(ord+1,ord+n+1,[&](int i,int j){return a[i]<a[j];});
	vector<pair<ll,pair<int,int>>> e;
	for(int i=1;i<=m;i++){
		int u,v;scanf("%i%i",&u,&v);
		ll w;scanf("%lld",&w);
		e.pb({w,{u,v}});
	}
	for(int i=2;i<=n;i++)e.pb({a[ord[1]]+a[ord[i]],{ord[1],ord[i]}});
	sort(e.begin(),e.end());
	for(int i=1;i<=n;i++)par[i]=i;
	ll ans=0;
	for(auto x:e){
		int u=x.second.first;
		int v=x.second.second;
		ll w=x.first;
		if(Find(u)!=Find(v)){
			ans+=w;
			Unite(u,v);
		}
	}
	printf("%lld",ans);
	return 0;
}