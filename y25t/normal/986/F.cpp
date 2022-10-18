#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long
#define inf 0x3f3f3f3f
#define M 10005
#define SR 35000005
#define CR 100005

inline void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=x*(a/b);
}

int pr[SR>>3],_pr;
bool npr[SR];
inline void sieve(int x){
	for(int i=2;i<=x;i++){
		if(!npr[i])
			pr[++_pr]=i;
		for(int j=1;j<=_pr&&i*pr[j]<=x;j++){
			npr[i*pr[j]]=1;
			if(i%pr[j]==0)
				break;
		}
	}
}

int m;

struct qry{
	ll n,k;
	int id;
}q[M];
inline bool cmp(qry x,qry y){
	return x.k!=y.k?x.k<y.k:x.n<y.n;
}

int hd[CR],_hd;
struct edge{
	int v,w,nxt;
}e[CR<<3];
inline void addedge(int u,int v,int w){
	e[++_hd]=(edge){v,w,hd[u]};
	hd[u]=_hd;
}

int dis[CR];
std::priority_queue<std::pair<int,int> > h;
inline void dij(){
	h.push(std::make_pair(0,0));
	while(h.size()){
		int u=h.top().second;
		h.pop();
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				h.push(std::make_pair(-dis[v],v));
			}
		}
	}
}

std::vector<ll> d;
ll x,y;
inline void build(ll k){
	d.clear();
	for(int i=1;i<=_pr&&1ll*pr[i]*pr[i]<=k;i++)
		if(k%pr[i]==0){
			while(k%pr[i]==0)
				k/=pr[i];
			d.push_back(pr[i]);
		}
	if(k>1)
		d.push_back(k);
	if(d.size()<=1)
		return;
	if(d.size()==2){
		exgcd(d[0],d[1],x,y);
		y=(y%d[0]+d[0])%d[0];
		return;
	}
	for(int i=1;i<d.size();i++)
		for(int j=0;j<d[0];j++)
			addedge(j,(j+d[i])%d[0],d[i]);
	for(int i=1;i<d[0];i++)
		dis[i]=inf;
	dij();
	for(int i=0;i<d[0];i++)
		hd[i]=0;
	_hd=0;
}

bool ans[M];

int main(){
	sieve(SR-5);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld",&q[i].n,&q[i].k);
		q[i].id=i;
	}
	std::sort(q+1,q+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(q[i].k!=q[i-1].k)
			build(q[i].k);
		if(d.size()==0)
			ans[q[i].id]=0;
		else if(d.size()==1)
			ans[q[i].id]=(q[i].n%d[0]==0);
		else if(d.size()==2)
			ans[q[i].id]=q[i].n%d[0]*y%d[0]*d[1]<=q[i].n;
		else
			ans[q[i].id]=dis[q[i].n%d[0]]<=q[i].n;
	}
	for(int i=1;i<=m;i++)
		puts(ans[i]?"YES":"NO");
}