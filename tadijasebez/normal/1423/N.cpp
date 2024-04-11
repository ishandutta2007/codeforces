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

const int N=12550;
const int M=1000050;
int n,m,u[M],v[M],w[M],val[N],sum[N],ord[N];
vector<pii> E[N];
int main(){
	rd(n,m);
	ra(u,v,m);
	for(int i=1;i<=m;w[i]=1,i++)E[u[i]].pb({v[i],i}),E[v[i]].pb({u[i],i});
	for(int i=1;i<=n;i++){
		sum[i]=E[i].size();
		vector<pii> cns;
		set<int> bad;
		cns.pb({i,-1});
		for(pii e:E[i])if(e.first<i){
			if(!val[e.first]){
				val[e.first]=1;
				w[e.second]=0;
				sum[i]--;
			}
			cns.pb(e);
			bad.insert(sum[e.first]);
		}
		while(cns.size()){
			if(!bad.count(sum[i])){
				break;
			}
			pii o=cns.back();
			cns.pop_back();
			sum[i]++;
			if(o.second==-1)val[i]=1;
			else val[o.first]=0,w[o.second]++;
		}
	}
	vector<int> ans;
	for(int i=1;i<=n;i++)if(val[i])ans.pb(i);
	printf("%i\n",ans.size());
	for(int i:ans)printf("%i ",i);
	printf("\n");
	for(int i=1;i<=m;i++)printf("%i %i %i\n",u[i],v[i],w[i]);
	return 0;
}