#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,unroll-loops")
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

struct segment {
    int first, second, num;
};

bool cmp(segment a, segment b) {
    return a.f < b.f || (a.f == b.f && a.sec > b.sec);
}

_ void source() {
    int n;
    cin >> n;
    vector<segment> arr(n);
    int cnt = 0;
    for (auto &it : arr) {
        cin >> it.f >> it.sec;
        cnt++;
        it.num = cnt;
    }
    sort(all(arr), cmp);
    arr.ins(arr.begin(), {0, 0, 0});
    vector<pair<int, int> > suf(n + 2);
    suf[n + 1] = {INF, INF};
    for (int i = n; i >= 1; i--) {
        suf[i] = min(suf[i + 1], {arr[i].sec, arr[i].num});
        if (suf[i + 1].f <= arr[i].sec) {
            cout << suf[i + 1].sec << ' ' << arr[i].num;
            exit(0);
        }
    }
    cout << "-1 -1";
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