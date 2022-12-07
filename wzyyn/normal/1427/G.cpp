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
int n,nd;
int a[N][N];
int id[N][N];
int S,T,tot=1;
struct edge{
	int to,next,f;
}e[N*N*4];
int head[N*N];
int dis[N*N],q[N*N],from[N*N];
void add(int x,int y,int f1,int f2){
	e[++tot]=(edge){y,head[x],f1};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],f2};
	head[y]=tot;
}
bool bfs(int S,int T){
	For(i,1,::T) dis[i]=-1;
	int h=0,t=1;
	q[1]=S; dis[S]=0;
	while (h!=t&&dis[T]==-1){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]==-1&&e[i].f){
				dis[e[i].to]=dis[x]+1;
				from[e[i].to]=i;
				q[++t]=e[i].to;
			}
	}
	if (dis[T]==-1) return 0;
	for (int i=T;i!=S;i=e[from[i]^1].to)
		e[from[i]].f--,e[from[i]^1].f++;//cerr<<
	return 1;
}

struct node{
	int x,y,key,id;
}info[N*4];
int eS[N*4],eT[N*4];
int top;
int main(){
	scanf("%d",&n);
	For(i,1,n) For(j,1,n)
		scanf("%d",&a[i][j]);
	For(i,1,n) For(j,1,n)
		id[i][j]=++nd;
	S=++nd; T=++nd;
	For(i,1,n) For(j,1,n){
		if (i!=n&&a[i][j]!=-1&&a[i+1][j]!=-1)
			add(id[i][j],id[i+1][j],1,1);
		if (j!=n&&a[i][j]!=-1&&a[i][j+1]!=-1)
			add(id[i][j],id[i][j+1],1,1);
	}
	For(i,1,n) For(j,1,n)
		if (i==1||i==n||j==1||j==n){
			++top;
			info[top]=(node){i,j,a[i][j],top};
			eS[top]=tot+1;
			add(S,id[i][j],1<<30,0);
			eT[top]=tot+1;
			add(id[i][j],T,0,0);
		}
	For(i,1,top) For(j,i+1,top)
		if (info[i].key>info[j].key)
			swap(info[i],info[j]);
	ll flo=0,ans=0;
	For(i,1,top-1){
		int x=info[i].id;
		int px=id[info[i].x][info[i].y];
		int tui=e[eS[x]^1].f;
		e[eS[x]].f=e[eS[x]^1].f=0;
		for (;tui&&bfs(T,px);--flo,--tui);
		e[eT[x]].f=1<<30;//cout<<flo<<endl;
		for (;bfs(S,T);++flo);
		ans+=flo*(info[i+1].key-info[i].key);
		//cout<<info[i].x<<' '<<info[i].y<<' '<<info[i].id<<' '<<info[i].key<<' '<<flo<<endl;
	}
	printf("%lld\n",ans);
}