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

const int N = 2e5 + 10;
int add[N], arr[N], sum;

_ void source() {
    int m, r = 1;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int len, delta;
            cin >> len >> delta;
            add[len] += delta;
            sum += len * delta;
        }
        else if (type == 2) {
            r++;
            int val;
            cin >> val;
            arr[r] = val;
            sum += val;
        }
        else {
            arr[r] += add[r];
            sum -= arr[r];
            add[r - 1] += add[r];
            add[r] = 0;
            r--;
        }
        cout << fixed << setprecision(10) << ld(sum) / ld(r) << endl;
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