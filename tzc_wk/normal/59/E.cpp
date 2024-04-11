#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int inf=INT_MAX;
const int MAXN=3e3+20;
const int MAXM=2e4+100;
int n,m,k;
map<pii,int> mp;
set<int> G[MAXM*2];
struct Edge{
	int from,to,nex;
	Edge(int a=0,int b=0,int c=0){
		from=a;to=b;nex=c;
	}
};
Edge edge[MAXM*2];
int head[MAXN], edgenum;
int dp[MAXM*2], pre[MAXM*2];
void add(int u, int v){
	Edge E=Edge(u,v,head[u]);
	edge[edgenum]=E;
	mp[pii(u, v)] = edgenum;
	dp[edgenum] = inf;
	head[u] = edgenum++;
}
void spfa(int x){
	queue<int>q;
	for (int i = head[x]; ~i; i = edge[i].nex){
		q.push(i);
		dp[i] = 0;
		pre[i] = -1;
	}
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int i = head[edge[u].to]; ~i; i = edge[i].nex){
			int v = edge[i].to;
			if (dp[i] > dp[u]+1 && G[u].count(v) == 0){
				q.push(i);
				dp[i] = dp[u] + 1;
				pre[i] = u;
			}
		}
	}
}
vector<int>ans;
int main() {
	cin>>n>>m>>k;
	memset(head, -1, sizeof head); edgenum = 0;
	mp.clear();
	while (m--){
		int u,v;
		cin>>u>>v;
		add(u, v); add(v, u);
	}
	for (int i=0,u,v,c;i<k;i++){
		cin>>u>>v>>c;
		if (mp.count(pii(u, v)))
			G[mp[pii(u,v)]].insert(c);
		swap(c, u);
		if (mp.count(pii(u,v)))
			G[mp[pii(u,v)]].insert(c);
	}
	spfa(1);
	int las = -1;
	for (int i=head[n];i!=-1;i=edge[i].nex){
		if (dp[i^1]!=inf && (las==-1||dp[las]>dp[i^1])){
			las=i^1;
		}
	}
	if (las==-1)	puts("-1");
	else{
		ans.push_back(n);
		while (las!=-1){
			ans.push_back(edge[las].from);
			las=pre[las];
		}
		cout<<ans.size()-1<<endl;
		for(int i=ans.size()-1;i>=0;i--)
			cout<<ans[i]<<" ";
	}
	return 0;
}