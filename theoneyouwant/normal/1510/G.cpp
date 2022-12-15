#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
vector<vector<int>>adj;
vector<int>ans;
int sz[105];
int len[105];
bool res[105];
int maxim;
int rem;

void dfs(int v, int p){
	sz[v]=1;
	len[v]=1;
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		dfs(u, v);
		sz[v]+=sz[u];
	}
	int maxi=0;
	int ind=-1;
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		if(len[u]>maxi){
			maxi=len[u];
			ind=u;
		}
	}
	len[v]+=maxi;
	
}
int mo;

void g(int u, int v){
	if(mo==0){
		return;
	}
	ans.pb(u);
	mo--;
	rem--;
	for(auto uu:adj[u]){
		if(uu==v || mo==0){
			continue;
		}
		g(uu, u);
	}
	ans.pb(v);
}

void f(int v, int p){
	if(rem==0){
		return;
	}
	if(maxim>=rem){
		
		int ind=-1;
		for(auto u:adj[v]){
			if(u==p){
				continue;
			}
			if(res[u]){
				ind=u;
			}
		}
		ans.pb(ind);
		maxim--;
		rem--;
		f(ind, v);
	}
	else{
		for(auto u:adj[v]){
			if(u==p || res[u]==1){
				continue;
			}
			if(rem-maxim>0){
				mo=rem-maxim;
				g(u, v);
				
			}
		}
		int ind=-1;
		for(auto u:adj[v]){
			if(u==p){
				continue;
			}
			if(res[u]){
				ind=u;
				break;
			}
		}
		if(rem!=0){
			ans.pb(ind);
			maxim--;
			rem--;
			
			f(ind, v);
		}
	}
}

void f2(int v, int p){
	int ind=-1;
	int maxi=-1;
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		if(len[u]>maxi){
			maxi=len[u];
			ind=u;
		}
	}
	if(ind!=-1){
		res[ind]=1;
		f2(ind, v);
	}
}
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ans.clear();
		int n, k;
		cin>>n>>k;
		for(int i=0; i<105; i++){
			res[i]=0;
		}
		res[1]=1;
		adj.clear();
		adj.resize(n+1);
		for(int i=2; i<=n; i++){
			int p;
			cin>>p;
			adj[p].pb(i);
			adj[i].pb(p);
		}
		if(k==1){
			cout<<0<<endl;
			cout<<1<<endl;
			continue;
		}
		dfs(1, 0);
		f2(1, 0);
		
		maxim=len[1]-1;
		rem=k-1;
		ans.pb(1);
		f(1, 0);
		cout<<ans.size()-1<<endl;
		for(auto u:ans){
			cout<<u<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}