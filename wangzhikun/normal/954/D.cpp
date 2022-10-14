#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n,m,s,t,u,v,cur,ct,ans = 0;

vector<int> way[1010];
int dist1[1010] = {0},dist2[1010] = {0},conn[1010][1010] = {0};
queue<int> que;
int main() {
	cin>>n>>m>>s>>t;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		way[u].push_back(v);
		way[v].push_back(u);
		conn[u][v] = 1;
		conn[v][u] = 1;
	}
	que.push(s);
	while(!que.empty()){
		cur = que.front();
		que.pop();
		for(int i=0;i<way[cur].size();i++){
			ct = way[cur][i];
			if(!dist1[ct]&&ct!=s){
				dist1[ct] = dist1[cur]+1;
				que.push(ct);
			}
		}
	}
	que.push(t);
	while(!que.empty()){
		cur = que.front();
		que.pop();
		for(int i=0;i<way[cur].size();i++){
			ct = way[cur][i];
			if(!dist2[ct]&&ct!=t){
				dist2[ct] = dist2[cur]+1;
				que.push(ct);
			}
		}
	}
	for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++){
		if(conn[i][j])continue;
		if(dist1[i]+dist2[j]+1>=dist1[t] && dist2[i]+dist1[j]+1>=dist1[t])ans++;
	}
	cout<<ans<<endl;
	return 0;
}