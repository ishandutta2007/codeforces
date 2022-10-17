#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

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

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

_ void source() {
    int m, ans = 0;
    vector<int> arr;
    pair<int, int> cur;
    cin >> m;
    for (int i = 1; i <= 2e6; i++) {
        int a = i, a2 = i;
        while (a % 2 == 0) {
            a /= 2;
            cur.f++;
        }
        while (a2 % 5 == 0) {
            a2 /= 5;
            cur.sec++;
        }
        if (min(cur.f, cur.sec) == m) {
            ans++;
            arr.pb(i);
        }
    }
    cout << ans << endl;
    for (auto &it : arr) {
        cout << it << ' ';
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
    srand(time(0));
    source();
    return 0;
}