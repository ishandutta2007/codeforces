#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 1e4 + 5;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(time(0));

int T, n, m, x, y;
int a[N], fa[N], num[N], ans[N];

int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }

void ask(int x) {
    cout << "? " << x << endl;
    cin >> y;
    int px = find(x), py = find(y);
    fa[px] = py, num[py] += num[px];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) cin >> a[i], fa[i] = i, num[i] = 1;
        int q = n;
        while (q) {
            int x = 0;
            rep(i, 1, n) if (num[find(i)] == 1 && a[i] > a[x]) x = i;
            if (x == 0)
                break;
            int q0 = q;
            rep(i, 1, min(q0, a[x])) {
                ask(x), q--;
                if (num[find(x)] > i + 1)
                    break;
            }
        }
        cout << "! ";
        memset(ans, 0, sizeof ans);
        int c = 0;
        rep(i, 1, n) {
            int x = find(i);
            if (ans[x] == 0)
                ans[x] = ++c;
            cout << ans[x] << " ";
        }
        cout << endl;
    }
    return 0;
}