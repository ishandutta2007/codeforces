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
const int N=10500;
struct edge{
	int to,next,v;
}e[N];
int n,m,k,S1,S2,T;
int x[505],y[505],l[505],r[505];
int head[N],tot,vis[N];
ll d1[N],d2[N];
priority_queue<pll> Q;
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void SSSP(int S,ll *dis){
	For(i,1,n) dis[i]=1ll<<60,vis[i]=0; 
	dis[S]=0; Q.push(pll(0,S));
	while (!Q.empty()){
		int x=Q.top().se; Q.pop();
		if (vis[x]) continue;
		vis[x]=1;
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]>dis[x]+e[i].v){
				dis[e[i].to]=dis[x]+e[i].v;
				Q.push(pll(-dis[e[i].to],e[i].to));
			}
	}
}
bool check(int v){
	For(i,1,k) e[i+m].v=r[i];
	for (;;){
		SSSP(S1,d1);
		SSSP(S2,d2);
		if (d1[T]+v<=d2[T])
			return 1;
		bool fl=0;
		For(i,1,k)
			if (d1[x[i]]+v<=d2[x[i]]&&e[m+i].v==r[i])
				e[m+i].v=l[i],fl=1;
		if (!fl) return 0; 
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d%d",&S1,&S2,&T);
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v);
	}
	For(i,1,k){
		scanf("%d%d%d%d",&x[i],&y[i],&l[i],&r[i]);
		add(x[i],y[i],r[i]);
	}
	if (check(1)){
		printf("WIN\n");
		For(i,1,k) printf("%d ",e[i+m].v);
		exit(0);
	}
	if (check(0)){
		printf("DRAW\n");
		For(i,1,k) printf("%d ",e[i+m].v);
		exit(0);
	}
	puts("LOSE");
}