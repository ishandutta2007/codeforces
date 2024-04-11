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

int main(){
	int n,q;rd(n,q);
	multiset<int> x,dif;
	auto Add=[&](int i){
		auto it=x.lower_bound(i);
		if(it!=x.end()&&it!=x.begin())dif.erase(dif.find(*it-*prev(it)));
		x.insert(i);
		it=x.find(i);
		if(next(it)!=x.end())dif.insert(*next(it)-*it);
		if(it!=x.begin())dif.insert(*it-*prev(it));
	};
	auto Del=[&](int i){
		auto it=x.find(i);
		if(next(it)!=x.end())dif.erase(dif.find(*next(it)-*it));
		if(it!=x.begin())dif.erase(dif.find(*it-*prev(it)));
		x.erase(i);
		it=x.lower_bound(i);
		if(it!=x.end()&&it!=x.begin())dif.insert(*it-*prev(it));
	};
	auto Get=[&](){
		if(dif.empty())return 0;
		return *x.rbegin()-*x.begin()-*dif.rbegin();
	};
	for(int i=0;i<n;i++)Add(ri());
	printf("%i\n",Get());
	while(q--){
		int t,x;rd(t,x);
		if(t==0)Del(x);
		else Add(x);
		printf("%i\n",Get());
	}
	return 0;
}