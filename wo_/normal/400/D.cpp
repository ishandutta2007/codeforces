#include<cstdio>
#include<algorithm>

using namespace std;

struct UnionFind{
	int par[100100];
	void init(int N){
		for(int i=0;i<N;i++){
			par[i]=i;
		}
	}
	int find(int x){
		if(x==par[x]) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		par[x]=y;
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
};

UnionFind uf;

int cs[550];
int type[100100];
int N;
int T;

int dis[550][550];

int us[100100],vs[100100],xs[100100];
int M;

void input(){
	scanf("%d%d%d",&N,&M,&T);
	for(int i=0;i<T;i++) scanf("%d",cs+i);
	for(int i=0;i<M;i++){
		scanf("%d%d%d",us+i,vs+i,xs+i);
		us[i]--;vs[i]--;
	}
}

void init(){
	int c=0;
	for(int i=0;i<T;i++){
		for(int j=0;j<cs[i];j++){
			type[c++]=i;
		}
	}
	uf.init(N);
}

bool isCorrect(){
	for(int i=0;i<M;i++){
		if(xs[i]==0){
			uf.unite(us[i],vs[i]);
		}
	}
	int c=0;
	for(int i=0;i<T;i++){
		for(int j=0;j<cs[i];j++){
			if(j+1==cs[i]){
				c++;
				continue;
			}
			int u=c,v=c+1;
			if(!uf.same(u,v)){
				return false;
			}
			c++;
		}
	}
	return true;
}

void getDis(){
	for(int i=0;i<T;i++){
		for(int j=0;j<T;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=1e9;
		}
	}
	for(int i=0;i<M;i++){
		int u=us[i],v=vs[i],x=xs[i];
		u=type[u],v=type[v];
		dis[u][v]=min(dis[u][v],x);
		dis[v][u]=min(dis[v][u],x);
	}
	for(int k=0;k<T;k++){
		for(int i=0;i<T;i++) for(int j=0;j<T;j++){
			dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
}

int main(){
	input();
	init();
	bool flg=isCorrect();
	if(!flg){
		printf("No\n");
		return 0;
	}
	getDis();
	printf("Yes\n");
	for(int i=0;i<T;i++){
		for(int j=0;j<T;j++){
			int x=dis[i][j];
			if(x==1e9) x=-1;
			printf("%d%c",x,j==T-1?'\n':' ');
		}
	}
	return 0;
}