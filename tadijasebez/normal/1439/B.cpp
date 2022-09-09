#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>

void Solve(){
	int n,m,k;
	scanf("%i %i %i",&n,&m,&k);
	vector<vector<int>> E(n,vector<int>());
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%i %i",&u,&v);
		u--;v--;
		E[u].pb(v);
		E[v].pb(u);
	}
	vector<int> deg(n,0);
	for(int i=0;i<n;i++)deg[i]=E[i].size();
	set<pii> all;
	for(int i=0;i<n;i++)all.insert({deg[i],i});
	vector<bool> was(n,false);
	vector<vector<int>> cand,mycl(n,vector<int>());
	vector<int> cnt;
	while(all.size()&&all.begin()->first<k){
		int u=all.begin()->second;
		all.erase(all.begin());
		was[u]=true;
		if(deg[u]==k-1){
			vector<int> clique={u};
			mycl[u].pb(cand.size());
			for(int v:E[u])if(!was[v]){
				clique.pb(v);
				mycl[v].pb(cand.size());
			}
			cand.pb(clique);
			cnt.pb(0);
		}
		for(int v:E[u])if(!was[v]){
			all.erase({deg[v],v});
			deg[v]--;
			all.insert({deg[v],v});
		}
	}
	if(all.size()){
		printf("1 %i\n",all.size());
		for(auto it:all)printf("%i ",it.second+1);
		printf("\n");
	}else{
		vector<bool> has(n,false);
		for(int u=0;u<n;u++){
			for(int v:E[u])has[v]=true;
			for(int clique:mycl[u]){
				for(int v:cand[clique]){
					cnt[clique]+=has[v];
				}
			}
			for(int v:E[u])has[v]=false;
		}
		for(int i=0;i<cand.size();i++){
			//printf("%i: ",cnt[i]);for(int j:cand[i])printf("%i ",j);printf("\n");
			if(cnt[i]==k*(k-1)){
				printf("2\n");
				for(int v:cand[i]){
					printf("%i ",v+1);
				}
				printf("\n");
				return;
			}
		}
		printf("-1\n");
	}
}
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		Solve();
	}
	return 0;
}