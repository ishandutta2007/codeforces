#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    int q;
    cin >> q;
    int a, b, l, r;
    string s;
    while (q--) {
        cin >> a >> b >> s;
        l = 0, r = 0;
        vector<int> v;
        while (l < s.size()) {
            if (s[l] == 'X') {
                l++;
                continue;
            }
            r = l + 1;
            while (r < s.size() && s[r] == '.')
                r++;
            v.emplace_back(r - l);
            l = r;
        }
        bool ok = true;
        int cnt = 0, id = -1;
        rep(i, 0, v.size()) {
            if (b <= v[i] && v[i] < a)
                ok = false;
            else if (2 * b <= v[i]) {
                if (id == -1)
                    id = i;
                else
                    ok = false;
            } else if (a <= v[i])
                cnt++;
        }
        if (!ok) {
            cout << "NO" << endl;
            continue;
        }
        if (id == -1) {
            if (cnt % 2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }
        ok = false;
        int sz = v[id];
        rep(r1, 0, sz - a + 1) {
            int r2 = sz - r1 - a;
            int ncnt = cnt;
            if (!((a <= r1 && r1 < 2 * b) || (r1 < b)))
                continue;
            if (!((a <= r2 && r2 < 2 * b) || (r2 < b)))
                continue;
            if (r1 >= a)
                ncnt++;
            if (r2 >= a)
                ncnt++;
            if (ncnt % 2 == 0)
                ok = true;
        }

        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}