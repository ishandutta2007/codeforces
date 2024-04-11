#include<bits/stdc++.h>
#define pii std::pair<int,int>
#define fr first
#define sc second
#define N 100005

int n;
std::pair<pii,pii> a[N];

std::vector<pii> p;

inline int lb(int x){
	return x&-x;
}
inline bool cmp(pii x,pii y){
	if(x==y)
		return 0;
	bool flg=0;
	if(x.fr<y.fr)
		flg=1,std::swap(x,y);
	while(x.fr>y.fr){
		int t=lb(x.fr)==lb(x.sc),k=std::min(x.fr-y.fr,lb(x.fr));
		x.fr-=k,x.sc-=k*t;
	}
	if(x==y)
		return flg;
	return (x.sc<y.sc)^flg;
}
inline pii lca(pii x,pii y){
	if(x.fr<y.fr)
		std::swap(x,y);
	while(x.fr>y.fr){
		int t=lb(x.fr)==lb(x.sc),k=std::min(x.fr-y.fr,lb(x.fr));
		x.fr-=k,x.sc-=k*t;
	}
	while(x!=y){
		x.sc-=lb(x.fr)*(lb(x.fr)==lb(x.sc)),x.fr-=lb(x.fr);
		y.sc-=lb(y.fr)*(lb(y.fr)==lb(y.sc)),y.fr-=lb(y.fr);
	}
	return x;
}

std::map<pii,std::vector<pii>> E;
std::map<pii,int> d,g;
std::map<int,int> f;
inline void dfs(pii u,pii fa){
	for(auto v:E[u]){
		dfs(v,u);
		d[u]+=d[v];
	}
	if(d[u])
		f[fa.fr+1]^=1,f[u.fr+1]^=1;
	else if(g[u])
		f[u.fr]^=1,f[u.fr+1]^=1;
}

int ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y,z,w;
		scanf("%d%d%d%d",&x,&y,&z,&w);
		x+=y,z+=w;
		a[i]={{x,y},{z,w}};
		p.push_back({x,y}),p.push_back({z,w});
	}
	p.push_back({0,0});
	std::sort(p.begin(),p.end(),cmp),p.erase(std::unique(p.begin(),p.end()),p.end());
	int tmp=p.size();
	for(int i=1;i<tmp;i++)
		p.push_back(lca(p[i-1],p[i]));
	std::sort(p.begin(),p.end(),cmp),p.erase(std::unique(p.begin(),p.end()),p.end());
	for(int i=1;i<p.size();i++)
		E[lca(p[i-1],p[i])].push_back(p[i]);
	for(int i=1;i<=n;i++){
		auto [u,v]=a[i];
		auto w=lca(u,v);
		d[w]-=2,d[u]++,d[v]++;
		g[w]=1;
	}
	dfs({0,0},{-1,-1});
	for(auto [x,y]:f)
		ans+=x&&y;
	printf("%d\n",ans);
}