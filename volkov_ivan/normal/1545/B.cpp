#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 7, M = 998244353;
int fact[N], obr[N];

int bpow(int n, int p) {
    if (p == 0)
        return 1;
    if (p == 1)
        return n % M;
    if (p % 2 == 0) {
        int mem = bpow(n, p / 2);
        return (mem * mem) % M;
    }
    return (bpow(n, p - 1) * n) % M;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % M;
    obr[N - 1] = bpow(fact[N - 1], M - 2);
    for (int i = N - 2; i >= 0; i--) {
        obr[i] = (obr[i + 1] * (i + 1)) % M;
    }
}

int cnk(int n, int k) {
    int res = fact[n];
    res = (res * obr[k]) % M;
    res = (res * obr[n - k]) % M;
    return res;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int nn = n - 1, k = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (i != n - 1 && s[i + 1] == '1') {
                k++;
            } else {
                nn--;    
            }
            i++;
        }
    }
    cout << cnk(nn - k + 1, k) << "\n";
}

signed main() {
    init();
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}