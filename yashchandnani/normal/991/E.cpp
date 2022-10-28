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
ll f[20];
void pre(){
	f[0]=f[1]=1;
	repA(i,2,19) f[i] = f[i-1]*i;
}
ll C(int n,int r){
	if(r<0||r>n) return 0;
	return f[n]/(f[r]*f[n-r]);
}
vi v;
int cnt[10];
ll ans;
void solve(int x){
	if(x!=10){
		rep(i,cnt[x]+1){
			if(cnt[x]>0&&i==0) continue;
			v.pb(i);
			solve(x+1);
			v.pop_back();
		}
	}
	else{
		x=0;
		rep(i,cnt[x]+1){
			if(cnt[x]>0&&i==0) continue;
			int sum = 0;
			ll y = 1;
			trav(i,v){
				sum+=i;
				y*=f[i];
			}
			ll pns= ans;
			ans+=(f[sum]/y)*C(sum+i-1,sum-1);
		}
	}
	return ;

}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	ll n;cin>>n;
	ll nn = n;
	while(nn){
		cnt[nn%10]++;
		nn/=10;
	}
	solve(1);
	cout<<ans;
	return 0;
}