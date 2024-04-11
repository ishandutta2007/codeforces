#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;

const int N=205;
const int M=120005;
int n,m,nd,tot=1,S,T;
int head[M],q[M],dis[M];
char s[N][N];
int id[N][N];
struct edge{
	int to,next,f;
}e[M*10];
void add(int x,int y,int f){
	e[++tot]=(edge){y,head[x],f};
	head[x]=tot; 
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(){
	For(i,1,nd) dis[i]=-1;
	int h=0,t=1;
	q[1]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]==-1&&e[i].f){
				dis[e[i].to]=dis[x]+1;
				if (e[i].to==T) return 1;
				q[++t]=e[i].to;
			}
	}
	return 0;
}
int dfs(int x,int flow){
	if (x==T) return flow;
	int k,rest=flow;
	for (int i=head[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,min(rest,e[i].f));
			e[i].f-=k;e[i^1].f+=k; rest-=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,1,n) For(j,1,m) if (s[i][j]=='#') id[i][j]=++nd;
	S=++nd; T=++nd;
	int ans=0;
	For(i,1,n) For(j,1,m)
		if (s[i][j]=='#'){
			add(S,id[i][j],1);
			add(id[i][j],T,1);
		}
	For(i,1,n) For(j,1,m)
		if (s[i][j]=='#'&&s[i+1][j]=='#'){
			++nd; --ans;
			add(S,nd,1);
			add(nd,id[i][j],1<<30);
			add(nd,id[i+1][j],1<<30);
		}
	For(i,1,n) For(j,1,m)
		if (s[i][j]=='#'&&s[i][j+1]=='#'){
			++nd; --ans;
			add(nd,T,1);
			add(id[i][j],nd,1<<30);
			add(id[i][j+1],nd,1<<30);
		}
	for (;bfs();ans+=dfs(S,1<<30));
	cout<<ans<<endl;
}