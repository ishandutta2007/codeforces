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
struct FT {
		vector<ll> s;
			FT(int n) : s(n,0) {}
				void update(int pos, ll dif) { // a[pos] += dif
							for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
								}
					ll query(int pos) { // sum of values in [0, pos)
								ll res = 0;
										for (; pos > 0; pos &= pos - 1) res += s[pos-1];
												return res;
													}
						int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
									// Returns n if no sum is >= sum, or -1 if empty sum is.
									if (sum <= 0) return -1;
											int pos = 0;
													for (int pw = 1 << 25; pw; pw >>= 1) {
																	if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
																						pos += pw, sum -= s[pos-1];
																			}
															return pos;
																}
};
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	FT T(1e6+10);
	ll ans = 0;
	int nn = n;
	vi v;
	rep(i,n){
		int l;cin>>l;
		int mn = 1e6+10;
		int mx = 0;
		bool fg=0;
		rep(j,l){
			int x;cin>>x;
			if(x>mn) fg=1;
			mn=min(mn,x);
			mx=max(mx,x);
		}
		if(fg){
			ans+=2*nn-1;
			nn--;
		}
		else{
			T.update(mn,1);
			v.pb(mx);
		}
	}
	trav(i,v){
		ans+=T.query(i);
	}
	cout<<ans;
	
	return 0;
}