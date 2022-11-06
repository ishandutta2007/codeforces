#include <bits/stdc++.h>
using namespace std;

const int maxn = 300 + 5;
const long long mods[] = { 479001599, 433494437, 1073807359, 1442968193, 715827883, 1000000087, 1000000123, 1000000009, 1000000007 };
const long long ps[] = { 101, 233, 457, 173, 211, 97, 839, 739, 1481 };
long long mod[2], p[2];
string s[maxn];
long long w[maxn], pf[maxn], pw[maxn];
int ln[maxn];

long long proc(string s) {
    long long h = 0;
    for (int i = 0; i < s.size(); ++i) {
        h = (h * p[0] % mod[0] + s[i]) % mod[0];
    }
    return h;
}

int main() {
    srand(time(nullptr));
    mod[0] = mods[rand() % 4 + 5], mod[1] = mods[rand() % 5];
    p[0] = ps[rand() % 4 + 5], p[1] = ps[rand() % 5];
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i], w[i] = proc(s[i]), ln[i] = (i ? ln[i - 1] : 0) + s[i].size();
    int ans = ln[n - 1] + n - 1;
    pf[0] = w[0];
    pw[0] = 1ll;
    for (int i = 1; i < n; ++i) pf[i] = (pf[i - 1] * p[1] % mod[1] + w[i]) % mod[1];
    for (int i = 1; i <= n; ++i) pw[i] = (pw[i - 1] * p[1]) % mod[1];
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int l = j - i + 1;
            long long a = i == 0 ? pf[j] : (pf[j] - pw[l] * pf[i - 1] % mod[1] + mod[1]) % mod[1];
            int c = 1;
            for (int k = j + 1; k + l <= n; ) {
                int t = k + l - 1;
                long long b = k == 0 ? pf[t] : (pf[t] - pw[l] * pf[k - 1] % mod[1] + mod[1]) % mod[1];
                if (a == b) {
                    ++c;
                    k += l;
                } else {
                    ++k;
                }
            }
            if (c >= 2) {
                for (int p = 2; p <= c; ++p) {
                    int tans = ln[n - 1] - (i == 0 ? ln[j] : ln[j] - ln[i - 1]) * p;
                    tans += l * p;
                    tans += (n - l * p) + p - 1;
                    ans = min(ans, tans);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}