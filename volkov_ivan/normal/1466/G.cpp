#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 11e5 + 239, M = 1e9 + 7, NN = 1e6 + 1, K = 30, b = 239, M2 = 1e15 + 239;
int pref[N], suff[N], pow2[N];
signed preff_calc[K][N];
int obr2[N];
string kek;
int sz;

int bpow(int a, int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return a % M;
    if (n % 2 == 0) {
        int mem = bpow(a, n / 2);
        return (mem * mem) % M;
    }
    return (a * bpow(a, n - 1)) % M;
}

int obr(int x) {
    return bpow(x, M - 2);
}

void init(string &t) {
    int n = t.size();
    pow2[0] = 1;
    for (int i = 1; i < N; i++)
        pow2[i] = (pow2[i - 1] * 2) % M;
    obr2[N - 1] = obr(pow2[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        obr2[i] = (obr2[i + 1] * 2) % M;
    }
    assert(obr2[0] == 1);
    kek = "";
    for (int i = 0; i < (int) t.size(); i++) {
        if ((int) kek.size() > NN)
            break;
        kek = kek + t[i] + kek;
    }
    sz = kek.size();
    assert(sz < N);
    memset(pref, 0, sizeof(pref));
    memset(suff, 0, sizeof(suff));
    int cur_b = 1;
    for (int i = 1; i <= sz; i++) {
        pref[i] = (pref[i - 1] * b + kek[i - 1] - 'a' + 1) % M2;
        suff[i] = (suff[i - 1] + cur_b * (kek[sz - i] - 'a' + 1)) % M2;
        cur_b = (cur_b * b) % M2;
    }
    memset(preff_calc, 0, sizeof(preff_calc));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < K; j++) {
            preff_calc[j][i] = preff_calc[j][i - 1];
            if (t[i - 1] - 'a' == j) {
                preff_calc[j][i] = (preff_calc[j][i] + pow2[n - i]) % M;
            }
        }
    }
}

int get(int k, string &cur, string &t) {
    int ans = 0;
    int n = t.size();
    int nn = cur.size();
    int cur_pref[nn + 1];
    int cur_suff[nn + 1];
    cur_pref[0] = cur_suff[0] = 0;
    int cur_b = 1;
    for (int i = 1; i <= nn; i++) {
        cur_pref[i] = (cur_pref[i - 1] * b + cur[i - 1] - 'a' + 1) % M2;
        cur_suff[i] = (cur_suff[i - 1] + cur_b * (cur[nn - i] - 'a' + 1)) % M2;
        cur_b = (cur_b * b) % M2;
    }
    for (int i = 0; i < nn; i++) {
        if (cur_pref[i] == suff[i] && cur_suff[nn - i - 1] == pref[nn - i - 1]) {
            int llen = max(i, nn - i - 1); 
            int res = preff_calc[cur[i] - 'a'][k];
            for (int p = 1; p <= min(k, min(21ll, n)); p++) {
                int has = (1 << (p - 1)) - 1;
                if (has >= llen)
                    break;
                if (t[p - 1] == cur[i])
                    res = (res - pow2[n - p] + M) % M;
            }
            ans = (ans + res * obr2[n - k]) % M;
        }
    }
    return ans;
}

void solve(string &s0, string &t) {
    int k;
    string w;
    cin >> k >> w;
    int len = w.size(), s0_len = s0.size();
    int ans = 0;
    for (int shift = 0; shift <= s0_len; shift++) {
        string cur = "";
        int pos = shift;
        bool flag = 1;
        for (int i = 0; i < len; i++) {
            if (pos == s0_len) {
                cur += w[i];
                pos = -1;
            } else if (w[i] != s0[pos]) {
                flag = 0;
                break;
            }
            pos++;
        }
        if (!flag)
            continue;
        if (cur.empty()) {
            ans = (ans + pow2[k]) % M;
            continue;
        }
        ans = (ans + get(k, cur, t)) % M;
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    string s0, t;
    cin >> s0 >> t;
    init(t);
    for (int i = 0; i < q; i++)
        solve(s0, t);
}