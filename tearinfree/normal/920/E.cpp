#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n,m,vis[200001];
vector<int> arr[200001],adj[200001],res;

void make(int s) {
	vector<int> a;
	fill(vis,vis+n+1,2);
	for(auto &v:arr[s]) vis[v]=0,a.push_back(v);

	sort(a.begin(),a.end());
	for(auto u:a) {
		sort(arr[u].begin(),arr[u].end());
		
		int j=0;
		for(auto v:a) {
			if(u==v) continue;
			while(j<arr[u].size() && v>arr[u][j]) j++;
			if(j==arr[u].size() || arr[u][j]!=v) adj[u].push_back(v);
		}
	}
}
int bfs(int s,int base) {
	queue<int> que;
	que.push(s);
	vis[s]=1;

	int sz=0,f=1;
	while(!que.empty()) {
		int cur=que.front();que.pop();
		sz++;
		for(auto to:adj[cur]) if(!vis[to]) {
			vis[to]=1;
			que.push(to);
		}
		int cnt=0;
		for(auto to:arr[cur]) if(vis[to]==2) cnt++;
		if(cnt!=base) f=-1;
	}
	return f*sz;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	if(n==1) {
		printf("1\n1\n");
		return 0;
	}

	int mx=n+1,id=0;
	for(int i=1;i<=n;i++) if(arr[i].size()<mx) {
		mx=arr[i].size(); id=i;
	}

	int b=n-mx;
	make(id);
	res.push_back(n-mx);
	for(int i=1;i<=n;i++) if(!vis[i]) {
		int s=bfs(i,b);
		if(s<0) res[0]-=s;
		else res.push_back(s);
	}

	sort(res.begin(),res.end());
	printf("%d\n",(int)res.size());
	for(auto val:res)printf("%d ",val);

	return 0;
}