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
#define int ll
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
const long double PI = acos(-1);

_ void source() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n + 1), used(n + 1, 0), arr(m);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    vector<int> now, now2;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        if (!used[arr[i]]) {
            now.pb(arr[i]);
            used[arr[i]] = true;
        }
    }
    reverse(all(now));
    int ans = 0;
    for (auto it : arr) {
        //copy(all(now), ostream_iterator<int>(cout, " "));
        //cout << endl << ans << endl;
        while (now.back() != it) {
            ans += c[now.back()];
            now2.pb(now.back());
            now.pop_back();
        }
        now.pop_back();
        while (!now2.empty()) {
            now.pb(now2.back());
            now2.pop_back();
        }
        now.pb(it);
    }
    cout << ans;
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
    srand(time(0));
    source();
    return 0;
}