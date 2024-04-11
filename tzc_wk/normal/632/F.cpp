#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=2500;
const int INF=0x3f3f3f3f;
int n,a[MAXN+5][MAXN+5],hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int mn[MAXN+5],fa[MAXN+5];bool vis[MAXN+5];
void prim(){
	vis[1]=1;for(int i=2;i<=n;i++) mn[i]=a[1][i],fa[i]=1;
	for(int i=1;i<=n-1;i++){
		int mnv=INF,k=0;
		for(int j=1;j<=n;j++) if(!vis[j]&&mn[j]<mnv) mnv=mn[j],k=j;
		vis[k]=1;
		for(int j=1;j<=n;j++) if(!vis[j]&&mn[j]>a[k][j]) mn[j]=a[k][j],fa[j]=k;
	}
}
void dfs(int x,int rt,int f,int mx){
	if(f&&a[x][rt]>mx){printf("NOT MAGIC\n");exit(0);}
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dfs(y,rt,x,max(mx,a[x][y]));
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++) if(a[i][i]) return printf("NOT MAGIC\n"),0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(a[i][j]!=a[j][i])
		return printf("NOT MAGIC\n"),0;
	prim();for(int i=2;i<=n;i++) adde(i,fa[i]),adde(fa[i],i);
	for(int i=1;i<=n;i++) dfs(i,i,0,-1);printf("MAGIC\n");
	return 0;
}