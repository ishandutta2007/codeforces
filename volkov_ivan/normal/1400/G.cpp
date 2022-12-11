#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5 + 7, K = 20, X = 42, M = 998244353;
int cnk[X][X];
int fact[N], defact[N];
int dp[1 << K][X];
int sz[1 << K];
vector <int> op[N], cl[N];
pair <int, int> lr[N];
pair <int, int> bad[K];
bool has[N];
bool f[N], f2[N];

int bpow(int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a % M;
    if (n % 2 == 0) {
        int mem = bpow(a, n / 2);
        return (mem * mem) % M;
    }
    return (a * bpow(a, n - 1)) % M;
}

int obr(int x) {
    return bpow(x, M - 2);
}

void init() {
    memset(cnk, 0, sizeof(cnk));
    for (int n = 0; n < X; n++) {
        cnk[n][0] = 1;
        for (int k = 1; k <= n; k++) {
            cnk[n][k] = (cnk[n - 1][k] + cnk[n - 1][k - 1]) % M;
        }
    }
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % M;
    defact[N - 1] = obr(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        defact[i] = (defact[i + 1] * (i + 1)) % M;
    }
}

int get_cnk(int n, int k) {
    if (k > n) return 0;
    if (k < 0) return 0;
    if (n < X) return cnk[n][k];
    return (((fact[n] * defact[k]) % M) * defact[n - k]) % M;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(has, 0, sizeof(has));
    memset(dp, 0, sizeof(dp));
    memset(f, 0, sizeof(f));
    memset(f2, 0, sizeof(f2));
    init();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> lr[i].first >> lr[i].second;
        op[lr[i].first].push_back(i);
        cl[lr[i].second].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> bad[i].first >> bad[i].second;
        bad[i].first--;
        bad[i].second--;
    }
    dp[0][0] = 1;
    sz[0] = 0;
    for (int mask = 1; mask < (1 << m); mask++) {
        int pos = -1;
        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                pos = i;
                break;
            }
        }
        int nmask = 0, alone = 0, x = bad[pos].first, nmask2 = 0, alone2 = 0;
        set <signed> lol;
        vector <int> kek, kek2;
        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                if (bad[i].first != x && bad[i].second != x) {
                    nmask |= (1 << i);   
                    /*if (bad[i].first != y && bad[i].second != y) {
                        nmask2 |= (1 << i);
                    }*/
                }
                lol.insert(bad[i].first);
                lol.insert(bad[i].second);
                if (bad[i].first == x && !f[bad[i].second]) {
                    f[bad[i].second] = 1;
                    kek.push_back(bad[i].second);
                }
                if (bad[i].second == x && !f[bad[i].first]) {
                    f[bad[i].first] = 1;
                    kek.push_back(bad[i].first);
                }
                //if (bad[i].first == y && bad[i].second != x) kek2.insert(bad[i].second);
                //if (bad[i].second == y && bad[i].first != x) kek2.insert(bad[i].first);
            }
        }
        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                if (nmask & (1 << i)) {
                    if (!f[bad[i].first] && !f[bad[i].second]) nmask2 |= (1 << i);
                }
                if (f[bad[i].first] && bad[i].second != x && !f[bad[i].second] && !f2[bad[i].second]) {
                    f2[bad[i].second] = 1;
                    kek2.push_back(bad[i].second);
                }
                if (f[bad[i].second] && bad[i].first != x && !f[bad[i].first] && !f2[bad[i].first]) {
                    f2[bad[i].first] = 1;
                    kek2.push_back(bad[i].first);
                }
            }
        }
        for (int elem : kek) {
            bool flag = 0;
            for (int i = 0; i < m; i++) {
                if (nmask & (1 << i)) {
                    if (bad[i].first == elem || bad[i].second == elem) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (!flag) alone++;
        }
        for (auto elem : kek2) {
            bool flag = 0;
            for (int i = 0; i < m; i++) {
                if (nmask2 & (1 << i)) {
                    if (bad[i].first == elem || bad[i].second == elem) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (!flag) alone2++;
        }
        dp[mask][0] = 1;
        sz[mask] = lol.size();
        for (int i = 1; i < X; i++) {
            if (i > sz[mask]) break;
            for (int t = 0; t <= min(i, alone); t++) {
                dp[mask][i] = (dp[mask][i] + dp[nmask][i - t] * get_cnk(alone, t)) % M;
            }
            for (int t = 0; t <= min(i - 1, alone2); t++) {
                dp[mask][i] = (dp[mask][i] + dp[nmask2][i - t - 1] * get_cnk(alone2, t)) % M;
            }
        }
        for (int elem : kek) f[elem] = 0;
        for (int elem : kek2) f2[elem] = 0;
    }
    //cout << dp[1][0] << ' ' << dp[1][1] << ' ' << dp[1][2] << endl;
    int res = 0;
    int cnt = 0;
    for (int len = 1; len <= n; len++) {
        for (int elem : op[len]) {
            cnt++;
            has[elem] = 1;
        }
        int mask = 0;
        for (int i = 0; i < m; i++) {
            int x = bad[i].first, y = bad[i].second;
            if (has[x] && has[y]) mask |= (1 << i);
        }
        for (int t = 0; t <= min(X - 1, len); t++) {
            //cout << len << ' ' << t << ' ' << mask << ' ' << dp[mask][t] << ' ' << get_cnk(cnt - sz[mask], len - t) << endl;
            res = (res + dp[mask][t] * get_cnk(cnt - sz[mask], len - t)) % M;
        }
        for (int elem : cl[len]) {
            cnt--;
            has[elem] = 0;
        }
    }
    cout << res << endl;
}