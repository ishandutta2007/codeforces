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

_ int get(int x) {
    if (x < 2) {
        return x;
    }
    int res = 1;
    for (int i = 2; i <= sqrt(x); i++) {
        int cnt = 0;
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
        if (cnt & 1) {
            res *= i;
        }
    }
    if (x > 1) {
        res *= x;
    }
    return res;
}

int arr[5010], prev[5010], f[5010];

_ void source() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            arr[i] = -get(-arr[i]);
        }
        else {
            arr[i] = get(arr[i]);
        }
        //cout << arr[i] << ' ';
    }
    //cout << endl;
    for (int i = 1; i <= n; i++) {
        prev[i] = -1;
        for (int j = 1; j < i; j++) {
            if (arr[i] == arr[j]) {
                prev[i] = j;
            }
        }
    }
    for (int l = 1; l <= n; l++) {
        int ans = 0;
        for (int r = l; r <= n; r++) {
            if (!arr[r]) {
                f[max(ans, 1)]++;
            }
            else {
                if (prev[r] < l) {
                    ans++;
                }
                f[ans]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << f[i] << ' ';
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