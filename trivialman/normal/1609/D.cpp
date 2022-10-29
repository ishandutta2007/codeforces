#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int INF = (1 << 30) - 1;
const int N = 1e4 + 5;
mt19937 rng(time(0));

int T, n, d, x, y;
int fa[N], num[N];

int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); };

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> d;
    rep(i, 1, n) fa[i] = i, num[i] = 1;
    int nfree = 0;
    rep(i, 1, d) {
        cin >> x >> y;
        int px = find(x), py = find(y);
        if (px == py)
            nfree++;
        else {
            fa[py] = px;
            num[px] += num[py];
        }

        vector<int> a;
        rep(j, 1, n) if (fa[j] == j) a.PB(num[j]);
        sort(a.begin(), a.end(), [](int x, int y) { return x > y; });
        int ans = -1;
        rep(i, 0, nfree) ans += a[i];
        cout << ans << endl;
    }
    return 0;
}