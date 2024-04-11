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

vector<pii> ans;
void Make(int l,int r){
	if(l==r)return;
	int mid=l+r>>1;
	Make(l,mid);
	Make(mid+1,r);
	for(int i=0;i<=mid-l;i++){
		ans.pb({l+i,mid+1+i});
	}
}
void Solve(int l,int r){
	if(l==r)return;
	int sz=r-l+1;
	int hal=(sz+1)/2;
	int now=1;
	while(now<hal)now*=2;
	//printf("%i %i %i %i\n",l,l+hal-1,l+now-1,r);
	Make(l,l+now-1);
	Make(r-now+1,r);
	/*Solve(l+hal,r);
	for(int i=0;i<hal;i++){
		ans.pb({l+i,l+hal+i});
	}*/
}

int f(int x,int y){return (x*101+y)%1000000;}
const int N=15050;
int a[N];
void Test(int n){
	for(int i=1;i<=n;i++)a[i]=i;
	for(pii p:ans){
		int tmp=f(a[p.first],a[p.second]);
		a[p.first]=tmp;
		a[p.second]=tmp;
		//for(int i=1;i<=n;i++)printf("%i ",a[i]);printf("\n");
	}
	set<int> st;
	for(int i=1;i<=n;i++)st.insert(a[i]);
	if(st.size()>2 || ans.size()>500000){
		printf("%i WA %i\n",n,ans.size());
		exit(0);
	}
	printf("OK\n");
}
mt19937 rng(time(0));

int main(){
	//for(int t=10000;t--;){
		//int n=ri();
		//int n=rng()%15000+1;
	//for(int n=1;n<=15000;n++){
		int n=ri();
		ans.clear();
		Solve(1,n);
		printf("%i\n",ans.size());
		for(pii p:ans)printf("%i %i\n",p.first,p.second);
		//Test(n);
	//}
	return 0;
}