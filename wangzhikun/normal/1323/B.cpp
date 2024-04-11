#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;

vector<ll> gao(vector<int> a) {
    int n = a.size();
    vector<ll> res(n + 1);
    int i = 0;
    while (i < n) {
        if (a[i] == 0) {
            i++;
            continue;
        }

        int j = i;
        while (j < n && a[j] == 1) {
            j++;
        }
        for (int len = 1; len <= j - i; len++) {
            res[len] += j - i - len + 1;
        }
        i = j;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int& x : a) {
        cin >> x;
    }
    for (int& x : b) {
        cin >> x;
    }

    ll ans = 0;

    auto ga = gao(a);
    auto gb = gao(b);
    for (int i = 1; i < ga.size(); i++) {
        if (k % i == 0 && k / i <= m) {
            ans += ga[i] * gb[k / i];
        }
    }

    cout << ans << "\n";
    return 0;
}