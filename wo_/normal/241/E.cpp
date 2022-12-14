#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

const int inf=5000;

int us[5050],vs[5050];

int N,M;

vector<int> G[1010];

bool ok_[2][1010];
bool ok[1010];

void bfs(int s,bool *res){
	queue<int> que;
	for(int i=0;i<N;i++){
		res[i]=false;
	}
	que.push(s);
	res[s]=true;
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(int i=0;i<G[v].size();i++){
			int u=G[v][i];
			if(res[u]) continue;
			res[u]=true;
			que.push(u);
		}
	}
}

int head[1010],to[10100],nxt[10100],cost[10100],m;

int dis[1010];

void init_edge(){
	for(int i=0;i<N;i++) head[i]=-1;
	m=0;
}

void add_edge(int u,int v,int c){
	to[m]=v;nxt[m]=head[u];cost[m]=c;head[u]=m;m++;
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d%d",us+i,vs+i);
		us[i]--;vs[i]--;
	}
	for(int i=0;i<M;i++){
		G[us[i]].push_back(vs[i]);
	}
	bfs(0,ok_[0]);
	for(int i=0;i<N;i++) G[i].clear();
	for(int i=0;i<M;i++){
		G[vs[i]].push_back(us[i]);
	}
	bfs(N-1,ok_[1]);
	for(int i=0;i<N;i++) ok[i]=ok_[0][i]&ok_[1][i];
	if(ok[N-1]==false){
		printf("No\n");
		return 0;
	}
	init_edge();
	for(int i=0;i<M;i++){
		int u=us[i],v=vs[i];
		if((!ok[u])||(!ok[v])) continue;
		add_edge(u,v,2);
		add_edge(v,u,-1);
	}
	for(int i=0;i<N;i++) dis[i]=inf;
	dis[0]=0;
	bool suc=true;
	for(int stage=0;stage<10100;stage++){
		bool update=false;
		if(stage>10000){
			suc=false;
			break;
		}
		for(int v=0;v<N;v++){
			if(dis[v]==inf) continue;
			for(int e=head[v];e!=-1;e=nxt[e]){
				int u=to[e];
				int c=cost[e];
				if(dis[u]>dis[v]+c){
					dis[u]=dis[v]+c;
					update=true;
				}
			}
		}
		if(update==false) break;
	}
	if(suc==false){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(int i=0;i<M;i++){
		int u=us[i],v=vs[i];
		if((!ok[u])||(!ok[v])){
			printf("1\n");
		}else{
			printf("%d\n",dis[v]-dis[u]);
		}
	}
	return 0;
}