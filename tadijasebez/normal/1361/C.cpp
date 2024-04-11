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
const int N=(1<<20)+50;
vector<int> cyc;
vector<pair<int,int>> E[N];
bool was[N];
int ptr[N],deg[N];
void DFS(int u){
	int cnt=0;
	while(1){
		while(ptr[u]<E[u].size() && was[E[u][ptr[u]].second]) ptr[u]++;
		if(ptr[u]==E[u].size()){ cyc.pb(u);return;}
		else{
			was[E[u][ptr[u]].second]=1;
			DFS(E[u][ptr[u]++].first);
			//cyc.pb(u);
		}
		cnt++;
	}
}
void RCH(int u){
	was[u]=1;
	for(auto e:E[u])if(!was[e.first])RCH(e.first);
}
int u[N],v[N],a[N],b[N];
int main(){
	int n=ri();
	for(int i=1;i<=n;i++){
		rd(u[i],v[i]);
	}
	for(int bit=20;bit>=0;bit--){
		for(int i=0;i<(1<<bit);i++)E[i].clear(),was[i]=0,ptr[i]=0,deg[i]=0;
		for(int i=1;i<=n;i++){
			a[i]=u[i]&((1<<bit)-1);
			b[i]=v[i]&((1<<bit)-1);
			E[a[i]].pb({b[i],i});deg[a[i]]++;
			E[b[i]].pb({a[i],i});deg[b[i]]++;
		}
		int com=0;
		bool ok=1;
		for(int i=0;i<(1<<bit);i++)if(deg[i]>0){
			if(deg[i]&1)ok=false;
			if(!was[i]){
				RCH(i);
				com++;
			}
		}
		if(com>1)ok=0;
		if(ok){
			printf("%i\n",bit);
			for(int i=0;i<=n;i++)was[i]=0;
			for(int i=0;i<(1<<bit);i++){
				if(deg[i]>0){
					cyc.clear();
					DFS(i);
					break;
				}
			}
			map<pair<int,int>,set<int>> ids;
			for(int i=1;i<=n;i++){
				ids[{a[i],b[i]}].insert(i);
				ids[{b[i],a[i]}].insert(i);
				//printf("%i %i\n",a[i],b[i]);
			}
			cyc.pop_back();
			for(int i=0,j=cyc.back();i<cyc.size();j=cyc[i],i++){
				int idx=*ids[{j,cyc[i]}].begin();
				ids[{j,cyc[i]}].erase(idx);
				ids[{cyc[i],j}].erase(idx);
				if(a[idx]==j)printf("%i %i ",idx*2-1,idx*2);
				else printf("%i %i ",idx*2,idx*2-1);
			}
			printf("\n");
			//for(int i:cyc)printf("%i ",i);printf("\n");
			break;
		}
	}
	return 0;
}