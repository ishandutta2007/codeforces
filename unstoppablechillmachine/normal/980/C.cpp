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

const int N = 1e5 + 10;

int arr[N], used[512], to[512];
_ void source() {
    int n, k;
    cin >> n >> k;
    vector<int> ar;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (!used[arr[i]]) {
            used[arr[i]] = true;
            ar.pb(arr[i]);
        }
    }
    for (int i = 0; i < 256; i++) {
        to[i] = -1;
    }
    for (auto it : ar) {
        if (to[it] != -1) {
            continue;
        }
        int l = max(0, it - k + 1);
        for (int kek = l; kek <= it; kek++) {
            bool t = true;
            for (int i = kek; i <= it; i++) {
                if (to[i] != kek && to[i] != -1) {
                    t = false;
                    break;
                }
            }
            if (t) {
                for (int i = kek; i <= it; i++) {
                    to[i] = kek;
                }
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << to[arr[i]] << ' ';
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