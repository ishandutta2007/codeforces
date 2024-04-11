#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

ll solve(int n, const string& s, const string& t) {
    vector<queue<int>> q(26);
    vector<int> fnw(n);

    for (int i = 0; i < n; ++i) {
        q[s[i] - 'a'].push(i);
        for (int j = i; j < n; j |= j + 1) {
            fnw[j]++;
        }
    }
    for (int d = 0; d < 26; ++d) q[d].push(n);

    auto sum = [&](int i) {
        int res = 0;
        for (; i >= 0; i = (i&i+1)-1) res += fnw[i];
        return res;
    };

    ll ans = numeric_limits<ll>::max();

    ll moves = 0;
    for (int i = 0; i < n; ++i) {
        int j_le = n;
        for (int k = 0; k < t[i] - 'a'; ++k) {
            ckmin(j_le, q[k].front());
        }

        int j_eq = q[t[i]-'a'].front();

        if (j_le != n) {
            ans = min(ans, moves + sum(j_le - 1));
        }

        if (j_le <= j_eq) break;

        moves += sum(j_eq - 1);
        for (int j = j_eq; j < n; j |= j + 1) fnw[j]--;
        q[t[i] - 'a'].pop();
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        ll res = solve(n, s, t);
        if (res == numeric_limits<ll>::max()) res = -1;
        cout << res << '\n';
    }
}