#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

const int N=300050;
ll a[N];
int p[N];
vector<pii> E[N];
vector<int> nodes[N];
bool was[N];
int mark[N],tid;
int main(){
	int n,m,x;
	rd(n,m,x);
	ra(a,n);
	ll sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	for(int i=1;i<=m;i++){
		int u,v;
		rd(u,v);
		E[u].pb({v,i});
		E[v].pb({u,i});
	}
	if(sum<(ll)(n-1)*x)return 0*printf("NO\n");
	printf("YES\n");
	priority_queue<pair<ll,pii>> pq;
	for(int i=1;i<=n;i++){
		nodes[i]={i};
		p[i]=i;
		mark[i]=++tid;
		pq.push({a[i],{i,mark[i]}});
	}
	for(int z=1;z<n;z++){
		while(mark[pq.top().second.first]!=pq.top().second.second)pq.pop();
		int i=pq.top().second.first;
		pq.pop();
		//while(was[E[i].back().second]||p[E[i].back().first]==i)E[i].pop_back();
		while(p[E[i].back().first]==i)E[i].pop_back();
		pii e=E[i].back();
		E[i].pop_back();
		//was[e.second]=true;
		printf("%i\n",e.second);
		int j=p[e.first];
		if(E[i].size()+nodes[i].size()>E[j].size()+nodes[j].size())swap(i,j);
		for(pii e:E[i])E[j].pb(e);
		for(int node:nodes[i])nodes[j].pb(node),p[node]=j;
		E[i].clear();
		nodes[i].clear();
		mark[i]=-1;
		mark[j]=++tid;
		a[j]+=a[i];
		a[j]-=x;
		pq.push({a[j],{j,mark[j]}});
	}
	return 0;
}