#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m,arr[100000],ind[100000],res[100000];
vector<int> adj[100000];

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	for(int i=0;i<m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		adj[v].push_back(u);
		ind[u]++;
	}
	
	queue<int> que;
	for(int i=0;i<n;i++) if(ind[i]==0) {
		que.push(i);
		res[i]=arr[i];
	}
	while(!que.empty()) {
		int cur=que.front();que.pop();
		for(auto &it:adj[cur]) {
			int cost=res[cur];
			if(arr[cur]==0 && arr[it]==1) cost++;
			res[it]=max(res[it],cost);
			
			ind[it]--;
			if(ind[it]==0) que.push(it);
		}
	}
	
	int mx=0;
	for(int i=0;i<n;i++) mx=max(mx,res[i]);
	printf("%d\n",mx);
	return 0;
}