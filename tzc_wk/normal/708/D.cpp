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
const int MAXV=100+2;
const int MAXE=1200;
const int INF=0x3f3f3f3f;
int n,m,S=101,T=102;
int hd[MAXV+5],to[MAXE+5],nxt[MAXE+5],cst[MAXE+5],cap[MAXE+5],ec=1;
void adde(int u,int v,int f,int c){
	to[++ec]=v;cap[ec]=f;cst[ec]=c;nxt[ec]=hd[u];hd[u]=ec;
	to[++ec]=u;cap[ec]=0;cst[ec]=-c;nxt[ec]=hd[v];hd[v]=ec;
}
void delback(int x){hd[x]=nxt[hd[x]];}
void addedge(int u,int v,int l,int r,int c){
	adde(S,v,l,0);adde(u,T,l,0);adde(u,v,r-l,c);
}
int dis[MAXV+5],flw[MAXV+5],pre[MAXV+5],lste[MAXV+5];
bool inq[MAXV+5];
bool getdis(int S,int T){
	memset(dis,63,sizeof(dis));memset(flw,0,sizeof(flw));
	dis[S]=0;flw[S]=INF;queue<int> q;q.push(S);inq[S]=1;
	while(!q.empty()){
		int x=q.front();q.pop();inq[x]=0;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=cap[e],w=cst[e];
			if(z&&dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;flw[y]=min(flw[x],z);
				pre[y]=x;lste[y]=e;
				if(!inq[y]){inq[y]=1;q.push(y);}
			}
		}
	} return dis[T]<INF;
}
pii mcmf(int S,int T){
	int mxfl=0,mncst=0;
	while(getdis(S,T)){
		mxfl+=flw[T];mncst+=flw[T]*dis[T];
		for(int i=T;i!=S;i=pre[i]){
			cap[lste[i]]-=flw[T];cap[lste[i]^1]+=flw[T];
		}
	} return mp(mxfl,mncst);
}
int main(){
	scanf("%d%d",&n,&m);int totcst=0;
	for(int i=1;i<=m;i++){
		int u,v,c,f;scanf("%d%d%d%d",&u,&v,&c,&f);
		if(f<c){
			adde(u,v,c-f,1);adde(v,u,f,1);
			adde(u,v,INF,2);
		} else {
			adde(v,u,f-c,0);adde(v,u,c,1);
			adde(u,v,INF,2);totcst+=f-c;
		}
		addedge(u,v,f,f,0);
	} adde(n,1,INF,0);
	totcst+=mcmf(S,T).se;
	printf("%d\n",totcst);
	return 0;
}