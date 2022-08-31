#include<bits/stdc++.h>
using namespace std;

int n,m;

vector<int> adj[1000005];
int col[1000005],match[1000005];
bitset<1000005> vis;

void dfs(int u,int c){
	col[u] = c;
	for(int v:adj[u]){
		if(col[v] == -1) dfs(v,1-c);
	}
}

int bip(int l){
	if(vis[l]) return 0;
	vis[l] = 1;
	for(int r:adj[l]){
		if(match[r] == -1 or bip(match[r])){
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

int main(){
	cin >> n >> m;
	if(n*m > 10000){
		cout << (n*m+1)/2 << endl;
		return 0;
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			
			// if(i+5 < n) adj[i*m+j].push_back((i+5)*m+j);
			// if(i-5 >= 0) adj[i*m+j].push_back((i-5)*m+j);
			// if(j+5 < m) adj[i*m+j].push_back(i*m+j+5);
			// if(j-5 >= 0) adj[i*m+j].push_back(i*m+j-5);

			if(i+2 < n and j+1 < m) adj[i*m+j].push_back((i+2)*m+j+1);
			if(i+2 < n and j-1 >= 0) adj[i*m+j].push_back((i+2)*m+j-1);
			if(i-2 >= 0 and j+1 < m) adj[i*m+j].push_back((i-2)*m+j+1);
			if(i-2 >= 0 and j-1 >= 0) adj[i*m+j].push_back((i-2)*m+j-1);

			if(i+1 < n and j+2 < m) adj[i*m+j].push_back((i+1)*m+j+2);
			if(i+1 < n and j-2 >= 0) adj[i*m+j].push_back((i+1)*m+j-2);
			if(i-1 >= 0 and j+2 < m) adj[i*m+j].push_back((i-1)*m+j+2);
			if(i-1 >= 0 and j-2 >= 0) adj[i*m+j].push_back((i-1)*m+j-2);
			col[i*m+j] = -1;
			match[i*m+j] = -1;
		}
	}
	for(int i = 0; i < n*m; i ++){
		// cout << i << " ------------ " << adj[i].size() << endl;
		// for(auto x:adj[i]) cout << x << " "; cout << "\n";
		if(col[i] == -1) dfs(i,0);
	}
	int ans = 0;
	for(int i = 0; i < n*m; i ++){
		if(col[i] == 0){
			vis.reset();
			ans += bip(i);
		}
	}
	cout << n*m-ans << endl;
}