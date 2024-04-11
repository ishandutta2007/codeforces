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
vector<int> ids[N];
vector<int> cpr[N];
vector<int> E[N];

int main(){
	for(int t=ri();t--;){
		int n,m;
		rd(n,m);
		auto a=rv<int>(n);
		map<int,int> cnt;
		auto b=a;
		sort(b.begin(),b.end());
		b.erase(unique(b.begin(),b.end()),b.end());
		auto Get=[&](int x){
			return lower_bound(b.begin(),b.end(),x)-b.begin()+1;
		};
		for(int i=0;i<n;i++){
			cnt[-a[i]]++;
		}
		vector<int> cs;
		for(auto it:cnt){
			cs.pb(it.second);
			ids[it.second].pb(-it.first);
			cpr[it.second].pb(Get(-it.first));
		}
		sort(cs.begin(),cs.end());
		cs.erase(unique(cs.begin(),cs.end()),cs.end());
		for(int i=1;i<=n;i++)E[i].clear();
		while(m--){
			int u,v;
			rd(u,v);
			E[Get(u)].pb(Get(v));
			E[Get(v)].pb(Get(u));
		}
		ll ans=0;
		vector<bool> bad(n+1,false);
		for(auto it:cnt){
			int x=-it.first;
			int cx=Get(x);
			for(int y:E[cx])bad[y]=true;
			for(int c:cs){
				for(int i=0;i<ids[c].size();i++){
					int y=ids[c][i];
					if(bad[cpr[c][i]]||y==x)continue;
					ans=max(ans,(ll)(it.second+c)*(x+y));
					break;
				}
			}
			for(int y:E[cx])bad[y]=false;
		}
		printf("%lld\n",ans);
		for(auto it:cnt){
			ids[it.second].clear();
			cpr[it.second].clear();
		}
	}
	return 0;
}