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

const int N=100050;
int a[N],ans[N],mark[N];
vector<int> ids[N];
int main(){
	for(int t=ri();t--;){
		int n,x,y;rd(n,x,y);
		ra(a,n);
		for(int i=1;i<=n+1;i++)ids[i].clear();
		for(int i=1;i<=n;i++)ids[a[i]].pb(i);
		int grey=0;
		for(int i=1;i<=n+1;i++)if(ids[i].empty())grey=i;
		set<pii> all;
		for(int i=1;i<=n+1;i++)all.insert({ids[i].size(),i});
		for(int i=1;i<=n;i++)ans[i]=grey,mark[i]=0;
		int o=0;
		while(o<x){
			int col=all.rbegin()->second;
			all.erase(--all.end());
			ans[ids[col].back()]=col;
			mark[ids[col].back()]=1;
			ids[col].pop_back();
			o++;
			all.insert({ids[col].size(),col});
		}
		while(1){
			int A=all.rbegin()->second;
			int B=prev(prev(all.end()))->second;
			if(ids[B].empty())break;
			if((all.size()==3&&ids[A].size()==1&&prev(prev(prev(all.end())))->first==1)||(all.size()>3&&ids[A].size()==1&&prev(prev(prev(all.end())))->first==1&&prev(prev(prev(prev(all.end()))))->first==0)){
				int C=prev(prev(prev(all.end())))->second;
				all.erase(--all.end());
				all.erase(--all.end());
				all.erase(--all.end());
				ans[ids[A].back()]=C;
				mark[ids[A].back()]=2;
				ans[ids[B].back()]=A;
				mark[ids[B].back()]=2;
				ans[ids[C].back()]=B;
				mark[ids[C].back()]=2;
				ids[A].pop_back();
				ids[B].pop_back();
				ids[C].pop_back();
				o+=3;
				all.insert({ids[A].size(),A});
				all.insert({ids[B].size(),B});
				all.insert({ids[C].size(),C});
				continue;
			}
			all.erase(--all.end());
			all.erase(--all.end());
			ans[ids[A].back()]=B;
			mark[ids[A].back()]=2;
			ans[ids[B].back()]=A;
			mark[ids[B].back()]=2;
			ids[A].pop_back();
			ids[B].pop_back();
			o+=2;
			all.insert({ids[A].size(),A});
			all.insert({ids[B].size(),B});
		}
		if(o<y)printf("NO\n");
		else{
			printf("YES\n");
			for(int i=1;i<=n;i++)if(mark[i]==2&&o>y){
				o--;
				ans[i]=grey;
			}
			for(int i=1;i<=n;i++)printf("%i ",ans[i]);
			printf("\n");
		}
	}
	return 0;
}