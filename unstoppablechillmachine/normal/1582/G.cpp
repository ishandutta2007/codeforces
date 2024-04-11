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

const int N = 1e6 + 10;
int pr[N];
vector<pair<int, int>> factorization[N];
vector<int> st[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 2; i < N; i++) {
        if (!pr[i]) {
            pr[i] = i;
            if (i * 1ll * i < N) {
                for (int j = i * i; j < N; j += i) {
                    pr[j] = i;
                }
            }
        }
    }

    for (int i = 2; i < N; i++) {
        int cnt = 0, cur = i;
        while (cur % pr[i] == 0) {
            cur /= pr[i];
            cnt++;
        }
        factorization[i] = factorization[cur];
        factorization[i].emplace_back(pr[i], cnt);
    }

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;

    vector<int> prv(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            for (const auto &[divisor, cnt] : factorization[a[i]]) {
                for (int j = 0; j < cnt; j++) {
                    st[divisor].pb(i);
                }
            }
            prv[i] = i;
        } else {
            prv[i] = i;
            for (const auto &[divisor, cnt] : factorization[a[i]]) {
                for (int j = 0; j < cnt; j++) {
                    if (!st[divisor].empty()) {
                        prv[i] = min(prv[i], st[divisor].back());
                        st[divisor].pop_back();
                    } else {
                        prv[i] = -1;
                    }
                }
            }
        }
        //cerr << prv[i] << ' ';
    }
    //cerr << '\n';

    ll ans = 0;
    vector<pair<int, int>> bad = {{-1, n}};
    for (int i = n - 1; i >= 0; i--) {
        while (!bad.empty() && bad.back().F >= prv[i]) {
            bad.pop_back();
        }
        if (prv[i] < i) {
            bad.emplace_back(prv[i], i);
        }
        ans += bad.back().second - i;
    }
    cout << ans << '\n';
}