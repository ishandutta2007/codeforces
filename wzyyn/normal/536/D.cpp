#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=2005;
struct edge{
	int to,next,v;
}e[N*N];
int head[N],tot,n,m,S,T;
int dS[N],dT[N],id[N];
int S1[N][N],v[N],Vis[N];
ll S2[N][N],dis[N];
ll f[N][N][2][2];
bool vis[N][N][2][2];
priority_queue<pll> Q;
bool cmp(int x,int y){
	return dis[x]<dis[y];
}
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void SSSP(int S,int *d){
	For(i,1,n){
		Vis[i]=d[i]=0;
		dis[i]=1ll<<60;
	}
	dis[S]=0;
	Q.push(pll(-dis[S],S));
	while (!Q.empty()){
		int x=Q.top().se; Q.pop();
		if (Vis[x]) continue;
		Vis[x]=1;
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]>dis[x]+e[i].v){
				dis[e[i].to]=dis[x]+e[i].v;
				Q.push(pll(-dis[e[i].to],e[i].to));
			}
	}
	For(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmp);
	d[id[1]]=1;
	For(i,2,n) d[id[i]]=d[id[i-1]]+(dis[id[i]]!=dis[id[i-1]]);
}
int SS1(int x,int y,int X,int Y){
	return S1[x][y]-S1[X][Y];
}
ll SS2(int x,int y,int X,int Y){
	return S2[x][y]-S2[X][Y];
}
ll F(int x,int y,int f1,int f2){
	if (x>n||y>n) return 0;
	if (vis[x][y][f1][f2])
		return f[x][y][f1][f2];
	vis[x][y][f1][f2]=1;
	ll ans;
	if (f1) ans=F(x,y+1,f1,f2||SS1(x,y,x,y+1))+SS2(x,y,x,y+1);
	else	ans=F(x+1,y,f1,f2||SS1(x,y,x+1,y))+SS2(x,y,x+1,y);
	if (f2) ans=max(ans,-F(x,y,!f1,0));
	return f[x][y][f1][f2]=ans;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&S,&T);
	For(i,1,n) scanf("%d",&v[i]);
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	SSSP(S,dS); SSSP(T,dT);
	For(i,1,n){
		S1[dS[i]][dT[i]]++;
		S2[dS[i]][dT[i]]+=v[i];
	}
	Rep(i,n,1) Rep(j,n,1){
		S1[i][j]+=S1[i+1][j];
		S2[i][j]+=S2[i+1][j];
	}
	Rep(i,n,1) Rep(j,n,1){
		S1[i][j]+=S1[i][j+1];
		S2[i][j]+=S2[i][j+1];
	}
	ll ans=F(1,1,0,0);
	if (ans==0) puts("Flowers");
	else puts(ans<0?"Cry":"Break a heart");
}