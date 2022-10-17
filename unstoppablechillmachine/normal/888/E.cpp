#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

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
#define endl "\n"

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

_ void source() {
    int n, m, a;
    vector<int> arr1, arr2;
    cin >> n >> m;
    for (int i = 1; i <= n / 2; i++) {
        cin >> a;
        arr1.pb(a);
    }
    for (int i = n / 2 + 1; i <= n; i++) {
        cin >> a;
        arr2.pb(a);
    }
    int lim = 1 << (arr1.size()), cnt = arr1.size();
    set<int> st1, st2;
    for (int i = 0; i < lim; i++) {
        int sum = 0;
        for (int j = 0; j < cnt; j++) {
            if ((i >> j) & 1) {
                sum += arr1[j];
            }
        }
        st1.ins(sum % m);
    }
    cnt = arr2.size();
    lim = 1 << cnt;
    for (int i = 0; i < lim; i++) {
        int sum = 0;
        for (int j = 0; j < cnt; j++) {
            if ((i >> j) & 1) {
                sum += arr2[j];
            }
        }
        st2.ins(sum % m);
    }
    int ans = 0;
    for (auto it : st1) {
        auto it2 = --st2.lower_bound(m - it);
        ans = max(ans, it + *it2);
    }
    cout << ans;
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
    srand(time(0));
    source();
    return 0;
}