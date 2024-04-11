#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int const maxn = 5010;
char T[maxn];
int nlen;
int RA[maxn], tempRA[maxn];
int SA[maxn], tempSA[maxn];
int c[maxn];
int Phi[maxn], PLCP[maxn];
int LCP[maxn];
void countingsort(int k) {
	int sum = 0, maxi = max(300, nlen);
	memset(c, 0, sizeof(c));
	FOR(i, 0, nlen) c[i + k < nlen ? RA[i + k] : 0]++;
	FOR(i, 0, maxi) {
		int t = c[i]; c[i] = sum; sum += t;
	}
	FOR(i, 0, nlen) tempSA[c[SA[i] + k < nlen ? RA[SA[i] + k] : 0]++] = SA[i];
	FOR(i, 0, nlen) SA[i] = tempSA[i];
}
void constructSA() {
	int r;
	FOR(i, 0, nlen) RA[i] = T[i];
	FOR(i, 0, nlen) SA[i] = i;
	for (int k = 1; k < nlen; k <<= 1) {
		countingsort(k);
		countingsort(0);
		tempSA[SA[0]] = r = 0;
		FOR(i, 1, nlen) tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
		FOR(i, 0, nlen) RA[i] = tempRA[i];
		if (RA[SA[nlen - 1]] == nlen - 1) break;
	}
}
void computeLCP() {
	int L = 0;
	Phi[SA[0]] = -1;
	FOR(i, 1, nlen) Phi[SA[i]] = SA[i - 1];
	FOR(i, 0, nlen) {
		if (Phi[i] == -1) {PLCP[i] = 0; continue;}
		while (T[i + L] == T[Phi[i] + L]) L++;
		PLCP[i] = L;
		L = max(L - 1, 0);
	}
	FOR(i, 0, nlen) LCP[i] = PLCP[SA[i]];
}

const int mod = 1000000007;
int nxt[maxn][maxn];
int f[maxn][maxn];
int g[maxn][maxn];
int h1[maxn][maxn];
int h2[maxn][maxn];

void add(bitset<maxn>& bt, int k) {
    int pos = 0;
    while (k) {
        int d = (k & 1) + bt[pos];
        bt[pos] = d & 1;
        k >>= 1;
        k += d >> 1;
        pos++;
    }
}

int compare(bitset<maxn> a, bitset<maxn> b) {
    FORd(i, maxn, 0) if (a[i] > b[i]) return 1; else if (a[i] < b[i]) return -1;
    return 0;
}

void solve() {
    ms(nxt, 0); ms(f, 0); ms(g, 0x3f);
    scanf("%s", T);
    nlen = strlen(T);
    T[nlen++] = '$';
    constructSA();
    computeLCP();
    FOR(i, 0, nlen) FOR(j, 1, nlen - i) {
        h1[i][j] = (1LL * h1[i][j - 1] * 2 + T[i + j - 1]) % mod;
        h2[i][j] = (0LL + h1[i][j - 1] + T[i + j - 1] * j) % mod;
    }
    FOR(i, 0, nlen) FOR(j, i, nlen) {
        int u = RA[i];
        int v = RA[j + 1];
        if (v > u) nxt[i][j] = 1;
        else if (h1[i][j - i + 1] == h1[j + 1][j - i + 1] && h2[i][j - i + 1] == h2[j + 1][j - i + 1]) nxt[i][j] = 1;
    }
    f[0][0] = g[0][0] = 1;
    FOR(i, 0, nlen) FOR(j, i, nlen) {
        f[i][j + 1] = (f[i][j + 1] + f[i][j]) % mod;
        g[i][j + 1] = min(g[i][j + 1], g[i][j]);
        if (T[j + 1] == '1') {
            if (nxt[i][j]) {
                f[j + 1][2 * j - i + 1] = (f[j + 1][2 * j - i + 1] + f[i][j]) % mod;
                g[j + 1][2 * j - i + 1] = min(g[j + 1][2 * j - i + 1], g[i][j] + 1);
            }
            else {
                f[j + 1][2 * j - i + 2] = (f[j + 1][2 * j - i + 2] + f[i][j]) % mod;
                g[j + 1][2 * j - i + 2] = min(g[j + 1][2 * j - i + 2], g[i][j] + 1);
            }
        }
    }
    int ans = 0; bitset<maxn> dmin, tmp; dmin.set();
    FOR(i, 0, nlen - 1) if (T[i] == '1') {
        ans = (ans + f[i][nlen - 2]) % mod;
        if (f[i][nlen - 2]) {
            tmp.reset();
            FORd(j, nlen - 1, i)
            if (T[j] == '1') tmp.set(nlen - j - 2);
            add(tmp, g[i][nlen - 2]);
            if (compare(dmin, tmp) == 1) dmin = tmp;
        }
    }
    int cnt = 0;
    FORd(i, maxn, 0) cnt = (2LL * cnt + dmin[i]) % mod;
    printf("%d\n%d", ans, cnt);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}