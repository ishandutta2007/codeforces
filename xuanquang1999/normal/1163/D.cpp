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

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a%b);
}

const int MAXN = 1005;
const int MAXM = 55;
const int oo = 1e9;

int getP(string s, string t) {
    for(int len = min(s.length(), t.length()); len >= 0; --len)
        if (s.substr(0, len) == t.substr(t.length() - len))
            return len;
}

void getNxt(string s, int nxt[][26]) {
    for(int len = 0; len <= s.length(); ++len) {
        for(int c = 0; c < 26; ++c) {
            string t = s.substr(0, len);
            t += c + 'a';
            nxt[len][c] = getP(s, t);
        }
    }

//    cout << s << endl;
//    for(int len = 0; len <= s.length(); ++len) {
//        for(int c = 0; c < 26; ++c)
//            printf("%d ", nxt[len][c]);
//        puts("");
//    }
}

int n, dp[MAXN][MAXM][MAXM], nxtS[MAXM][26], nxtT[MAXM][26];
string p, s, t;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> p;
    cin >> s;
    cin >> t;

    getNxt(s, nxtS);
    getNxt(t, nxtT);

    for(int i = 0; i <= p.length(); ++i)
        for(int j = 0; j <= s.length(); ++j)
            for(int k = 0; k <= t.length(); ++k)
                dp[i][j][k] = -oo;
    dp[0][0][0] = 0;

    for(int i = 0; i < p.length(); ++i) {
        for(int j = 0; j <= s.length(); ++j) {
            for(int k = 0; k <= t.length(); ++k) {
                for(char c = 0; c < 26; ++c) {
                    if (p[i] != '*' && p[i] != c+'a')
                        continue;
                    int J = nxtS[j][c], K = nxtT[k][c], x = dp[i][j][k];
                    if (J == s.length())
                        ++x;
                    if (K == t.length())
                        --x;
                    dp[i+1][J][K] = max(dp[i+1][J][K], x);
                }
            }
        }
    }

    int ans = -oo;
    for(int j = 0; j <= s.length(); ++j)
        for(int k = 0; k <= t.length(); ++k)
            ans = max(ans, dp[p.length()][j][k]);

    cout << ans;

    return 0;
}