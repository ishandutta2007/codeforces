#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 10005;
const int INF = (1<<30)-1;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int hd[N],iter[N],dis[N];
struct E{int v,w,nxt;}e[N<<3];
queue<int>Q;
bool v[N];
int x[N],y[N];
int n,m,d,tot=1,S,T;

inline void add(int u,int v,int w){
	e[++tot]={v,w,hd[u]};hd[u]=tot;
	e[++tot]={u,0,hd[v]};hd[v]=tot;
}
inline bool bfs(){
	memcpy(iter,hd,sizeof(hd));
	memset(dis,-1,sizeof(dis));
	Q.push(S);dis[S]=0;
	while(!Q.empty()){
		int x=Q.front();Q.pop();
		for(int i=hd[x],y;i;i=e[i].nxt)
			if(e[i].w&&dis[y=e[i].v]==-1){
				dis[y]=dis[x]+1, Q.push(y);
			}
	}
	return ~dis[T];
}
int dfs(int x=S,int f=INF){
	if(x==T||!f)return f;
	int sf=0,y;
	for(int &i=iter[x];i;i=e[i].nxt)
		if(e[i].w&&dis[y=e[i].v]==dis[x]+1){
			int w=dfs(y,min(f,e[i].w));
			e[i].w-=w, e[i^1].w+=w;
			f-=w, sf+=w;
			if(!f)break;
		}
	return sf;
}

bool check(int num){
	memset(hd,0,sizeof hd);
	tot = 1;
	S = 0, T = m+n+1;
	rep(i,1,m){
		add(S, i, 1);
		add(i, m+x[i], 1);
		add(i, m+y[i], 1);
	}
	rep(i,1,n) add(m+i,T,num);
	int flow = 0;
	while(bfs()) flow+=dfs();
	return flow==m;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	rep(i,1,m) scanf("%d%d",x+i,y+i);
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid = l+r>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
	check(ans);
	rep(p,1,m){
		for(int i=hd[p];i;i=e[i].nxt)
			if(!e[i].w){
				int a = e[i].v-m, b = x[p]+y[p]-a;
				printf("%d %d\n",a,b);
				break;
			}
	}
	return 0;
}