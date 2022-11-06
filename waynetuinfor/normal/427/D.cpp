#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int maxn = 5000 + 10, mod = 715827883, p = 101;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int ha[maxn], hb[maxn], pp[maxn];

inline void init(const string &s, int *a) {
    a[0] = s[0];
    for (int i = 1; i < s.length(); ++i) a[i] = add(mul(a[i - 1], p), s[i]);
}

inline int get_hash(int *a, int l, int r) {
    if (l == 0) return a[r];
    return sub(a[r], mul(pp[r - l + 1], a[l - 1]));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string a, b; cin >> a >> b;
    pp[0] = 1;
    for (int i = 1; i < maxn; ++i) pp[i] = mul(pp[i - 1], p);
    init(a, ha); init(b, hb);
    for (int ans = 1; ans <= a.length(); ++ans) {
        gp_hash_table<int, int> ma, mb;
        for (int i = 0; i < a.length(); ++i) {
            if (i + ans > a.length()) break;
            int h = get_hash(ha, i, i + ans - 1); 
            ++ma[h];
        }
        for (int i = 0; i < b.length(); ++i) {
            if (i + ans > b.length()) break;
            int h = get_hash(hb, i, i + ans - 1); 
            ++mb[h];
        }
        bool f = false;
        for (auto it = ma.begin(); it != ma.end(); ++it) {
            if (mb[it->first]) f = true;
            if (it->second > 1) continue;
            if (mb[it->first] == 1) return cout << ans << endl, 0;
        }
        if (!f) return cout << "-1" << endl, 0;
    }
    cout << "-1" << endl;
    return 0;
}