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

const int N=2005;
const int H=1000050;
pii A[N],B[N];
int ptr[N];
int cnt[H],mxp;
vector<int> T[H];
int main(){
	int n,m;
	rd(n,m);
	ra(A,n);
	ra(B,m);
	sort(B+1,B+1+m,[&](pii i,pii j){return i.second>j.second;});
	//vector<pii> evs;
	auto Get=[&](int i){
		if(ptr[i]>m)return 0;
		return max(0,B[ptr[i]].second-A[i].second+1);
	};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)if(A[i].first<=B[j].first){
			//evs.pb({B[j].first-A[i].first+1,i});
			T[B[j].first-A[i].first+1].pb(i);
		}
		ptr[i]=1;
		while(ptr[i]<=m&&B[ptr[i]].first<A[i].first)ptr[i]++;
		cnt[Get(i)]++;
		mxp=max(mxp,Get(i));
	}
	//sort(evs.begin(),evs.end());
	int ans=mxp;
	//for(pii p:evs){
	for(int t=1;t<H;t++){
		//int i,t;tie(t,i)=p;
		for(int i:T[t]){
			cnt[Get(i)]--;
			while(ptr[i]<=m&&B[ptr[i]].first<A[i].first+t)ptr[i]++;
			cnt[Get(i)]++;
		}
		while(cnt[mxp]==0)mxp--;
		ckmn(ans,t+mxp);
	}
	printf("%i\n",ans);
	return 0;
}