#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <iostream>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int _abs_int(int a) {
	return a<0 ? -a : a;
}
lli _abs_lli(lli a) {
	return a<0 ? -a : a;
}

const int inf=1e9;

int n,m,vis[300001],pr[300001],dist[300001],gn[300001];
vector<int> adj[300001];

void BFS(int s) {
	queue<int> que;
	que.push(s);
	vis[s] = 1;
	
	while(!que.empty()) {
		int cur=que.front();que.pop();
		for(auto &it:adj[cur]) if(!vis[it]) {
			vis[it]=1;
			dist[it]=dist[cur]+1;
			pr[it]=cur;
			que.push(it);
		}
	}
}
int tmp_vis[300001];
bool check(int s,int g) {
	queue<int> que;
	vector<int> node_list;
	que.push(s);
	gn[s] = g;
	while(!que.empty()) {
		int cur=que.front();que.pop();
		node_list.push_back(cur);
		for(auto &it:adj[cur]) if(!gn[it]) {
			gn[it]=g;
			que.push(it);
		}
	}
	for(auto &cur:node_list) {
		int cnt=0;
		for(auto &it:adj[cur]) {
			if(gn[cur] == gn[it]) cnt++;
		}
		if(cnt != (int)(node_list.size())-1) {
			vector<int> ans;
			fill(vis,vis+n+1,0);
			fill(pr,pr+n+1,0);
			queue<int> que;
			que.push(cur);
			vis[cur]=1;
			for(int k=0;k<2;k++) {
				int s=que.size();
				while(s--) {
					int cur=que.front();que.pop();
					for(auto &it:adj[cur]) if(gn[it]==gn[cur] && !vis[it]) {
						pr[it] = cur;
						vis[it] = 1;
						que.push(it);
					}
				}
			}
			
			int c=que.front();
			ans.push_back(cur);
			while(true) {
				ans.push_back(c);
				if(c==cur) break;
				c = pr[c];
			}
			ans.push_back(1);
			reverse(ans.begin(),ans.end());
			ans.push_back(n);
			printf("%d\n",(int)ans.size()-1);
			for(auto &it:ans) printf("%d ",it);
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	fill(vis,vis+n+1,0);
	fill(dist,dist+n+1,inf);
	fill(pr,pr+n+1,0);
	dist[1] = 0;
	BFS(1);

	int mx = inf;
	vector<int> ans;
	if(dist[n] < mx) {
		int c=n;
		while(true){
			ans.push_back(c);
			if(c==1) break;
			c = pr[c];
		}
		reverse(ans.begin(),ans.end());
		mx = dist[n];
	}
	
	for(int i=2;i<n;i++) if(vis[i] && dist[i]==2) {
		int f=1;
		for(auto &it:adj[i]) if(it==1) {
			f=0;
			break;
		}
		if(f) {
			if(mx > 4) {
				int c=i;
				ans.clear();
				while(true) {
					ans.push_back(c);
					if(c==1) break;
					c=pr[c];
				}
				reverse(ans.begin(),ans.end());
				ans.push_back(1);
				ans.push_back(n);
			}
			printf("%d\n",(int)ans.size()-1);
			for(auto &it:ans) printf("%d ",it);
			return 0;
		}
	}
	if(mx <= 5) {
		printf("%d\n",(int)ans.size()-1);
		for(auto &it:ans) printf("%d ",it);
		return 0;
	}

	int g=1;
	gn[1] = -1;
	for(int i=2;i<=n;i++) if(vis[i] && !gn[i]) {
		if(check(i, g++)) return 0;
	}
	
	puts("-1");
	
	return 0;
}