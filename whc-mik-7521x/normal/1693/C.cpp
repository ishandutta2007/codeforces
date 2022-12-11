#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,deg[N],dis[N];
priority_queue<pair<int,int>>pq;
struct edge{
    int to,nxt;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
bool vis[N];
int main(){
    scanf("%d%d",&n,&m);
	memset(dis,63,sizeof dis);
	while(m--){
		int x,y;
        scanf("%d%d",&y,&x);
        add(x,y);
		++deg[y];
	}
	dis[n]=0;
	pq.push({0,n});
	while(!pq.empty()){
		int x=pq.top().second;
		pq.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=h[x];i;i=ed[i].nxt){
            int v=ed[i].to;
			if(dis[x]+deg[v]<dis[v]){
				dis[v]=dis[x]+deg[v];
				pq.push({-dis[v],v});
			}
			deg[v]--;
		}
	}
    printf("%d",dis[1]);
	return 0;
}