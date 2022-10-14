#include <bits/stdc++.h>

#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}

struct flow{
#define N 1000
#define M 21000
#define Nf 1023
	struct edge{
		int to,w,ne,v;
	}
	e[M*2+2];
	ll p[N+1],em=2,q[N<<1],qe,fa[N+1],dis[N+1];
	bool vis[N+1];
	flow(){
		set0(p);
		set0(q);
		set0(fa);
		set0(dis);
		set0(e);
		set0(vis);
	}
	inline int addedge(int a,int b,int w,int v){
		e[em].to=b,e[em].w=w,e[em].v=v,e[em].ne=p[a],p[a]=em++;
		e[em].to=a,e[em].w=0,e[em].v=-v,e[em].ne=p[b],p[b]=em++;
		return em-2;
	}
	inline int getans(int s,int t,ll&cost){
		cost=0;
		int flow=0;
		while(1){
			memset(dis,0x3f,sizeof(dis));
			memset(fa,0x3f,sizeof(fa));
			dis[s]=0;
			vis[s]=1;
			q[0]=s,qe=1;
			for(int i=0;i^qe;i++){
				int k=q[i&Nf];
				for(int j=p[k];j;j=e[j].ne) if(e[j].w&&dis[e[j].to]>dis[k]+e[j].v){
					dis[e[j].to]=dis[k]+e[j].v;
					fa[e[j].to]=j^1;
					if(!vis[e[j].to])q[(qe++)&Nf]=e[j].to,vis[e[j].to]=1;
				}
				vis[k]=0;
			}
			if(fa[t]==0x3f3f3f3f)break;
			if(dis[t]>=0)break;
			int rfl=0x7fffffff;
			for(int i=t;i!=s;i=e[fa[i]].to)rfl=std::min(rfl,e[fa[i]^1].w);
			cost+=dis[t]*rfl;
			flow+=rfl;
			for(int i=t;i!=s;i=e[fa[i]].to)e[fa[i]].w+=rfl,e[fa[i]^1].w-=rfl;
		}
		return flow;
	}
#undef N
#undef M
#undef Nf
};

const int N=205,inf=1e6;

int n1,n2,m,r,b,u,v,deg1[N],deg2[N];
char desc1[205],desc2[205];
string desc = "RUB";
int edge_desc[20000][2];
int main(){
	flow A;
	read(n1,n2,m,r,b);
	cin>>(desc1+1)>>(desc2+1);
	int s = N*2+1,t = N*2+2;
	ll ans = 0;
	for(int i=0;i<m;i++){
		read(u,v);
		ans+=r;
		edge_desc[i][0] = A.addedge(u,N+v,1,-r);
		edge_desc[i][1] = A.addedge(u,N+v,1,b);
		deg1[u]+=1;deg2[v]+=1;
	}
	int rans = 0;
	for(int i=1;i<=n1;i++){
		if(desc1[i] == 'B'){
			rans+=deg1[i]+1;
			A.addedge(s,i,deg1[i]+1,-inf);
			A.addedge(s,i,deg1[i]-1,0);
		}
		if(desc1[i] == 'R'){
			A.addedge(s,i,deg1[i]-1,0);
		}
		if(desc1[i] == 'U'){
			A.addedge(s,i,deg1[i]*2,0);
		}
	}
	for(int i=1;i<=n2;i++){
		if(desc2[i] == 'B'){
			rans+=deg2[i]+1;
			A.addedge(i+N,t,deg2[i]+1,-inf);
			A.addedge(i+N,t,deg2[i]-1,0);
		}
		if(desc2[i] == 'R'){
			A.addedge(i+N,t,deg2[i]-1,0);
		}
		if(desc2[i] == 'U'){
			A.addedge(i+N,t,deg2[i]*2,0);
		}
	}
	ll ff = 0;
	A.getans(s,t,ff);
	if(abs(ff+1ll*inf*rans)>inf/2){
		cout<<-1<<endl;
	}else{
		ans+=ff+1ll*inf*rans;
		cout<<ans<<endl;
		for(int i=0;i<m;i++){
			int cc = 2-A.e[edge_desc[i][0]].w-A.e[edge_desc[i][1]].w;
			cout<<desc[cc];
		}
		cout<<endl;
	}
	return 0;
}