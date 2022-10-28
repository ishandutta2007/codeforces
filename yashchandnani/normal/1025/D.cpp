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

void pre(){


}

void solve(){


}
bitset<709> dp[709][709];
int a[709];
bool l[709][709],r[709][709],m[709][709];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) {
		cin>>a[i];
		l[i][0]=r[i][0] = 1;
		if(i>0&&__gcd(a[i],a[i-1])>1) r[i-1][1] = 1,l[i][1]=1;
		rep(j,i) m[j][i] = m[i][j] = (__gcd(a[i],a[j])>1);
		dp[i][i][i] = 1;
	}
	bool ans = 0;
	rep(j,n){
		repD(i,j-1,0){
			repA(k,i,j) {
				if(l[k][k-i]&&r[k][j-k]){
					dp[i][j][k]=1;
					if(i>0&&m[k][i-1]) r[i-1][j-i+1]=1;
					if(j<n-1&&m[k][j+1]) l[j+1][j-i+1]=1;
				}
			}
		}
	}
	rep(i,n) ans|= dp[0][n-1][i];
	if(ans) cout<<"Yes";
	else cout<<"No";
	return 0;
}