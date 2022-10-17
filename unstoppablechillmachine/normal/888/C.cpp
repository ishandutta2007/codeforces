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
#define endl "\n"

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 26;
vector<int> arr[N];

_ void source() {
    for (int i = 0; i < 26; i++) {
        arr[i].pb(0);
    }
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        arr[s[i] - 'a'].pb(i + 1);
    }
    for (int i = 0; i < 26; i++) {
        arr[i].pb(int(s.size()) + 1);
    }
    int ans = INF;
    for (int i = 0; i < 26; i++) {
        int cur = 0;
        for (int j = 0; j + 1 < arr[i].size(); j++) {
            cur = max(cur, arr[i][j + 1] - arr[i][j]);
        }
        ans = min(ans, cur);
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