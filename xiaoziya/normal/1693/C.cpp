#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,ans;
int vis[maxn],oud[maxn];
vector<int>w[maxn];
long long dis[maxn];
priority_queue< pair<long long,int> >q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)
		scanf("%d%d",&x,&y),w[y].push_back(x),oud[x]++;
	for(int i=1;i<=n;i++)
		dis[i]=1e18;
	dis[n]=0,q.push(make_pair(0,n));
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x])
			continue;
		vis[x]=1;
		for(int i=0;i<w[x].size();i++){
			int y=w[x][i];
			oud[y]--;
			if(dis[y]>dis[x]+oud[y]+1)
				dis[y]=dis[x]+oud[y]+1,q.push(make_pair(-dis[y],y));
		}
	}
	printf("%lld\n",dis[1]);
	return 0;
}