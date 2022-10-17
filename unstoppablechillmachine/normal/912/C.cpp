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

mt19937 Random((int)time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 1e5 + 10;

vector<pair<int, int> > arr[N];

int start_minus, increase;

_ int get(int time, int cnt) {
    return cnt * (start_minus + time * increase);
}

_ int gg(int a, int b) {
    return (b == 0 ? a : a / b);
}

_ void source() {
    int n, m, uron;
    cin >> n >> m;
    vector<int> regen(n + 1), al(n + 1);
    vector<pair<int, int> > change;
    cin >> start_minus >> increase >> uron;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b >> regen[i];
        if (uron >= a) {
            if (increase) {
                cout << -1;
                exit(0);
            }
            else {
                change.pb({0, -1});
                change.pb({INF, 1});
                al[i] = true;
            }
        }
        if (!regen[i]) {
            if (uron >= b && increase) {
                cout << -1;
                exit(0);
            }
        }
        arr[i].pb({0, b});
    }
    for (int i = 1; i <= m; i++) {
        int time, num, new_val;
        cin >> time >> num >> new_val;
        arr[num].pb(mk(time, new_val));
    }
    for (int i = 1; i <= n; i++) {
        if (al[i]) {
            continue;
        }
        sort(all(arr[i]));
        int l = 0;
        bool can = false;
        for (int j = 0; j < arr[i].size(); j++) {
            if (!can) {
                if (arr[i][j].second <= uron) {
                    can = true;
                    l = arr[i][j].first;
                }
                else {
                    continue;
                }
            }
            assert(arr[i][j].second <= uron);
            if (j + 1 >= arr[i].size()) {
                change.pb({l, -1});
                if (!regen[i]) {
                    if (increase) {
                        cout << -1;
                        exit(0);
                    }
                    else {
                        change.pb({INF, 1});
                    }
                }
                else {
                    change.pb({arr[i][j].first + (uron - arr[i][j].second) / regen[i], 1});
                }
                can = false;
            }
            else if  (arr[i][j].second + regen[i] * (arr[i][j + 1].first - arr[i][j].first - 1) > uron) {
                change.pb({l, -1});
                change.pb({arr[i][j].first + (uron - arr[i][j].second) / regen[i], 1});
                can = false;
            }
            else if (arr[i][j + 1].second > uron) {
                change.pb({l, -1});
                change.pb({arr[i][j + 1].f - 1, 1});
                can = false;
            }
        }
    }
    sort(all(change));
    int cnt = 0, ans = 0;
    for (auto it : change) {
        ans = max(ans, get(it.f, cnt));
        cnt -= it.sec;
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