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
int n,a[N];
bool pref[N],was[N];

int main(){
	for(int t=ri();t--;){
		scanf("%i",&n);
		for(int i=0;i<n;i++)scanf("%i",&a[i]);
		int mx=0;
		for(int i=0;i<n;i++)was[i]=false,pref[i]=false;
		for(int i=0;i<n;i++){
			if(was[a[i]])break;
			ckmx(mx,a[i]);
			if(mx==(i+1))pref[i]=true;
			was[a[i]]=true;
		}
		/*for(int i=0;i<n;i++)printf("%i ",pref[i]);
		puts("");*/
		for(int i=1;i<n;i++)was[i]=false;
		mx=0;
		vector<pair<int,int>> ans;
		for(int i=n-1;i>0;i--){
			if(was[a[i]])break;
			ckmx(mx,a[i]);
			if(mx==n-i&&pref[i-1])ans.pb({i,n-i});
			was[a[i]]=true;
		}
		printf("%i\n",(int)ans.size());
		for(auto c:ans)printf("%i %i\n",c.first,c.second);
	}
    return 0;
}