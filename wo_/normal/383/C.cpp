#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct segtree{
	int N;
	int dat[524288][2];
	void init(int N_){
		N=1;
		while(N<N_) N*=2;
		for(int i=0;i<N*2;i++) dat[i][0]=0,dat[i][1]=0;
	}
	void add(int l,int r,int k,int a,int b,int x,int p){
		if(l<=a&&b<=r){
			dat[k][p]+=x;
			dat[k][p^1]-=x;
			return;
		}
		else if(r<=a||b<=l) return;
		add(l,r,k*2,a,(a+b)/2,x,p);
		add(l,r,k*2+1,(a+b)/2,b,x,p);
	}
	void add(int l,int r,int x,int p){
		add(l,r,1,0,N,x,p);
	}
	int get(int id,int p){
		int res=0;
		id+=N;
		while(id>0){
			res+=dat[id][p];
			id/=2;
		}
		return res;
	}
};

segtree seg;

vector<int> G[200200];
int dep[200200];
int pre[200200],pos[200200];

void add(int v,int x){
	seg.add(pre[v],pos[v],x,dep[v]%2);
}

int get(int v){
	return seg.get(pre[v],dep[v]%2);
}

int c=0,d=0;
void dfs(int v,int p){
	dep[v]=d;
	d++;
	pre[v]=c;
	c++;
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		if(u==p) continue;
		dfs(u,v);
	}
	d--;
	pos[v]=c;
}

int N,M;
int a[200200];

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	for(int i=0;i<N-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0,-1);
	seg.init(N);
	for(int i=0;i<M;i++){
		int type;
		scanf("%d",&type);
		if(type==1){
			int x,val;
			scanf("%d%d",&x,&val);
			x--;
			add(x,val);
		}else{
			int v;
			scanf("%d",&v);
			v--;
			printf("%d\n",get(v)+a[v]);
		}
	}
	return 0;
}