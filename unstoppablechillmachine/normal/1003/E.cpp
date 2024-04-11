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

_ void error() {
    cout << "NO";
    exit(0);
}

_ void source() {
    int n, d, k;
    cin >> n >> d >> k;
    if (n <= d) {
        error();
    }
    vector<int> dist1(n + 1), dist2(n + 1), st(n + 1);
    set<pair<int, int> > have;
    vector<pair<int, int> > ans;
    for (int i = 1; i <= d + 1; i++) {
        if (i <= d) {
            ans.pb({i, i + 1});
        }
        dist1[i] = i - 1;
        dist2[i] = d - dist1[i];
        if (i == 1 || i == d + 1) {
            st[i] = 1;
        }
        else {
            st[i] = 2;
        }
        if (st[i] > k) {
            error();
        }
        have.ins({max(dist1[i], dist2[i]), i});
    }
    int cur = d + 1;
    while (cur < n) {
        for (;;) {
            if (have.empty()) {
                error();
            }
            int ind = have.begin()->sec, dist = have.begin()->f;
            if (st[ind] == k || dist == d) {
                have.ers(have.begin());
                continue;
            }
            ans.pb({ind, cur + 1});
            st[ind]++;
            st[cur + 1] = 1;
            dist1[cur + 1] = dist1[ind] + 1;
            dist2[cur + 1] = dist2[ind] + 1;
            have.ins({max(dist1[cur + 1], dist2[cur + 1]), cur + 1});
            break;
        }
        cur++;
    }
    vector<int> nst(n + 1);
    for (auto it : ans) {
        nst[it.f]++;
        nst[it.sec]++;
    }
    for (int i = 1; i <= n; i++) {
        assert(nst[i] <= k);
    }
    cout << "YES" << endl;
    for (auto it : ans) {
        cout << it.f << ' ' << it.sec << '\n';
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