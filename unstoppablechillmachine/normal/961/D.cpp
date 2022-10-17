#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
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
//#define endl "\n"

#define right rightt
#define left leftt
#define next nextt
#define prev prevv

mt19937 Random(int(time(0)));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const ld EPS = 1e-6;

const int N = 1e5 + 10;
pair<int, int> arr[N];
int n;

_ bool check(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    pair<int, int> p1 = {b.f - a.f, b.sec - a.sec}, p2 = {b.f - c.f, b.sec - c.sec};
    return p1.f * p2.sec - p2.f * p1.sec == 0;
}

_ bool can(int ind1, int ind2) {
    vector<pair<int, int> > arr2;
    for (int i = 1; i <= n; i++) {
        if (!check(arr[ind1], arr[i], arr[ind2])) {
            arr2.pb(arr[i]);
        }
    }
    if (arr2.size() <= 2) {
        return true;
    }
    for (int i = 2; i < arr2.size(); i++) {
        if (!check(arr2[0], arr2[1], arr2[i])) {
            return false;
        }
    }
    return true;
}

_ void source() {
    cin >> n;
    if (n < 3) {
        cout << "YES";
        exit(0);
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].f >> arr[i].sec;
    }
    if (can(1, 2) || can(1, 3) || can(2, 3)) {
        cout << "YES";
    }
    else {
        cout << "NO";
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