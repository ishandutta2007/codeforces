#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
//using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
#define next nextt
#define prev prevv

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const ld EPS = 1e-9;

_ void source() {
    map<int, int> cnt;
    map<int, set<int> > was;
    set<int> st;
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
        was[arr[i]].ins(i);
    }
    for (auto it : cnt) {
        if (it.sec > 1) {
            st.ins(it.f);
        }
    }
    while (!st.empty()) {
        int cur = *st.begin();
        cnt[cur] -= 2;
        was[cur].ers(was[cur].begin());
        int new_pos = *was[cur].begin();
        was[cur].ers(was[cur].begin());
        if (cnt[cur] < 2) {
            st.ers(cur);
        }
        cnt[2 * cur]++;
        was[2 * cur].ins(new_pos);
        if (cnt[2 * cur] >= 2) {
            st.ins(2 * cur);
        }
    }
    set<pair<int, int> > out;
    for (auto it : was) {
        for (auto it2 : it.sec) {
            out.ins({it2, it.f});
        }
    }
    cout << out.size() << endl;
    for (auto it : out) {
        cout << it.sec << ' ';
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