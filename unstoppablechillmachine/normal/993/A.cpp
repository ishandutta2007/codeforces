#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

//const int MAX_MEM = 1e8; int mpos = 0; char mem[MAX_MEM]; inline void * operator new ( size_t n ) { char *res = mem + mpos; mpos += n; assert(mpos <= MAX_MEM); return (void *)res; } inline void operator delete ( void * ) { }

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
ld EPS = 1e-9;

#define int ld

_ ld dist2(pair<int, int> a, pair<int, int> b) {
    return (a.f - b.f) * (a.f - b.f) + (a.sec - b.sec) * (a.sec - b.sec);
}

_ ld f(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int res = (b.f - a.f) * (c.sec - a.sec) - (b.sec - a.sec) * (c.f - a.f);
    return abs(ld(res)) / 2.0;
}

_ bool in(vector<pair<int, int> > arr, pair<int, int> point) {
    ld sqr1 = dist2(arr[0], arr[1]), sqr2 = 0;
    for (int i = 0; i < 4; i++) {
        sqr2 += f(arr[i], arr[ll(i + 1) % 4], point);
    }
    return sqr1 == sqr2;
}

_ void source() {
    vector<pair<int, int> > arr1(4), arr2(4);
    pair<int, int> left = {INF, INF}, right = {-INF, -INF};
    for (int i = 0; i < 4; i++) {
        cin >> arr1[i].f >> arr1[i].sec;
        left.f = min(left.f, arr1[i].f);
        left.sec = min(left.sec, arr1[i].sec);
        right.f = max(right.f, arr1[i].f);
        right.sec = max(right.sec, arr1[i].sec);
    }
    for (int i = 0; i < 4; i++) {
        cin >> arr2[i].f >> arr2[i].sec;
        if (arr2[i].f >= left.f && arr2[i].f <= right.f && arr2[i].sec >= left.sec && arr2[i].sec <= right.sec) {
            cout << "YES";
            exit(0);
        }
    }
    for (int i = 0; i < 4; i++) {
        if (in(arr2, arr1[i])) {
            cout << "YES";
            exit(0);
        }
    }
    for (int i = 0; i < 4; i++) {
        if (in(arr1, arr2[i])) {
            cout << "YES";
            exit(0);
        }
    }
    pair<int, int> mid = {(left.f + right.f) / 2.0, (right.sec + left.sec) / 2.0};
    if (in(arr2, mid)) {
        cout << "YES";
        exit(0);
    }
    cout << "NO";
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