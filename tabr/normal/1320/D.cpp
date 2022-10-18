#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct rollinghash {
    ll base1, base2, mod1, mod2;
    vector<ll> hash1, hash2, pow1, pow2;

    rollinghash(string s) {
        int n = s.size();
        base1 = 1009;
        base2 = 1007;
        mod1 = 1000000007;
        mod2 = 1000000009;
        hash1.assign(n + 1, 0);
        hash2.assign(n + 1, 0);
        pow1.assign(n + 1, 1);
        pow2.assign(n + 1, 1);

        for (int i = 0; i < n; i++) {
            hash1[i + 1] = (hash1[i] + s[i]) * base1 % mod1;
            hash2[i + 1] = (hash2[i] + s[i]) * base2 % mod2;
            pow1[i + 1] = pow1[i] * base1 % mod1;
            pow2[i + 1] = pow2[i] * base2 % mod2;
        }
    }

    pair<ll, ll> get(int l, int r) {
        ll t1 = ((hash1[r] - hash1[l] * pow1[r - l]) % mod1 + mod1) % mod1;
        ll t2 = ((hash2[r] - hash2[l] * pow2[r - l]) % mod2 + mod2) % mod2;
        return make_pair(t1, t2);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    string t;
    cin >> n >> t >> q;
    vector<string> s(2);
    vector<int> pos(n + 1);
    int id = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == '0') {
            id++;
            s[0].push_back('0' + i % 2);
            s[1].push_back('0' + (i + 1) % 2);
        }
        pos[i + 1] = id;
    }
    vector<rollinghash> rh = {rollinghash(s[0]), rollinghash(s[1])};
    while (q--) {
        int a, b, l;
        cin >> a >> b >> l;
        if (l < 3) {
            if (t.substr(a - 1, l) == t.substr(b - 1, l)) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
            continue;
        }
        int i = 0, j = (a % 2 != b % 2);
        if (rh[i].get(pos[a - 1], pos[a + l - 1]) == rh[j].get(pos[b - 1], pos[b + l - 1])) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
    return 0;
}