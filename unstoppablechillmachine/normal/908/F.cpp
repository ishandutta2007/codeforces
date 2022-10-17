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
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const long long BINF = 1e18 + 10;

const int N = 3e5 + 10;

deque<int> arr_r, arr_b;
vector<int> arr_g, before_r[N], before_b[N];

_ int get_sum(deque<int> arr) {
    return (arr.empty() ? 0 : arr.back() - arr.front());
}

_ int get_max(vector<int> arr) {
    int res = 0;
    for (int i = 1; i < arr.size(); i++) {
        res = max(res, arr[i] - arr[i - 1]);
    }
    return res;
}

_ void source() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int pos;
        char ch;
        cin >> pos >> ch;
        if (ch == 'R') {
            arr_r.pb(pos);
        }
        else if (ch == 'G') {
            arr_g.pb(pos);
        }
        else {
            arr_b.pb(pos);
        }
    }
    if (arr_g.empty()) {
        if (!arr_r.empty()) {
            ans += get_sum(arr_r);
        }
        if (!arr_b.empty()) {
            ans += get_sum(arr_b);
        }
        cout << ans;
        exit(0);
    }
    if (!arr_r.empty() && arr_r.front() <= arr_g.front()) {
        ans += arr_g.front() - arr_r.front();
        while (!arr_r.empty() && arr_r.front() <= arr_g.front()) {
            arr_r.pop_front();
        }
    }
    if (!arr_b.empty() && arr_b.front() <= arr_g.front()) {
        ans += arr_g.front() - arr_b.front();
        while (!arr_b.empty() && arr_b.front() <= arr_g.front()) {
            arr_b.pop_front();
        }
    }
    if (!arr_r.empty() && arr_r.back() >= arr_g.back()) {
        ans += arr_r.back() - arr_g.back();
        while (!arr_r.empty() && arr_r.back() >= arr_g.back()) {
            arr_r.pop_back();
        }
    }
    if (!arr_b.empty() && arr_b.back() >= arr_g.back()) {
        ans += arr_b.back() - arr_g.back();
        while (!arr_b.empty() && arr_b.back() >= arr_g.back()) {
            arr_b.pop_back();
        }
    }
    for (int i = 1; i < arr_g.size(); i++) {
        while (!arr_r.empty() && arr_r.front() <= arr_g[i]) {
            before_r[i].pb(arr_r.front());
            arr_r.pop_front();
        }
        while (!arr_b.empty() && arr_b.front() <= arr_g[i]) {
            before_b[i].pb(arr_b.front());
            arr_b.pop_front();
        }
        if ((!before_b[i].empty() && before_r[i].empty()) || (before_b[i].empty() && !before_r[i].empty())) {
            ans += arr_g[i] - arr_g[i - 1];
            if (!before_b[i].empty()) {
                int mx = max(get_max(before_b[i]), max(before_b[i].front() - arr_g[i - 1], arr_g[i] - before_b[i].back()));
                ans += arr_g[i] - arr_g[i - 1] - mx;
            }
            if (!before_r[i].empty()) {
                int mx = max(get_max(before_r[i]), max(before_r[i].front() - arr_g[i - 1], arr_g[i] - before_r[i].back()));
                ans += arr_g[i] - arr_g[i - 1] - mx;
            }
        }
        else {
            ans += arr_g[i] - arr_g[i - 1];
            int sum = 0;
            if (!before_b[i].empty()) {
                int mx = max(get_max(before_b[i]), max(before_b[i].front() - arr_g[i - 1], arr_g[i] - before_b[i].back()));
                sum += arr_g[i] - arr_g[i - 1] - mx;
            }
            if (!before_r[i].empty()) {
                int mx = max(get_max(before_r[i]), max(before_r[i].front() - arr_g[i - 1], arr_g[i] - before_r[i].back()));
                sum += arr_g[i] - arr_g[i - 1] - mx;
            }
            ans += min(arr_g[i] - arr_g[i - 1], sum);
        }
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