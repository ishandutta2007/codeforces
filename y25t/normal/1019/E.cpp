#include<bits/stdc++.h>
#define ll long long
#define pii std::pair<ll,ll>
#define mp std::make_pair
#define fir first
#define sec second
#define N 100005

pii operator + (pii x,pii y){
	return mp(x.fir+y.fir,x.sec+y.sec);
}
pii operator - (pii x,pii y){
	return mp(x.fir-y.fir,x.sec-y.sec);
}
__int128 operator * (pii x,pii y){
	return (__int128)x.fir*y.sec-(__int128)x.sec*y.fir;
}
std::vector<pii> build(std::vector<pii> &v){
	std::vector<pii> res;
	std::sort(v.begin(),v.end());
	v.erase(std::unique(v.begin(),v.end()),v.end());
	for(auto x:v){
		while(res.size()>1&&(res[res.size()-2]-res.back())*(x-res.back())<0)
			res.pop_back();
		res.push_back(x);
	}
	return res;
}

int n,m;

std::vector<std::pair<int,pii>> E[N];

int hd[N<<1],_hd=1;
struct edge{
	int v;
	pii w;
	int nxt;
}e[N<<2];
inline void addedge(int u,int v,pii w){
	e[++_hd]=(edge){v,w,hd[u]};
	hd[u]=_hd;
	e[++_hd]=(edge){u,w,hd[v]};
	hd[v]=_hd;
}

int tot;
inline void dfs0(int u,int fa){
	int lst=u;
	for(auto [v,w]:E[u]){
		if(v==fa)
			continue;
		dfs0(v,u);
		addedge(lst,v,w);
		addedge(lst,++tot,mp(0,0));
		lst=tot;
	}
}

bool vis[N<<1];
int sz[N<<1],rt,s,mx;
inline void fnd(int u,int fa){
	sz[u]=1;
	for(int i=hd[u];i;i=e[i].nxt){
		if(i==(fa^1)||vis[i>>1])
			continue;
		int v=e[i].v;
		fnd(v,i);
		sz[u]+=sz[v];
	}
	if(std::max(sz[u],s-sz[u])<mx){
		rt=fa;
		mx=std::max(sz[u],s-sz[u]);
	}
}
std::vector<pii> p,q,r,ans;
inline void dfs(int u,int fa,pii x){
	p.push_back(x);
	for(int i=hd[u];i;i=e[i].nxt){
		if(i==(fa^1)||vis[i>>1])
			continue;
		dfs(e[i].v,i,x+e[i].w);
	}
}
inline void dvd(int u,int ss){
	if(ss==1)
		return;
	mx=s=ss;
	fnd(u,0);
	vis[rt>>1]=1;
	int x=e[rt].v,y=e[rt^1].v;
	p.clear();
	dfs(x,0,mp(0,0));
	q=p,p.clear();
	dfs(y,0,e[rt].w);
	p=build(p),q=build(q);
	for(int i=p.size()-1;i;i--)
		p[i]=p[i]-p[i-1];
	for(int i=q.size()-1;i;i--)
		q[i]=q[i]-q[i-1];
	r.clear();
	r.push_back(p[0]+q[0]);
	for(int i=1,j=1;i<p.size()||j<q.size();)
		if(i<p.size()&&(j>=q.size()||p[i]*q[j]<0))
			r.push_back(p[i++]);
		else
			r.push_back(q[j++]);
	for(int i=1;i<r.size();i++)
		r[i]=r[i]+r[i-1];
	for(auto i:r)
		ans.push_back(i);
	dvd(y,ss-sz[x]);
	dvd(x,sz[x]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int u,v,a,b;
		scanf("%d%d%d%d",&u,&v,&a,&b);
		E[u].push_back(mp(v,mp(a,b)));
		E[v].push_back(mp(u,mp(a,b)));
	}
	tot=n;
	dfs0(1,0);
	dvd(1,tot);
	ans.push_back(mp(0,0));
	ans=build(ans);
	for(int i=0,j=0;i<m;i++){
		while(j<ans.size()-1&&ans[j+1].sec-ans[j].sec>-i*(ans[j+1].fir-ans[j].fir))
			j++;
		printf("%lld ",ans[j].fir*i+ans[j].sec);
	}
	puts("");
}