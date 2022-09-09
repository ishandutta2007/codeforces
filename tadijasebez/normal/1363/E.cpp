#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}
const int N=200050;
int a[N],b[N],c[N];
vector<int> E[N];
ll ans;
pair<int,int> DFS(int u,int p){
	if(p)a[u]=min(a[u],a[p]);
	pair<int,int> tmp={0,0};
	if(b[u]!=c[u]){
		if(c[u]==1)tmp.second++;
		else tmp.first++;
	}
	for(int v:E[u])if(v!=p){
		auto now=DFS(v,u);
		tmp.first+=now.first;
		tmp.second+=now.second;
	}
	int mx=min(tmp.first,tmp.second);
	ans+=(ll)a[u]*mx*2;
	tmp.first-=mx;
	tmp.second-=mx;
	return tmp;
}
int main(){
	int n=ri();
	for(int i=1;i<=n;i++)rd(a[i],b[i],c[i]);
	for(int i=1,u,v;i<n;i++)rd(u,v),E[u].pb(v),E[v].pb(u);
	auto tmp=DFS(1,0);
	if(tmp.first+tmp.second==0)printf("%lld\n",ans);
	else printf("-1\n");
	return 0;
}