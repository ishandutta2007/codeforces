#include <iostream>
// #include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
// #include <unordered_map>
#include <map>
#include <queue>
#include <set>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define File(a) freopen(a".in", "r", stdin), freopen(a".out", "w", stdout)
#define rep(i, j) for ( int i = 0, i##_end_ = (j); i < i##_end_; ++ i)
#define For(i, j, k) for ( int i = (j), i##_end_ = (k); i <= i##_end_; ++ i)
#define Fordown(i, j, k) for ( int i = (j), i##_end_ = (k); i >= i##_end_; -- i)
#define Set(a, b) memset(a, b, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(a))
#define fir first
#define sec second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) ((int)(a).size())
#define INF (0x3f3f3f3f)
#define INF1 (2139062143)
#define Mod (998244353)
#define g0 (3)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define y1 wozenmezhemecaia

template <typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline bool chkmin(T &a, T b) { return b < a ? a = b, 1 : 0; }

inline LL Pow(LL a, LL b)
{
    LL Ans = 1;
    for ( ; b; b >>= 1, (a *= a) %= Mod) if (b & 1) (Ans *= a) %= Mod;
    return Ans;
}	

const int maxn = 2960000;

LL n, fac[maxn], ifac[maxn];
int S[maxn];
LL powg[maxn], invg[maxn];
int k, N, rev[maxn], cnt;

int ccc = 0;

inline void NTT(int* a, bool type)
{
	ccc += N;
    rep(i, N) if (rev[i] > i) swap(a[i], a[rev[i]]);
    for (int i = 2; i <= N; i <<= 1) {
        LL wn = type ? powg[i] : invg[i];
        for (int j = 0; j < N; j += i) {
            int w = 1;
            for (int k = j; k < j + (i >> 1); k++) {
                int x = a[k], y = 1LL * a[(i >> 1) + k] * w % Mod;
                a[k] = (x + y);
                if (a[k] > Mod)
                	a[k] -= Mod;
                a[(i >> 1) + k] = (x - y + Mod);
                if (a[(i >> 1) + k] > Mod)
                	a[(i >> 1) + k] -= Mod;
                w = 1LL * wn * w % Mod;
                // (w *= wn) %= Mod;
            }
        }
    }	
    if (!type) {
        LL invn = Pow(N, Mod - 2);
        rep(i, N) a[i] = 1LL * a[i] * invn % Mod;//(a[i] *= invn) %= Mod;
    }
}

int aaa[maxn], bbb[maxn];

void calc(int A, int B) {
    for (int i = 1; i <= n; i++)
    	S[i] = 1LL * fac[i - 1] * ifac[i] % Mod;
    A --;
    B--;
    // memset(aaa, 0, sizeof aaa);
    aaa[0] = 1;
    bbb[0] = 1;
    for (int i = 1; i <= max(A, B); i *= 2) {

    	

    	NTT(S, 1);
    	if (i & A) {
    		NTT(aaa, 1);
    		rep (j, N) aaa[j] = 1LL * aaa[j] * S[j] % Mod;
    		NTT(aaa, 0);
    		for (int j = n + 1; j < N; j++)
    			aaa[j] = 0;
    	}

    	if (i & B) {
    		NTT(bbb, 1);
    		rep (j, N) bbb[j] = 1LL * bbb[j] * S[j] % Mod;
    		NTT(bbb, 0);
    		for (int j = n + 1; j < N; j++)
    			bbb[j] = 0;

    	}
    	rep(j, N) S[j] = 1LL * S[j] * S[j] % Mod;
    	NTT(S, 0);
    	for (int j = n + 1; j < N; j++)
    		S[j] = 0;

    }
    for (int i = 0; i < N; i++)
    	aaa[i] = 1LL * aaa[i] * fac[i] % Mod * ifac[A] % Mod;
    for (int i = N - 1; i > 0; i--)
    	aaa[i] = aaa[i - 1];
    for (int i = 0; i < N; i++)
    	bbb[i] = 1LL * bbb[i] * fac[i] % Mod * ifac[B] % Mod;
    for (int i = N - 1; i > 0; i--)
    	bbb[i] = bbb[i - 1];
}


int C(int x, int y) {
	if (y > x)
		return 0;
	else
		return 1LL * fac[x] * ifac[y] % Mod * ifac[x - y] % Mod;
}

int main()
{
	int A, B;
	scanf("%d%d%d", &n, &A, &B);
	if (A == 0 || B == 0 || A + B > n + 1) {
		printf("0\n");
		return 0;
	}
    for (N = 1; N < (n << 1); N <<= 1, ++ cnt) ;

    fac[0] = 1;

    For(i, 1, N) fac[i] = fac[i - 1] * i % Mod;
    ifac[N] = Pow(fac[N], Mod - 2);
    Fordown(i, N, 1) ifac[i - 1] = ifac[i] * i % Mod;

    int invg0 = Pow(g0, Mod - 2);
    for (int i = 1; i <= N; i <<= 1)
        powg[i] = Pow(g0, (Mod - 1) / i), invg[i] = Pow(invg0, (Mod - 1) / i);
    rep(i, N) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (cnt - 1));

    calc(A, B);
    // calc(B, bbb);


    int ans = 0;
    for (int j = 1; j <= n; j++)
		ans = (ans + 1LL * aaa[j] * bbb[n - j + 1] % Mod * C(n - 1, j - 1)) % Mod;
	printf("%d\n", (ans + Mod) % Mod);
    // for (int i = 1; i <= n; i++)
    // 	printf("%d ", aaa[i]);
    // printf("\n");
    // printf("%d\n", ccc);
    return 0;
}