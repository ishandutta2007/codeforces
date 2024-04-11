#include<bits/stdc++.h>
#define ll long long
#define pii std::pair<ll,int>
#define inf 0x3f3f3f3f3f3f3f3f
#define N 100005

int n,m,q;

struct Edge{
	int w,u,v;
}E[N<<1];

std::map<std::pair<int,int>,int> id;

std::set<pii> a[N],s,t;
ll mx[N];
inline ll f(int u){
	if(a[u].size()<3)
		return inf;
	ll res=0;
	auto it=a[u].begin();
	for(int i=0;i<3;i++,it=next(it))
		res+=it->first;
	return res;
}
inline ll g(int u){
	ll res=inf;
	auto it=a[u].begin();
	for(int i=0;i<3&&it!=a[u].end();i++,it=next(it))
		res=it->first;
	return res;
}
inline void ers(int u){
	auto it=a[u].begin();
	for(int i=0;i<3&&it!=a[u].end();i++,it++)
		t.erase(*it);
	s.erase({f(u),u});
}
inline void ins(int u){
	auto it=a[u].begin();
	for(int i=0;i<3&&it!=a[u].end();i++,it++)
		if(it->first<=std::min(mx[E[it->second].u],mx[E[it->second].v]))
			t.insert(*it);
	s.insert({f(u),u});
}

inline ll cal(){
	ll res=s.begin()->first;
	auto it=t.begin();
	for(int o=0;o<6&&it!=t.end();o++,it=next(it)){
		auto [u,x]=*it;
		for(auto [v,y]:t)
			if(std::set<int>({E[x].u,E[x].v,E[y].u,E[y].v}).size()==4){
				res=std::min(res,u+v);
				break;
			}
	}
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		E[i]=(Edge){w,u,v};
		id[std::minmax(u,v)]=i;
		a[u].insert({w,i}),a[v].insert({w,i});
	}
	for(int i=1;i<=n;i++)
		mx[i]=g(i);
	for(int i=1;i<=n;i++)
		ins(i);
	printf("%lld\n",cal());
	scanf("%d",&q);
	while(q--){
		int tp,u,v,w;
		scanf("%d%d%d",&tp,&u,&v);
		ers(u),ers(v);
		if(!tp){
			int i=id[std::minmax(u,v)];
			a[u].erase({E[i].w,i}),a[v].erase({E[i].w,i});
		}
		else{
			scanf("%d",&w);
			E[++m]=(Edge){w,u,v};
			id[std::minmax(u,v)]=m;
			a[u].insert({w,m}),a[v].insert({w,m});
		}
		mx[u]=g(u),mx[v]=g(v);
		ins(u),ins(v);
		printf("%lld\n",cal());
	}
}