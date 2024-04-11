#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> loop;
vector<int> G[3030];
int N;
int root[3030];
int dep[3030],par[3030];
int rloop[3030];
int nloop;
int loop_adj[3030][2];

int par_lca[3030][15];

bool used[3030];
int special;

bool flg;
bool in;

void dfs(int v,int p){
//	printf("%d %d\n",v,p);
	if(used[v]==true){
//		printf("true\n");
		flg=true;
		in=true;
		special=v;
		return;
	}
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		if(u==p) continue;
		dfs(u,v);
		if(flg){
			if(in){
//				printf("a\n");
				loop.push_back(v);
				if(special==v){
					in=false;
//					printf("c\n");
				}
				return;
			}else{
//				printf("b\n");
				return;
			}
		/*	if(special==v){
				printf("c\n");
				in=false;
			}*/
		}
	}
}

void tdfs(int v,int p,int d,int r){
	root[v]=r;
	dep[v]=d;
	par[v]=p;
//	printf("call %d %d %d %d\n",v,p,d,r);
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		if(v==r){
			int id=rloop[v];
			if(u==loop_adj[id][0]||u==loop_adj[id][1]){
				continue;
			}
		}
		if(u==p) continue;
//		printf("call u=%d\n",u);
		tdfs(u,v,d+1,r);
	}
}

void loopSet(){
	nloop=loop.size();
	for(int i=0;i<N;i++) rloop[i]=-1;
	for(int i=0;i<nloop;i++){
		rloop[loop[i]]=i;
	}
	for(int i=0;i<nloop;i++){
		loop_adj[i][0]=loop[(i+1)%nloop];
		loop_adj[i][1]=loop[(i-1+nloop)%nloop];
	}
}

int getLoopDis(int u,int v){
	int a=rloop[u],b=rloop[v];
	if(a==-1||b==-1) return -1;
	int d=max(b-a,a-b);
	d=min(d,nloop);
	return d;
}

void lcaInit(){
	for(int i=0;i<N;i++) par_lca[i][0]=par[i];
	for(int d=1;d<15;d++){
		for(int i=0;i<N;i++){
			if(par_lca[i][d-1]==-1) par_lca[i][d]=-1;
			else par_lca[i][d]=par_lca[par_lca[i][d-1]][d-1];
		}
	}
}

int getLca(int u,int v){
	if(dep[u]>dep[v]) swap(u,v);
	while(dep[v]>dep[u]) v=par_lca[v][0];
	if(u==v) return v;
	for(int i=14;i>=0;i--){
		if(par_lca[u][i]==par_lca[v][i]){}else{
			u=par_lca[u][i];
			v=par_lca[v][i];
		}
	}
	return par_lca[u][0];
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0,-1);
	/*for(int i=0;i<loop.size();i++){
		printf("%d ",loop[i]);
	}
	printf("\n");*///loop kenshutu ok
	
	loopSet();
	for(int i=0;i<nloop;i++){
		tdfs(loop[i],-1,0,loop[i]);
	}
	/*for(int i=0;i<N;i++){
		printf("%d %d %d %d\n",i,root[i],dep[i],par[i]);
	}*///tree dfs ok
	
	//printf("\n");
	double ans=0;
	lcaInit();
	for(int u=0;u<N;u++) for(int v=0;v<N;v++){
		if(u==v) ans+=1;
		else if(root[u]==root[v]){
			int lca=getLca(u,v);
			int d=dep[u]+dep[v]-2*dep[lca];
			int x=d-1;
			ans+=(1.0/(x+2));
	//		printf("%d %d %d\n",u,v,x);
		}else{
			int x=dep[u]+dep[v];
			int r1=root[u],r2=root[v];
			int y=getLoopDis(r1,r2);
			y--;
			int z=nloop-y-2;
			ans+=((1.0/(x+y+2))+(1.0/(x+z+2))-(1.0/(x+y+z+2)));
	//		printf("%d %d %d %d %d\n",u,v,x,y,z);
		}
	}
	printf("%.9f\n",ans);
	return 0;
}