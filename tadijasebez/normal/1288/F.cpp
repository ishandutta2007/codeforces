#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
#define vi vector<int>
const int N=410;
const int M=N*8;
const int inf=1e6;
int xb,s,t;
struct Edge{int u,v,w,c;}edges[M];
vi E[N];
void AddEdge(int u,int v,int w,int c){
	E[u].pb(xb);edges[xb++]=(Edge){u,v,w,c};
	E[v].pb(xb);edges[xb++]=(Edge){v,u,-w,0};
}
const ll oo=1e18;
ll ds[N];
int in[N],go[N];
bool BFS(){
	for(int i=s;i<=t;i++)ds[i]=oo,in[i]=0;
	queue<int> q;q.push(s);ds[s]=0;in[s]=1;
	while(q.size()){
		int u=q.front();q.pop();in[u]=0;
		for(int e:E[u]){
			int v,w,c;tie(v,w,c)=make_tuple(edges[e].v,edges[e].w,edges[e].c);
			if(c && ds[v]>ds[u]+w){
				ds[v]=ds[u]+w;go[v]=e;
				if(!in[v])q.push(v),in[v]=1;
			}
		}
	}
	return ds[t]!=oo;
}
ll MinCostMaxFlow(){
	ll ans=0;
	while(BFS() && ds[t]<0){
		ans+=ds[t];
		for(int i=t;i!=s;i=edges[go[i]].u){
			edges[go[i]].c--;
			edges[go[i]^1].c++;
		}
	}
	return ans;
}
char col1[N],col2[N];
int mao[N];
int main(){
	int n1,n2,m,r,b;
	scanf("%i %i %i %i %i",&n1,&n2,&m,&r,&b);
	scanf("%s",col1+1);
	int cnt=0;
	s=0;t=n1+n2+1;
	for(int i=1;i<=n1;i++){
		if(col1[i]=='R')AddEdge(s,i,-inf,1),cnt++;
		if(col1[i]=='B')AddEdge(i,t,-inf,1),cnt++;
		if(col1[i]!='B')AddEdge(s,i,0,inf);
		if(col1[i]!='R')AddEdge(i,t,0,inf);
	}
	scanf("%s",col2+1);
	for(int i=1;i<=n2;i++){
		if(col2[i]=='R')AddEdge(i+n1,t,-inf,1),cnt++;
		if(col2[i]=='B')AddEdge(s,i+n1,-inf,1),cnt++;
		if(col2[i]!='B')AddEdge(i+n1,t,0,inf);
		if(col2[i]!='R')AddEdge(s,i+n1,0,inf);
	}
	for(int i=1,u,v;i<=m;i++){
		scanf("%i %i",&u,&v);v+=n1;
		AddEdge(u,v,r,1);
		AddEdge(v,u,b,1);
		mao[i]=xb-4;
	}
	ll ans=MinCostMaxFlow()+(ll)cnt*inf;
	if(ans>=inf)printf("-1\n");
	else{
		printf("%lld\n",ans);
		for(int i=1;i<=m;i++)printf("%c",edges[mao[i]].c==0?'R':edges[mao[i]+2].c==0?'B':'U');
		printf("\n");
	}
	return 0;
}