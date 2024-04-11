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
const int N=500050;
vector<int> E[N];
set<int> ngb[N];
int col[N];
int main(){
	int n,m;
	rd(n,m);
	for(int i=1;i<=m;i++){
		int u,v;rd(u,v);
		E[u].pb(v);E[v].pb(u);
	}
	vector<int> ord(n);
	for(int i=1;i<=n;i++)scanf("%i",&col[i]),ord[i-1]=i;
	sort(ord.begin(),ord.end(),[&](int i,int j){return col[i]<col[j];});
	bool ok=true;
	for(int i=1;i<=n;i++){
		for(int j:E[i])if(col[j]<=col[i])ngb[i].insert(col[j]);
		if(ngb[i].size()==col[i]-1&&!ngb[i].count(col[i])){

		}else ok=false;
	}
	if(ok){
		for(int i:ord)printf("%i ",i);
		printf("\n");
	}else printf("-1\n");
	return 0;
}