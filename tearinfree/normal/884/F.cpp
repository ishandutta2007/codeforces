#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;

struct graph{
	struct edge{
		int t,f,c,rev;
		edge() {}
		edge(int t,int f,int c)
		:t(t),f(f),c(c) {}
	};
	
	vector<vector<edge>> adj;
	vector<int> dist,pa;
	int n;

	graph() {}
	void init(int n) {
		this->n=n;
		adj.resize(n);
		dist.resize(n);
		pa.resize(n);
	}
	void add_edge(int u,int v,int f,int c) {
		adj[u].push_back(edge(v,f,c));
		adj[v].push_back(edge(u,0,-c));
		adj[u].back().rev=adj[v].size()-1;
		adj[v].back().rev=adj[u].size()-1;
	}
	int mcmf(int src,int sik) {
		int tf=0,tc=0;
		while(true) {
			fill(dist.begin(),dist.end(),inf);
			fill(pa.begin(),pa.end(),-1);
			
			vector<int> vis(n,0);
			
			queue<int> que;
			que.push(src);
			dist[src]=0; pa[src]=src; vis[src]=1;
			while(!que.empty()) {
				int cur=que.front(); que.pop();
				vis[cur]=0;
				for(int i=0;i<adj[cur].size();i++) {
					if(adj[cur][i].f>0 && dist[adj[cur][i].t]>dist[cur]+adj[cur][i].c) {
						dist[adj[cur][i].t]=dist[cur]+adj[cur][i].c;
						pa[adj[cur][i].t]=adj[cur][i].rev;
						if(!vis[adj[cur][i].t]) {
							vis[adj[cur][i].t]=1;
							que.push(adj[cur][i].t);
						}
					}
				}
			}

			if(dist[sik]>=inf) break;
			
			int cur=sik;
			while(cur!=src) {
				int tar=adj[cur][pa[cur]].t,idx=adj[cur][pa[cur]].rev;
				adj[tar][idx].f-=1; adj[cur][pa[cur]].f+=1;
				tc+=adj[tar][idx].c;
				cur=tar;
			}
			tf++;
		}
		return tc;
	}
}g;

int n,arr[100];
char str[101],cnt[26];

int main() {
	scanf("%d",&n);
	scanf("%s",str);
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	for(int i=0;i<n;i++) cnt[str[i]-'a']++;
	
	int sz=n/2+28;
	int src=sz-2, sik=sz-1;
	g.init(sz);

	for(int i=0;i<26;i++) {
		g.add_edge(src,i,cnt[i],0);
		for(int j=0;j<n/2;j++) {
			int mx=0;
			if(str[j]==i+'a') mx=max(mx,arr[j]);
			if(str[n-j-1]==i+'a') mx=max(mx,arr[n-j-1]);
			g.add_edge(i,26+j,1,-mx);
		}
	}
	for(int i=0;i<n/2;i++) g.add_edge(26+i,sik,2,0);
	printf("%d\n",-g.mcmf(src,sik));

	return 0;
}