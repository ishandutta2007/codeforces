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

void pre(){


}

void solve(){


}
int a[1000009];
ll p[1000009];
ll p1[1000009],p2[1000009];
ll ans1[1000009],ans2[1000009];
bool pr[1000009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) cin>>a[i];
	p[0]=a[0];
	repA(i,1,n-1) p[i]=a[i]+p[i-1];
	if(p[n-1]==1){
		cout<<-1;
		return 0;
	}
	ll fns = p[n-1]*n;
	ll s = p[n-1];
	repA(i,2,1000000) if(!pr[i]){
		for(int j = 2*i;j<=1000000;j+=i) pr[j]=1;
	}
	vector<ll> gg;
	repA(i,2,1000000){
		if(!pr[i]&&s%i==0){
			gg.pb(i);
			while(s%i==0) s/=i;
		}
	}
	if(s>1) gg.pb(s);
	trav(i,gg){
		rep(j,n) p1[j]=(p[j]/i)*i,p2[j]=p1[j]+i;
		ans1[n-1]=ans2[n-1]=0;
		repD(j,n-2,0){
			ans1[j] = n*p[n-1];
			ans2[j] = n*p[n-1];
			ans1[j] = min(ans1[j],ans1[j+1]+abs(p[j]-p1[j]));
			ans1[j] = min(ans1[j],ans2[j+1]+abs(p[j]-p1[j]));
			ans2[j] = min(ans2[j],ans2[j+1]+abs(p[j]-p2[j]));
			if(p2[j]<=p1[j+1]) ans2[j] = min(ans2[j],ans1[j+1]+abs(p[j]-p2[j]));
		}
		fns=min({fns,ans1[0],ans2[0]});
	}
	cout<<fns;
	return 0;
}