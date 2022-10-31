#include <bits/stdc++.h>

const int INF=1e9+6;
typedef std::pair<int,int> ip;
struct Edge {
	int u,v,c,id;
	Edge() {}
	Edge(int u,int v,int c,int id):u(u),v(v),c(c),id(id){}
	Edge(int v,int c,int id):u(0),v(v),c(c),id(id){}
	bool operator<(const Edge &rhs)const {
		return c<rhs.c;
	}
};

int n,m;
Edge eg[200001];
std::vector<Edge> adj[200001];
int ep[19][200001],ew[19][200001],er[19][200001];
int pa[200001],use[200001],de[200001],res[200001];

int fi(int no) {
	if(no==pa[no]) return no;
	else return pa[no]=fi(pa[no]);
}
void DFS(int no,int p,int w,int d){
	int a=1,pp=p;
	ep[0][no]=p;
	ew[0][no]=w;
	de[no]=d;
	while(ep[a-1][pp]!=0) {
		ep[a][no]=ep[a-1][pp];
		ew[a][no]=std::max(ew[a-1][no],ew[a-1][pp]);
		pp=ep[a-1][pp];
		a++;
	}
	
	for(auto &it:adj[no]) if(it.v!=p) DFS(it.v,no,it.c,d+1);
}
int fia(int u,int v,int c){
	if(de[u]<de[v]) std::swap(u,v);
	int mv=0,dif=de[u]-de[v];
	for(int i=0;(1<<i)<=dif;i++) {
		if((1<<i)&dif) {
			mv=std::max(mv,ew[i][u]);
			er[i][u]=std::min(er[i][u],c);
			u=ep[i][u];
		}
	}
	if(u==v)return mv;
	for(int i=18;i>=0;i--) {
		if(ep[i][u]!=0&&ep[i][v]!=0&&ep[i][u]!=ep[i][v]) {
			mv=std::max(mv,std::max(ew[i][u],ew[i][v]));
			er[i][u]=std::min(er[i][u],c);
			er[i][v]=std::min(er[i][v],c);
			u=ep[i][u]; v=ep[i][v];
		}
	}
	mv=std::max(mv,std::max(ew[0][u],ew[0][v]));
	er[0][u]=std::min(er[0][u],c);
	er[0][v]=std::min(er[0][v],c);
	return mv;
}
void rem(int no,int p) {
	for(auto &it:adj[no]) {
		if(it.v==p) res[it.id]=(er[0][no]==INF)?-1:er[0][no]-1;
		else rem(it.v,no);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) scanf("%d%d%d",&eg[i].u,&eg[i].v,&eg[i].c),eg[i].id=i;
	
	std::sort(eg,eg+m);
	for(int i=1;i<=n;i++) pa[i]=i;
	for(int i=0;i<m;i++) {
		int pu=fi(eg[i].u),pv=fi(eg[i].v);
		if(pu!=pv) {
			pa[pu]=pv;
			adj[eg[i].u].push_back(Edge(eg[i].v,eg[i].c,eg[i].id));
			adj[eg[i].v].push_back(Edge(eg[i].u,eg[i].c,eg[i].id));
			use[eg[i].id]=1;
		}
	}
	for(int i=0;i<19;i++) for(int j=0;j<=n;j++) er[i][j]=INF;
	DFS(1,0,0,0);
	
	for(int i=0;i<m;i++) if(!use[eg[i].id]){
		res[eg[i].id]=fia(eg[i].u,eg[i].v,eg[i].c)-1; 
	}
	for(int i=17;i>=0;i--) {
		for(int j=1;j<=n;j++) {
			er[i][j]=std::min(er[i][j],er[i+1][j]);
			er[i][ep[i][j]]=std::min(er[i][ep[i][j]],er[i+1][j]);
		}
	}
	rem(1,0);
	for(int i=0;i<m;i++){
		printf("%d ",res[i]);
	}
	
	return 0;
}