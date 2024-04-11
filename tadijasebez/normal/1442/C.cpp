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

const int N=200050;
const ll inf=9e18;
const int mod=998244353;
vector<int> E[2][N];
struct Dist{
	ll d,lvl;
	Dist(){d=0;lvl=inf;}
	Dist(ll a,ll b):d(a),lvl(b){}
	bool operator < (Dist b) const { // >
		//if(max(b.lvl,lvl)>20){
			return mp(lvl,d)>mp(b.lvl,b.d);
		//}else return d+(1<<lvl)-1>b.d+(1<<b.lvl)-1;
	}
	int Get(){
		int ans=d%mod,tmp=1;
		for(int i=0;i<lvl;i++)tmp=tmp*2%mod;
		tmp--;if(tmp<0)tmp+=mod;
		return (ans+tmp)%mod;
	}
}dist[2][N];

const int L=21;
const int oo=1e9+7;
int dst[L][N];
void BFS(int n){
	for(int i=1;i<=n;i++)for(int j=0;j<L;j++)dst[j][i]=oo;
	queue<pii> q;
	q.push({0,1});
	dst[0][1]=0;
	while(q.size()){
		int u,t;tie(t,u)=q.front();
		q.pop();
		for(int v:E[t%2][u]){
			if(dst[t][v]==oo){
				dst[t][v]=dst[t][u]+1;
				q.push({t,v});
			}
		}
		if(t!=L-1){
			for(int v:E[(t%2)^1][u]){
				if(dst[t+1][v]==oo){
					dst[t+1][v]=dst[t][u]+1;
					q.push({t+1,v});
				}
			}
		}
	}
}
void Dijkstra(int n){
	priority_queue<pair<Dist,pii>> pq;
	dist[0][1]=Dist(0,0);
	pq.push({Dist(0,0),{0,1}});
	while(pq.size()){
		Dist d;pii U;tie(d,U)=pq.top();pq.pop();
		int u,t;tie(t,u)=U;
		if(d<dist[t][u])continue;
		for(int v:E[t][u]){
			Dist w=Dist(d.d+1,d.lvl);
			if(dist[t][v]<w){
				dist[t][v]=w;
				pq.push({w,{t,v}});
			}
		}
		for(int v:E[t^1][u]){
			Dist w=Dist(d.d+1,d.lvl+1);
			if(dist[t^1][v]<w){
				dist[t^1][v]=w;
				pq.push({w,{t^1,v}});
			}
		}
	}
}

Dist min(Dist a,Dist b){
	if(max(a.lvl,b.lvl)>20){
		if(mp(a.lvl,a.d)<mp(b.lvl,b.d))return a;
		else return b;
	}else{
		if(a.d+(1<<a.lvl)-1<b.d+(1<<b.lvl)-1)return a;
		else return b;
	}
}
int main(){
	int n,m;rd(n,m);
	for(int i=1,u,v;i<=m;i++){
		rd(u,v);
		E[0][u].pb(v);
		E[1][v].pb(u);
	}
	BFS(n);
	Dijkstra(n);
	Dist ans=min(dist[0][n],dist[1][n]);
	for(int i=0;i<L;i++)if(dst[i][n]<oo){
		ans=min(ans,Dist(dst[i][n],i));
	}
	printf("%i\n",ans.Get());
	return 0;
}