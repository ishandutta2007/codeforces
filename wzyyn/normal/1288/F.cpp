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

const int N=2005;
struct edge{
	int from,to,next,f,v;
}e[N*10];
int head[N],tot=1;
int n1,n2,m,R,B;
char s1[N],s2[N];
int dis[N],vis[N];
int q[N*100],from[N];
int dif[N],d1[N],d2[N];
int sum,ans,id1[N],id2[N];
void add(int x,int y,int f,int v){
	//cout<<x<<' '<<y<<' '<<f<<' '<<v<<endl;
	e[++tot]=(edge){x,y,head[x],f,v};
	head[x]=tot;
	e[++tot]=(edge){y,x,head[y],0,-v};
	head[y]=tot;
}
bool bfs(int S,int T){
	For(i,1,T) dis[i]=1<<30,vis[i]=0;
	int h=0,t=1; q[1]=S;
	dis[S]=0; from[S]=0;
	while (h!=t){
		int x=q[++h]; vis[x]=0;
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]>dis[x]+e[i].v&&e[i].f){
				dis[e[i].to]=dis[x]+e[i].v;
				from[e[i].to]=i;
				if (!vis[e[i].to]){
					vis[e[i].to]=1;
					q[++t]=e[i].to;
				}
			}
	}
	//cout<<dis[T]<<endl;
	if (dis[T]==(1<<30)) return 0;
	sum--;
	for (int i=from[T];i;i=from[e[i].from])
		e[i].f--,e[i^1].f++,ans+=e[i].v;
	return 1;
}
int main(){
	scanf("%d%d%d%d%d",&n1,&n2,&m,&R,&B);
	scanf("%s%s",s1+1,s2+1);
	int S=n1+n2+1,T=S+1,SS=T+1,TT=SS+1;
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		++d1[x]; ++d2[y];
		++dif[x]; --dif[y+n1];
		add(x,y+n1,1,R); id1[i]=tot;
		add(y+n1,x,1,B); id2[i]=tot;
	}
	For(i,1,n1){
		if (!d1[i]&&s1[i]!='U')
			return puts("-1"),0;
		if (s1[i]!='U'){
			add(S,i,d1[i]-1,0);
			if (s1[i]=='R'){
				dif[i]-=d1[i]+1;
				dif[S]+=d1[i]+1;
			}
		}
		else
			add(S,i,2*d1[i],0);
	}
	For(i,1,n2){
		if (!d2[i]&&s2[i]!='U')
			return puts("-1"),0;
		if (s2[i]!='U'){
			add(i+n1,T,d2[i]-1,0);
			if (s2[i]=='R'){
				dif[i+n1]+=d2[i]+1;
				dif[T]-=d2[i]+1;
			}
		}
		else
			add(i+n1,T,2*d2[i],0);
	}
	For(i,1,T)
		if (dif[i]>0){
			sum+=dif[i];
			add(i,TT,dif[i],0);
		}
		else if (dif[i]<0){
			add(SS,i,-dif[i],0);
		}
	add(T,S,1<<30,0);
	//cout<<sum<<endl;
	for (;bfs(SS,TT););
	//cout<<sum<<endl;
	if (sum) return puts("-1"),0;
	printf("%d\n",ans);
	For(i,1,m)
		if (e[id1[i]].f) putchar('R');
		else if (e[id2[i]].f) putchar('B');
		else putchar('U');
}