#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 2e5 + 10;
int hs[N][26], hs2[N][26], next[N][26], p_pow[N], p_pow2[N];

_ int get_hash(int l, int r, int letter) {
    return (hs[r][letter] - hs[l - 1][letter]) * p_pow[200000 - r];
}

_ int get_hash2(int l, int r, int letter) {
    return (((hs2[r][letter] - hs2[l - 1][letter] + 2 * MOD) % MOD) * p_pow2[200000 - r]) % MOD;
}

_ void source() {
    p_pow[0] = 1;
    p_pow2[0] = 1;
    for (int i = 1; i <= 2e5; i++) {
        p_pow[i] = p_pow[i - 1] * P;
        p_pow2[i] = (p_pow2[i - 1] * P) % MOD;
    }
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s.ins(s.begin(), ' ');
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            hs[i][j] = hs[i - 1][j];
            hs2[i][j] = hs2[i - 1][j];
            if (s[i] - 'a' == j) {
                hs[i][j] += p_pow[i];
                hs2[i][j] += p_pow2[i] % MOD;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        next[n + 1][i] = INF;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < 26; j++) {
            next[i][j] = next[i + 1][j];
            if (s[i] - 'a' == j) {
                next[i][j] = i;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        int l1, l2, len, r1, r2;
        cin >> l1 >> l2 >> len;
        r1 = l1 + len - 1;
        r2 = l2 + len - 1;
        vector<pair<int, int> > arr1, arr2;
        for (int j = 0; j < 26; j++) {
            arr1.pb({next[l1][j], j});
            arr2.pb({next[l2][j], j});
        }
        sort(all(arr1));
        sort(all(arr2));
        bool t = true;
        for (int j = 0; j < 26; j++) {
            if (get_hash2(l1, r1, arr1[j].sec) != get_hash2(l2, r2, arr2[j].sec) || get_hash(l1, r1, arr1[j].sec) != get_hash(l2, r2, arr2[j].sec)) {
                t = false;
                break;
            }
        }
        cout << (t ? "YES" : "NO") << endl;
    }
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    source();
    return 0;
}