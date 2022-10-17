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

const int N = 2e5 + 10;

vector<int> ans1[N], ans2[N];

_ void source() {
    int h;
    bool t = false;
    cin >> h;
    h++;
    vector<int> arr(h + 1);
    for (int i = 1; i <= h; i++) {
        cin >> arr[i];
        if (arr[i] > 1 && arr[i - 1] > 1) {
            t = true;
        }
    }
    if (!t) {
        cout << "perfect";
        exit(0);
    }
    cout << "ambiguous" << endl;
    ans1[1].pb(1);
    cout << 0 << ' ';
    int cur = 2;
    for (int i = 2; i <= h; i++) {
        for (int j = 1; j <= arr[i]; j++) {
            cout << ans1[i - 1][0] << ' ';
            ans1[i].pb(cur);
            cur++;
        }
    }
    cout << endl;
    cout << 0 << ' ';
    ans2[1].pb(1);
    cur = 2;
    for (int i = 2; i <= h; i++) {
        cout << ans2[i - 1][0] << ' ';
        ans2[i].pb(cur);
        cur++;
        for (int j = 2; j <= arr[i]; j++) {
            cout << ans2[i - 1].back() << ' ';
            ans2[i].pb(cur);
            cur++;
        }
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
    srand(time(0));
    source();
    return 0;
}