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

vector<ll> Gauss;
vector<pair<int,pll>> ans;
vector<ll> need;
bool Add(ll x){
	ll tmp=x;
	//int sz=ans.size();
	for(ll y:Gauss){
		if((x^y)<x){
			//ans.pb({1,{x,y}});
			x^=y;
		}
	}
	if(x!=0)Gauss.pb(x),need.pb(tmp);//,printf("%lld\n",x);
	//else{
		//while(ans.size()>sz)ans.pop_back();
	//}
	if(x==1)return 1;
	return 0;
}
void Solve(ll x){
	Gauss.clear();
	for(ll y:need){
		ll o=y/x;
		ll now=0;
		for(int i=62;i>=0;i--){
			if(now>0){
				ans.pb({0,{now,now}});
				now+=now;
			}
			if(o>>i&1){
				if(now!=0)ans.pb({0,{now,x}});
				now+=x;
			}
		}
		for(ll z:Gauss){
			if((y^z)<y){
				ans.pb({1,{y,z}});
				y^=z;
			}
		}
		Gauss.pb(y);
	}
}
mt19937 rng(time(0));
int main(){
	int t=1;
	int mx=0;
	while(t--){
		ll x=ri();
		//ll x=rng()%10000000;
		//x*=2;x++;
		ans.clear();
		Gauss.clear();
		need.clear();
		Add(x);
		ll now=x;
		while(1){
			//ans.pb({0,{now,x}});
			now+=x;
			if(Add(now))break;
		}
		Solve(x);
		//mx=max(mx,(int)ans.size());
		//printf("%i %i\n",ans.size(),mx);
		printf("%i\n",ans.size());
		for(auto o:ans){
			if(o.first)printf("%lld ^ %lld\n",o.second.first,o.second.second);
			else printf("%lld + %lld\n",o.second.first,o.second.second);
		}
	}
	//printf("%i\n",mx);
	return 0;
}