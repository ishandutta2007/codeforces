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

#define TASK "pocnitoare"

const int INF = 1e9 + 10;
const int MOD = 1e7 + 3;
const int P = 239017;
const long long BINF = 1e18 + 10;

_ vector<int> merge(vector<int> a, vector<int> b) {
    vector<int> res;
    int j = 0, jj = 0;
    for (int i = 0; i < int(a.size()) + int(b.size()); i++) {
        if (j == a.size()) {
            res.pb(b[jj]);
            jj++;
        }
        else if (jj == b.size()) {
            res.pb(a[j]);
            j++;
        }
        else if (a[j] < b[jj]) {
            res.pb(a[j]);
            j++;
        }
        else {
            res.pb(b[jj]);
            jj++;
        }
    }
    return res;
}

_ void source() {
    int n, m;
    cin >> n >> m;
    vector<int> cost(2 * n + 10), arr[2 * n + 10], pref[2 * n + 10];
    for (int i = 2; i <= n; i++) {
        cin >> cost[i];
    }
    for (int i = n; i >= 1; i--) {
        arr[i].pb(0);
        vector<int> arr2 = arr[i * 2];
        for (int j = 0; j < arr2.size(); j++) {
            arr2[j] += cost[i * 2];
        }
        arr[i] = merge(arr[i], arr2);
        arr2 = arr[i * 2 + 1];
        for (int j = 0; j < arr2.size(); j++) {
            arr2[j] += cost[i * 2 + 1];
        }
        arr[i] = merge(arr[i], arr2);
        pref[i].rsz(arr[i].size() + 1);
        pref[i][0] = 0;
        for (int j = 1; j <= arr[i].size(); j++) {
            pref[i][j] = pref[i][j - 1] + arr[i][j - 1];
        }
    }
    for (int i = 1; i <= m; i++) {
        int v, len;
        cin >> v >> len;
        int cur = 0, prev = 0, res = 0;
        while (v) {
            if (len > cur) {
                res += len - cur;
            }
            if (2 * v != prev) {
                int cnt = lower_bound(all(arr[2 * v]), len - cur - cost[2 * v]) - arr[2 * v].begin();
                if (cnt) res += (len - cur - cost[2 * v]) * cnt - pref[2 * v][cnt];
            }
            if (2 * v + 1 != prev) {
                int cnt = lower_bound(all(arr[2 * v + 1]), len - cur - cost[2 * v + 1]) - arr[2 * v + 1].begin();
                if (cnt) res += (len - cur - cost[2 * v + 1]) * cnt - pref[2 * v + 1][cnt];
            }
            cur += cost[v];
            prev = v;
            v /= 2;
            //cout << res << endl;
        }
        cout << res << endl;
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