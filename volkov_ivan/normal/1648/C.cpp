#include <bits/stdc++.h>
#define int long long

using namespace std;

const int M = 998244353;
const int N = 2e5 + 7;
int fact[N], rfact[N], cnt[N], s[N], t[N], f[N];

void upd(int pos, int val) {
    for (int i = pos; i < N; i += i & (-i))
        f[i] += val;
}

int get(int pos) {
    int sm = 0;
    for (int i = pos; i > 0; i -= i & (-i))
        sm += f[i];
    return sm;
}

int bpow(int a, int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return a % M;
    if (n % 2 == 0) {
        int mem = bpow(a, n / 2);
        return (mem * mem) % M;
    }
    return (bpow(a, n - 1) * a) % M;
}

int revv(int x) {
    return bpow(x, M - 2);
}

void init() {
    memset(f, 0, sizeof(f));
    memset(cnt, 0, sizeof(cnt));
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % M;
    rfact[N - 1] = revv(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--)
        rfact[i] = (rfact[i + 1] * (i + 1)) % M;
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    init();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        cnt[s[i]]++;
        upd(s[i], 1);
    }
    for (int i = 0; i < m; i++)
        cin >> t[i];
    int cf = fact[n];
    for (int i = 0; i < N; i++)
        cf = (cf * rfact[cnt[i]]) % M;
    int res = 0;
    for (int i = 0; i <= min(n, m - 1); i++) {
        if (i == n) {
            res = (res + 1) % M;
            break;
        }
        cf = (cf * revv(n - i)) % M;
        res += cf * get(t[i] - 1);
        res %= M;
        if (cnt[t[i]] == 0)
            break;
        cf = (cf * cnt[t[i]]) % M;
        cnt[t[i]]--;
        upd(t[i], -1);
    }
    cout << res << "\n";
}