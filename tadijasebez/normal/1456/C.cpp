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

const int N=500050;
int c[N];
ll sum[N],pre[N];
/*struct Line{
	ll n,k;
	int cnt;
	Line(){}
	Line(ll a,ll b,int c):n(a),k(b),cnt(c){}
	ll Get(ll x){return x*k+n;}
};
int sec(Line a,Line b){
	ll p=a.n-b.n;
	ll q=b.k-a.k;
	if(q<0)p=-p,q=-q;
	if(p<0)return p/q;
	else return (p+q-1)/q;
}
vector<Line> hull;
void AddLine(Line l){
	int sz=hull.size();
	while(sz>1 && sec(hull[sz-2],hull[sz-1])>sec(hull[sz-1],l)){
		sz--;
		hull.pop_back();
	}
	hull.pb(l);sz++;
}
pair<ll,int> Get(ll x){
	int bot=1,top=(int)hull.size()-1,mid,ans=0;
	while(top>=bot){
		int mid=bot+top>>1;
		if(hull[mid-1].Get(x)<hull[mid].Get(x))ans=mid,bot=mid+1;
		else top=mid-1;
	}
	return {hull[ans].Get(x),hull[ans].cnt};
}
ll dp[N];
int cnt[N];
void Push(int L){
	AddLine(Line(dp[L]+sum[L]*(L+1)-pre[L],(L+1),cnt[L]));
}
pair<ll,int> Solve(int C,int n){
	hull.clear();
	dp[0]=0;
	cnt[0]=0;
	Push(0);
	for(int i=1;i<=n;i++){
		pair<ll,int> now=Get(-sum[i]);
		dp[i]=now.first+pre[i]+C;
		cnt[i]=now.second+1;
		Push(i);
	}
	return {dp[n],cnt[n]};
}*/
int o[N];
int main(){
	int n,k;rd(n,k);
	k++;k=min(n,k);
	ra(c,n);
	sort(c+1,c+1+n);

	ll ans=0;
	int now=-1;
	o[0]=-1;
	for(int i=1;i<=n;i++){
		now=(i-1)/k;
		sum[i]=sum[i-1]+(ll)c[i]*now;
		o[i]=now;
	}
	ans=sum[n];
	ll tmp=0,sm=0;
	for(int i=n;i>=1;i--){
		if(o[i]==o[i-1])tmp+=sm;
		tmp+=(ll)c[i]*(o[i-1]+1);
		sm+=c[i];
		ckmx(ans,sum[i-1]+tmp);
	}
	printf("%lld\n",ans);
	/*int top=k-1,bot=1,mid,ans=k;
	while(top>=bot){
		mid=top+bot>>1;
		ll X=0,Y=0;
		for(int i=1;i<=n;i++){
			int now=(i-1)/mid;
			X+=(ll)c[i]*now;
			now=(i-1)/(mid+1);
			Y+=(ll)c[i]*now;
		}
		printf("%i %i: %lld %lld\n",mid,mid+1,X,Y);
		if(Y<X)ans=mid,top=mid-1;
		else bot=mid+1;
	}
	ll sol=0;
	for(int i=1;i<=n;i++){
		int now=(i-1)/ans;
		sol+=(ll)c[i]*now;
	}
	printf("%lld\n",sol);
	for(ans=1;ans<=k;ans++){
		ll sol=0;
		for(int i=1;i<=n;i++){
			int now=(i-1)/ans;
			sol+=(ll)c[i]*now;
		}
		printf("%lld\n",sol);
	}*/
	/*int top=1e6,bot=-1e6,ans=1e6;
	while(top>=bot){
		int C=top+bot>>1;
		if(Solve(C,n).second>ans)bot=C+1;
		else ans=C,top=C-1;
	}
	int C=ans;
	ll sol=Solve(C,n).first-(ll)k*C;
	printf("%lld\n",sol);*/
	return 0;
}