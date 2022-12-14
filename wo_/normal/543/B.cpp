#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int inf=1e8;

vector<int> G[3030];
int N;

int dis[3030][3030];

void bfs(int s){
	int *res=dis[s];
	for(int i=0;i<N;i++) res[i]=inf;
	res[s]=0;
	queue<int> que;
	que.push(s);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(int i=0;i<G[v].size();i++){
			int nv=G[v][i];
			int nd=res[v]+1;
			if(res[nv]<=nd) continue;
			res[nv]=nd;
			que.push(nv);
		}
	}
}

int l1,l2;

int solve(int s1,int t1,int s2,int t2){
	int ans=dis[s1][t1]+dis[s2][t2];
	for(int u=0;u<N;u++) for(int v=0;v<N;v++){
		if(u==v) continue;
		int cur=dis[s1][u]+dis[u][v]+dis[v][t1]+dis[s2][u]+dis[v][t2];
		if(dis[s1][u]+dis[u][v]+dis[v][t1]>l1) continue;
		if(dis[s2][u]+dis[u][v]+dis[v][t2]>l2) continue;
		ans=min(ans,cur);
	}
	return ans;
}


int main(){
	int s1,t1,s2,t2;
	int M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	scanf("%d%d%d",&s1,&t1,&l1);
	scanf("%d%d%d",&s2,&t2,&l2);
	s1--;t1--;
	s2--;t2--;
	for(int i=0;i<N;i++) bfs(i);
	if(dis[s1][t1]>l1||dis[s2][t2]>l2){
		printf("-1\n");
		return 0;
	}
	int ans=dis[s1][t1]+dis[s2][t2];
	ans=min(ans,solve(s1,t1,s2,t2));
	ans=min(ans,solve(s1,t1,t2,s2));
	printf("%d\n",M-ans);
	return 0;
}