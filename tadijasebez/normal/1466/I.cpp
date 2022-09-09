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

bool ask(int i,string s){
	printf("%i %s\n",i,s.c_str());
	fflush(stdout);
	char a[5];
	rd(a);
	return a[0]=='y';
}

int n,b;

string Solve(vector<int> ids,string pref){
	if(pref.size()==b)return pref;
	stack<pair<int,string>> stk;
	stk.push({0,pref});
	for(int i:ids){
		while(stk.size()>1){
			string now=stk.top().second;
			while(now.size()<b)now+='1';
			if(ask(i,now))stk.pop();
			else break;
		}
		if(stk.top().second.size()==b)continue;
		string now=stk.top().second;
		now+='0';
		while(now.size()<b)now+='1';
		if(ask(i,now))stk.push({i,stk.top().second+'1'});
		else stk.push({i,stk.top().second+'0'});
	}
	vector<int> work;
	string best=stk.top().second;
	while(stk.size()>1){
		int i=stk.top().first;
		string now=best;
		while(now.size()<b)now+='1';
		if(ask(i,now)){
			work.clear();
			best=stk.top().second;
		}
		work.pb(i);
		stk.pop();
	}
	return Solve(work,best);
}

int main(){
	rd(n,b);
	vector<int> ids;
	for(int i=1;i<=n;i++)ids.pb(i);
	printf("0 %s\n",Solve(ids,"").c_str());
	fflush(stdout);
	return 0;
}