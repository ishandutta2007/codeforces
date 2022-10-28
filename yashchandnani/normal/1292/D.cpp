#include <bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
bool p[5009];
vi pr;
void pre(){
	repA(i,2,5000){
		if(!p[i]) {
			pr.pb(i);
			for(int j=i;j<=5000;j+=i) p[j]=1;
		}
	}
	reverse(all(pr));
}

vi v;
vi u;
int n;
int c(int k,int p){
	int cur=p;
	int cnt = 0;
	while(cur<=k) cnt+=k/cur,cur*=p;
	return cnt;
}
ll solve(int l,int r,int tot,int ix,ll ans){
	if(ix==sz(pr)) return ans;
	int i = l;
	ll fns= ans;
	ll gg = 0;
	int cnt2 = tot;
	while(i<r){
		int curcnt=0;
		int j = i;
		int cnt = c(v[i],pr[ix]);
		while(j<r&&(c(v[j],pr[ix])==cnt)) curcnt+=u[j],j++;
		ll cur = ans+1ll*(n-2*cnt2)*cnt-gg;
		fns = min(fns,cur);
		fns=min(fns,solve(i,j,curcnt,ix+1,cur));
		cnt2-=curcnt;
		gg+=2ll*curcnt*cnt;
		i=j;
	}
	return fns;

}
int cntx[5009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	cin>>n;
	ll cost = 0;
	v.resize(n);
	u.resize(n);
	map<int,int> m;
	rep(i,n) {
		int x;cin>>x;
		cntx[x]++;
	}
	repA(i,0,5000){
		if(cntx[i]==0) continue;
		v.pb(i);
		u.pb(cntx[i]);
		rep(j,sz(pr)) cost+=1ll*cntx[i]*c(i,pr[j]);
	}
	cout<<solve(0,sz(v),n,0,cost);	
	return 0;
}