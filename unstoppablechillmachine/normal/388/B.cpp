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

bool arr[1010][1010];

_ void source() {
    int n, v = 1, cnt = 2, dist = 0;
    cin >> n;
    vector<bool> pw;
    int n2 = n;
    while (n2 > 1) {
        pw.pb(n2 & 1);
        n2 >>= 1;
    }
    reverse(all(pw));
    for (auto it : pw) {
        arr[v][cnt + 1] = true;
        arr[v][cnt + 2] = true;
        arr[cnt + 1][cnt + 3] = true;
        arr[cnt + 2][cnt + 3] = true;
        cnt += 3;
        v = cnt;
        dist += 2;
        if (it & 1) {
            int prev = 1;
            for (int i = 1; i < dist; i++) {
                cnt++;
                arr[prev][cnt] = true;
                prev = cnt;
            }
            arr[prev][v] = true;
        }
    }
    assert(cnt <= 1000);
    arr[v][2] = true;
    cout << cnt << endl;
    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j <= cnt; j++) {
            bool c = max(arr[i][j], arr[j][i]);
            cout << (c ? 'Y' : 'N');
        }
        cout << endl;
    }
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    //freopen("input.txt", "r", stdin);
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