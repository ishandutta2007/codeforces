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

map<pair<string, string>, int> sum;

_ void source() {
    string prev;
    int n, a, b, cnt, cost;
    cin >> n >> a >> b >> cnt >> cost;
    for (int i = 1; i <= n; i++) {
        string s1, s2, s11, s22;
        cin >> s1 >> s2;
        s11 = s1;
        s22 = s2;
        if (s1 > s2) {
            swap(s1, s2);
        }
        if (s11 == prev) {
            sum[mk(s1, s2)] += b;
        }
        else {
            sum[mk(s1, s2)] += a;
        }
        prev = s22;
    }
    vector<int> res;
    for (auto it : sum) {
        res.pb(it.sec);
    }
    sort(rall(res));
    int cur = 0, ans = 0;
    for (int i = 0; i < res.size(); i++) {
        if (cur < cnt) {
            ans += min(res[i], cost);
        }
        else {
            ans += res[i];
        }
        cur++;
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