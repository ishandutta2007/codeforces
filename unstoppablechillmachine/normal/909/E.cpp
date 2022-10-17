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

mt19937 Random((int)time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 1e5 + 10;

int cnt[N], arr[N];
set<pair<int, int> > st0, st1;
vector<int> p[N];
_ void source() {
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        p[b].pb(a);
    }
    for (int i = 0; i < n; i++) {
        if (arr[i]) {
            st0.ins(mk(cnt[i], i));
        }
        else {
            st1.ins(mk(cnt[i], i));
        }
    }
    while (!st0.empty()) {
        ans++;
        while (!st1.empty() && st1.begin()->f == 0) {
            int a = st1.begin()->sec;
            st1.ers(mk(0, a));
            for (auto b : p[a]) {
                if (arr[b]) {
                    st0.ers(mk(cnt[b], b));
                    cnt[b]--;
                    st0.ins(mk(cnt[b], b));
                }
                else {
                    st1.ers(mk(cnt[b], b));
                    cnt[b]--;
                    st1.ins(mk(cnt[b], b));
                }
            }
        }
        while (!st0.empty() && st0.begin()->f == 0) {
            int a = st0.begin()->sec;
            st0.ers(mk(0, a));
            for (auto b : p[a]) {
                if (arr[b]) {
                    st0.ers(mk(cnt[b], b));
                    cnt[b]--;
                    st0.ins(mk(cnt[b], b));
                }
                else {
                    st1.ers(mk(cnt[b], b));
                    cnt[b]--;
                    st1.ins(mk(cnt[b], b));
                }
            }
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