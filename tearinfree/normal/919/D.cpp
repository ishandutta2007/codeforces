#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <cstring>

using namespace std;
typedef long long lli;

int n,m;
char str[300100];
vector<int> adj[300100];
int ind[300100],dist[300100][26];

int main() {
	scanf("%d%d",&n,&m);
	scanf("%s",str+1);
	for(int i=0;i<m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		ind[v]++;
	}

	queue<int> que;
	for(int i=1;i<=n;i++) if(!ind[i]) {
		que.push(i);
	}
	
	while(!que.empty()) {
		int cur=que.front();que.pop();
		dist[cur][str[cur]-'a']++;
		for(auto &to:adj[cur]) {
			for(int i=0;i<26;i++) {
				dist[to][i] = max(dist[to][i],dist[cur][i]);
			}
			if(--ind[to]==0) que.push(to);
		}
	}

	for(int i=1;i<=n;i++) if(ind[i]) {
		puts("-1");
		return 0;
	}

	int mx=0;
	for(int i=1;i<=n;i++) for(int j=0;j<26;j++) mx=max(mx,dist[i][j]);
	printf("%d\n",mx);

	return 0;
}