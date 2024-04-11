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
vector<int> E[N],id(N),ord;
bool was[N];
deque<int> q;

void BFS(int root){
	was[root]=true;
	q.pb(root);
	ord.pb(root);
	while(!q.empty()){
		int x=q[0];
		q.pop_front();
		for(int j:E[x])if(!was[j]){
			q.pb(j);
			ord.pb(j);
			was[j]=true;
		}
	}
}

int main(){
	int n;rd(n);
	for(int i=1;i<n;i++){
		int u,v;rd(u,v);
		E[u].pb(v);
		E[v].pb(u);
	}
	auto a=rv<int>(n);
	for(int i=0;i<n;i++)id[a[i]]=i;
	for(int i=1;i<=n;i++){
		sort(E[i].begin(),E[i].end(),[&](int x,int y){
			return id[x]<id[y];
		});
	}
	BFS(1);
	if((int)ord.size()!=n)return 0*printf("No");
	//for(int i=0;i<n;i++)printf("%i ",q[i]);
	//puts("");
	for(int i=0;i<n;i++)if(ord[i]!=a[i])return 0*printf("No");
	printf("Yes");
    return 0;
}