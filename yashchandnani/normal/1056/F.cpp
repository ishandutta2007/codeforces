#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
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
ld pw[109];
void pre(){
	pw[0] = 1;
	repA(i,1,100) pw[i] = pw[i-1]*0.9;

}
ld dp[2][1009][100];
ld ff(ld x,ld y,ld c,bool fg){
	ld lo = 0,hi = y;
	rep(i,100){
		ld m1 = lo+(hi-lo)/3;
		ld m2 = hi-(hi-lo)/3;
		ld s1 = 1+c*m1,s2=1+c*m2;
		ld t1 = x/s1 + m1;
		ld t2 = x/s2+m2;
		if(t1<t2) hi = m2;
		else lo = m1;
	}
	ld m = (lo+hi)/2;
	ld s = 1+c*m;
	return x/s+m;
}
void solve(){
	int n;cin>>n;
	ld c,t;cin>>c>>t;
	vector<pii> a(n);
	rep(i,n) cin>>a[i].fst>>a[i].snd;
	sort(all(a));
	reverse(all(a));
	int cur = 0;
	fill(dp);
	rep(i,n){
		repA(j,1,1000){
			repA(k,1,n){
				dp[cur][j][k] = dp[1-cur][j][k];
				if((j>=a[i].snd)&&(dp[1-cur][j-a[i].snd][k-1]!=0||(j==a[i].snd&&k==1))) {
					if(dp[cur][j][k]==0) dp[cur][j][k]= dp[1-cur][j-a[i].snd][k-1]+(1.0*a[i].fst/pw[k]);
					else dp[cur][j][k] = min(dp[cur][j][k],dp[1-cur][j-a[i].snd][k-1]+(1.0*a[i].fst/pw[k]));
				}
			}
		}
		cur =1-cur;
	}
	cur =1-cur;
	int ans = 0;
	repA(j,1,1000){
		repA(k,1,n){
			if(dp[cur][j][k]==0) continue;
			if(t-10*k<=0) continue;
			if(ff(dp[cur][j][k],t-10*k,c,0)<=t-10*k) {
				ans = max(ans,j);
			}
		}
	}
	cout<<ans;

}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve(),cout<<'\n';	
	
	
	
	
	return 0;
}