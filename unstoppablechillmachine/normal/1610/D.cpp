#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int MOD = 1e9 + 7;
void add(int &a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) {
        a += MOD;
    }
    return a;
}

int mult(int a, int b) {
    return (a * 1ll * b) % MOD;
}

int b_pow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b & 1) {
        return mult(a, b_pow(a, b - 1));
    }
    return b_pow(mult(a, a), b / 2);
}

const int N = 2e5 + 10;
const int L = 31;
int dp[N][L][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> ch;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            ch.pb(x);
        }
    }
    int ans = mult(b_pow(2, SZ(ch)), sub(b_pow(2, n - SZ(ch)), 1));
    if (!ch.empty()) {
        auto get = [](int x) {
            int res = 0;
            while (x % (1 << (res + 1)) == 0) {
                res++;
            }
            return res;
        };
        for (int i = 0; i < SZ(ch); i++) {
            dp[i][get(ch[i])][1] = 1;
        }
        for (int i = 0; i + 1 < SZ(ch); i++) {
            int nxt = get(ch[i + 1]);
            for (int j = 0; j < L; j++) {
                for (int k = 0; k < 2; k++) {
                    if (nxt < j) {
                        add(dp[i + 1][nxt][1], dp[i][j][k]);
                    } else if (nxt == j) {
                        add(dp[i + 1][j][k ^ 1], dp[i][j][k]);
                    } else if (nxt > j) {
                        add(dp[i + 1][j][k], dp[i][j][k]);
                    }
                    add(dp[i + 1][j][k], dp[i][j][k]);
                }
            }
        }
        for (int j = 0; j < L; j++) {
            add(ans, dp[SZ(ch) - 1][j][0]);
        }
    }
    cout << ans << '\n';
}