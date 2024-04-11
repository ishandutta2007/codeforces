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

const int N = 300;

int n, m, used[N][N], sum[N][N];
bool arr[N][N];
queue<pair<pair<int, int>, int> > q;
_ void go(pair<int, int> cur, int now, pair<int, int> d, int timer) {
    if (cur.f + d.f < 1 || cur.f + d.f > n) {
        return;
    }
    if (cur.sec + d.sec < 1 || cur.sec + d.sec > m) {
        return;
    }
    if (used[cur.f + d.f][cur.sec + d.sec] != timer && !arr[cur.f + d.f][cur.sec + d.sec]) {
        used[cur.f + d.f][cur.sec + d.sec] = timer;
        q.push(mk(mk(cur.f + d.f, cur.sec + d.sec), now / 2));
    }
}

int get(int a, int b) {
    return a * (m + 1) + b;
}

pair<int, int> get2(int a) {
    return mk(a / (m + 1), a % (m + 1));
}

_ void source() {
    vector<pair<int, int> > delta;
    vector<pair<int, int> > arr2(N * N + 10);
    delta.pb(mk(1, 0));
    delta.pb(mk(-1, 0));
    delta.pb(mk(0, 1));
    delta.pb(mk(0, -1));
    int k, p, cnt = 0;
    cin >> n >> m >> k >> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            if (ch == '*') {
                arr[i][j] = 1;
            }
            else if (ch >= 'A' && ch <= 'Z') {
                cnt++;
                arr2[cnt] = mk(get(i, j), ch - 'A' + 1);
            }
        }
    }
    for (int i = 1; i <= cnt; i++) {
        pair<int, int> cur = get2(arr2[i].f);
        int now = arr2[i].sec * k;
        //cout << now << endl;
        used[cur.f][cur.sec] = i;
        q.push(mk(cur, now));
        while (!q.empty()) {
            pair<int, int> cur = q.front().f;
            int now = q.front().sec;
            q.pop();
            sum[cur.f][cur.sec] += now;
            if (now == 1) {
                continue;
            }
            for (int j = 0; j < 4; j++) {
                go(cur, now, delta[j], i);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //cout << sum[i][j] << ' ';
            if (sum[i][j] > p) {
                ans++;
            }
        }
        //cout << endl;
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