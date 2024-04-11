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

const int N=1205;
int type[N],tot;
vector<int> my[N],E[N];
vector<vector<int>> ans;
struct cmp{bool operator()(int i,int j){return mp(E[i].size(),i)>mp(E[j].size(),j);}};
int main(){
	int n=ri();
	for(int i=1;i<=3*n;i++)type[ri()]=1;
	stack<int> stk,leaf;
	for(int i=1;i<=6*n;i++){
		if(stk.empty()||type[my[stk.top()][0]]!=type[i]){
			tot++;
			my[tot].pb(i);
			stk.push(tot);
		}else{
			my[stk.top()].pb(i);
			if(my[stk.top()].size()==3){
				int u=stk.top();
				stk.pop();
				while(leaf.size()&&my[leaf.top()][0]>my[u][0]){
					E[u].pb(leaf.top());
					leaf.pop();
				}
				leaf.push(u);
			}
		}
	}
	assert(stk.empty());
	set<int,cmp> st[2];
	while(leaf.size()){
		st[type[my[leaf.top()][0]]].insert(leaf.top());
		leaf.pop();
	}
	for(int i=1;i<=n;i++){
		int j=*st[0].begin();st[0].erase(j);
		ans.pb(my[j]);
		for(int k:E[j])st[1].insert(k),assert(type[my[k][0]]==1);
		j=*st[1].begin();st[1].erase(j);
		ans.pb(my[j]);
		for(int k:E[j])st[0].insert(k),assert(type[my[k][0]]==0);
	}
	reverse(ans.begin(),ans.end());
	for(auto v:ans){
		for(int i:v)printf("%i ",i);
		printf("\n");
	}
	return 0;
}