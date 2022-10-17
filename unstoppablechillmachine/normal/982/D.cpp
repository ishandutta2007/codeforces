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
//#define int ll
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

_ void source() {
    int n;
    cin >> n;
    vector<int> arr;
    map<int, vector<int> > pos;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        arr.pb(x);
        pos[x].pb(i);
    }
    sort(all(arr));
    arr.rsz(unique(all(arr)) - arr.begin());
    pair<int, int> ans;
    vector<int> lpar(n + 10), rpar(n + 10);
    multiset<int> lens;
    int cnt = 0;
    for (auto it : arr) {
        for (auto it2 : pos[it]) {
            if (lpar[it2 + 1] && rpar[it2 - 1]) {
                int l1 = rpar[it2 - 1], r1 = it2 - 1, l2 = it2 + 1, r2 = lpar[it2 + 1];
                lens.ers(lens.find(r1 - l1 + 1));
                lens.ers(lens.find(r2 - l2 + 1));
                lens.ins(r2 - l1 + 1);
                rpar[it2 - 1] = 0;
                lpar[it2 + 1] = 0;
                lpar[l1] = r2;
                rpar[r2] = l1;
                cnt--;
            }
            else if (lpar[it2 + 1]) {
                int l = it2 + 1, r = lpar[it2 + 1];
                lens.ers(lens.find(r - l + 1));
                lens.ins(r - l + 2);
                lpar[l] = 0;
                lpar[l - 1] = r;
                rpar[r] = l - 1;
            }
            else if (rpar[it2 - 1]) {
                int l = rpar[it2 - 1], r = it2 - 1;
                lens.ers(lens.find(r - l + 1));
                lens.ins(r - l + 2);
                lpar[l] = r + 1;
                rpar[r] = 0;
                rpar[r + 1] = l;
            }
            else {
                lens.ins(1);
                rpar[it2] = it2;
                lpar[it2] = it2;
                cnt++;
            }
        }
        if (cnt > ans.f && (*lens.begin() == *lens.rbegin())) {
            ans = {cnt, it + 1};
        }
    }
    cout << ans.sec;
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