#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

const int MAXN = 100005;
const int ALPHA = 52;
const int MOD = 1000000007;

int power(int x, int n) {
    int res = 1;
    while (n > 0) {
        if (n&1) res = (1LL*res*x)%MOD;
        x = (1LL*x*x)%MOD;
        n >>= 1;
    }
    return res;
}

char s[MAXN];
int n, q, freq[MAXN];
int fact[MAXN], invFact[MAXN];
int fl[ALPHA+2][MAXN], fr[ALPHA+2][MAXN], cnt[ALPHA+1][ALPHA+1];

int charToIdx(char c) {
    if (c >= 'a' && c <= 'z')
        return c-'a'+1;
    if (c >= 'A' && c <= 'Z')
        return c-'A'+27;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%s", s);
    n = strlen(s);

    fact[0] = invFact[0] = 1;
    fto(i, 1, n) {
        fact[i] = (1LL*fact[i-1]*i)%MOD;
        invFact[i] = power(fact[i], MOD-2);
    }

    fto(i, 0, n-1)
        ++freq[charToIdx(s[i])];

    fl[0][0] = 1;
    fto(c, 1, ALPHA) {
        fto(j, 0, n/2) {
            fl[c][j] = fl[c-1][j];
            if (freq[c] > 0 && j >= freq[c])
                fl[c][j] = (fl[c][j] + fl[c-1][j-freq[c]])%MOD;
        }
    }

    fto(c2, 1, ALPHA) {
        if (freq[c2] == 0) continue;

        fr[ALPHA+1][0] = 1;
        fdto(c, ALPHA, 0) {
            fto(j, 0, n/2) {
                fr[c][j] = fr[c+1][j];
                if (c != c2 && freq[c] > 0 && j >= freq[c])
                    fr[c][j] = (fr[c][j] + fr[c+1][j-freq[c]])%MOD;
            }
        }

        fto(c1, 1, c2-1) {
            int s = freq[c1] + freq[c2];
            if (freq[c1] == 0 || s > n/2)
                continue;
            fto(j, 0, n/2 - s)
                cnt[c1][c2] = (cnt[c1][c2] + 1LL*fl[c1-1][j]*fr[c1+1][n/2 - s - j])%MOD;
            fto(j, 0, n/2)
                cnt[c1][c2] = (cnt[c1][c2] + 1LL*fl[c1-1][j]*fr[c1+1][n/2 - j])%MOD;
            cnt[c2][c1] = cnt[c1][c2];
        }
    }

    int magic = power(fact[n/2], 2);
    fto(c, 1, ALPHA)
        magic = (1LL*magic*invFact[freq[c]])%MOD;

//    debug(magic);
//
//    fto(i, 0, n/2) {
//        fto(c, 1, ALPHA) printf("%d ", fl[c][i]);
//        puts("");
//    }

    scanf("%d", &q);

    fto(i, 1, q) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;

        int ans;
        if (s[x] == s[y])
            ans = (1LL*magic*fl[ALPHA][n/2])%MOD;
        else {
            int c1 = charToIdx(s[x]), c2 = charToIdx(s[y]);
            ans = (1LL*magic*cnt[c1][c2])%MOD;
        }
        printf("%d\n", ans);
    }


    return 0;
}