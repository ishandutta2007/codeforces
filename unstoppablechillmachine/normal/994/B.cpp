//I_l_M_P
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

struct person {
    int f, sec, num;
};

bool cmp(person a, person b) {
    return a.f < b.f || (a.f == b.f && a.sec < b.sec);
}

_ void source() {
    int n, k;
    cin >> n >> k;
    vector<person> arr(n);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i - 1].f;
        arr[i - 1].num = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i - 1].sec;
        ans[i] = arr[i - 1].sec;
    }
    sort(all(arr), cmp);
    multiset<int> cur;
    int sum = 0;
    for (int i = 1; i < n; i++) {
        int it = arr[i - 1].sec;
        if (cur.size() < k) {
            cur.ins(it);
            sum += it;
        }
        else if (k && it > *cur.begin()) {
            sum += it - *cur.begin();
            cur.ers(cur.begin());
            cur.ins(it);
        }
        ans[arr[i].num] += sum;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
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