#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}

const int maxn = 1000010;
int n;
int a[maxn];
int b[maxn];
ll sum[maxn];
pi tb[maxn];

void solve() {
	FOR(i, 0, maxn) tb[i] = mp(-1, -1);
	cin>>n;
	FOR(i, 0, n) {
		cin>>a[i];
		sum[i + 1] = sum[i] + a[i];
	}
	ll tot = 0;
	FOR(i, 0, n) {
		cin>>b[i];
		tot += b[i];
		int k = upper_bound(sum, sum + n + 1, tot) - sum - 1;
		if (tot == sum[k]) {
			cout<<k<<"\n";
			FOR(u, 1, k + 1) cout<<u<<" ";
			cout<<"\n";
			cout<<i + 1<<"\n";
			FOR(u, 0, i + 1) cout<<u + 1<<" ";
			return;
		}
		if (tb[tot - sum[k]] != mp(-1, -1)) {
			int j = tb[tot - sum[k]].fi;
			int l = tb[tot - sum[k]].se;
			cout<<k - l<<"\n";
			FOR(u, l + 1, k + 1) cout<<u<<" ";
			cout<<"\n";
			cout<<i - j<<"\n";
			FOR(u, j + 1, i + 1) cout<<u + 1<<" ";
			return;
		}
		tb[tot - sum[k]] = mp(i, k);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}