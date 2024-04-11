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
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int MAXN = 600010;
char T[MAXN];
int nlen;
int RA[MAXN], tempRA[MAXN];
int SA[MAXN], tempSA[MAXN];
int c[MAXN];
int Phi[MAXN], PLCP[MAXN];
int LCP[MAXN];
void countingsort(int k) {
	int sum = 0, maxi = max(300, nlen);
	memset(c, 0, sizeof(c));
	for (int i = 0; i < nlen; i++) c[i + k < nlen ? RA[i + k] : 0]++;
	for (int i = 0; i < maxi; i++) {
		int t = c[i]; c[i] = sum; sum += t;
	}
	for (int i = 0; i < nlen; i++) tempSA[c[SA[i] + k < nlen ? RA[SA[i] + k] : 0]++] = SA[i];
	for (int i = 0; i < nlen; i++) SA[i] = tempSA[i];
}
void constructSA() {
	int r;
	for (int i = 0; i < nlen; i++) RA[i] = T[i];
	for (int i = 0; i < nlen; i++) SA[i] = i;
	for (int k = 1; k < nlen; k <<= 1) {
		countingsort(k);
		countingsort(0);
		tempSA[SA[0]] = r = 0;
		for (int i = 1; i < nlen; i++) tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
		for (int i = 0; i < nlen; i++) RA[i] = tempRA[i];
		if (RA[SA[nlen - 1]] == nlen - 1) break;
	}
}
void computeLCP() {
	int L = 0;
	Phi[SA[0]] = -1;
	for (int i = 1; i < nlen; i++) Phi[SA[i]] = SA[i - 1];
	for (int i = 0; i < nlen; i++) {
		if (Phi[i] == -1) {PLCP[i] = 0; continue;}
		while (T[i + L] == T[Phi[i] + L] && T[i + L] != '$') L++;
		PLCP[i] = L;
		L = max(L - 1, 0);
	}
	for (int i = 0; i < nlen; i++) LCP[i] = PLCP[SA[i]];
}

const int maxn = 600010;
int n;
string t[maxn];
int cost[maxn];
int pos[maxn];
int COST[maxn];
int maxlen[maxn];
int MAXLEN[maxn];
ll SUMCOST[maxn];

int st[4 * maxn];
void build(int node, int L, int R) {
	if (L == R) {st[node] = LCP[L]; return;}
	build(node << 1, L, (L + R) >> 1);
	build((node << 1) + 1, ((L + R) >> 1) + 1, R);
	st[node] = min(st[node << 1], st[(node << 1) + 1]);
}
int query(int node, int l, int r, int L, int R) {
	if (l > R || r < L) return INF;
	if (l <= L && r >= R) return st[node];
	return min(query(node << 1, l, r, L, (L + R) >> 1), query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R));
}

ll calc(int l, int r) {
	if (!l) return SUMCOST[r];
	return SUMCOST[r] - SUMCOST[l - 1];
}

void solve() {
	ms(pos, -1);
	cin>>n;
	FOR(i, 0, n) {
		cin>>t[i];
		FOR(j, 0, sz(t[i])) {
			pos[nlen] = i;
			maxlen[nlen] = sz(t[i]) - j;
			T[nlen++] = t[i][j];
		}
		T[nlen++] = '$';
	}
	FOR(i, 0, n) cin>>cost[i];
	constructSA(); computeLCP();
	FOR(i, 0, nlen) {
		if (~pos[i]) {
			COST[RA[i]] = cost[pos[i]];
			MAXLEN[RA[i]] = maxlen[i];
		}
	}
	FOR(i, 0, nlen) {
		if (!i) SUMCOST[i] = COST[i];
		else SUMCOST[i] = SUMCOST[i - 1] + COST[i];
	}
	build(1, 0, nlen - 1);
	ll ans = 0;
	FOR(i, 1, nlen) {
		if (!LCP[i] && (i == nlen - 1 || !LCP[i + 1])) {
			ans = max(ans, MAXLEN[i] * calc(i, i));
			continue;
		}
		int l = i, r = nlen - 1;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (query(1, i, mid, 0, nlen - 1) >= LCP[i]) l = mid; else r = mid - 1;
		}
		int R = l;
		l = 0, r = i;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (query(1, mid, i, 0, nlen - 1) < LCP[i]) l = mid + 1; else r = mid;
		}
		int L = l;
		ans = max(ans, LCP[i] * calc(L - 1, R));
		if (MAXLEN[i] > LCP[i] && (i == nlen - 1 || MAXLEN[i] > LCP[i + 1])) ans = max(ans, MAXLEN[i] * calc(i, i));
	}
	cout<<ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}