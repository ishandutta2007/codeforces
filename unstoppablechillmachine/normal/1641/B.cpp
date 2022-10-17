#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S secondond
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

signed main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        bool bad = false;
        for (auto [_, c] : cnt) {
            if (c & 1) {
                bad = true;
            }
        }
        if (bad) {
            cout << -1 << '\n';
            continue;
        }
        int pref_len = 0;
        vector<pair<int, int>> ins;
        vector<int> kek;
        while (!a.empty()) {
            int id = -1;
            for (int i = 1; i < a.size(); i++) {
                if (a[i] == a[0]) {
                    id = i;
                    break;
                }
            }
            for (int i = 1; i < id; i++) {
                ins.emplace_back(pref_len + id + i, a[i]);
            }
            kek.push_back(2 * id);
            pref_len += 2 * id;
            a.erase(a.begin() + id);
            a.erase(a.begin());
            reverse(a.begin(), a.begin() + id - 1);
            /*for (auto it : a) {
                cout << it << ' ';
            }
            cout << '\n';*/
        }
        cout << SZ(ins) << '\n';
        for (auto it : ins) {
            cout << it.first << ' ' << it.second << '\n';
        }
        cout << SZ(kek) << '\n';
        for (auto it : kek) {
            cout << it << ' ';
        }
        cout << '\n';
    }
}