#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
int P = 998244353;
const int INF = 1e9 + 1;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int n, m;
LL ans = 0;
vector<int> a[N];
array<LL, 3> status[N];

LL solve(char type) {
    LL res = 0;
    int h, w;
    if (type == 'R')
        h = n, w = m;
    else
        h = m, w = n;

    memset(status, 0, sizeof status);
    rep(i, 1, h) {
        unordered_map<int, int> mp;
        mp.clear();
        rep(j, 1, w) mp[type == 'R' ? a[i][j] : a[j][i]]++;
        for (auto [num, cnt] : mp) {
            auto [i1, cnt1, val] = status[num];
            res += 1ll * cnt * cnt1 * (i - i1) + 1ll * cnt * val;
            status[num] = {i, cnt1 + cnt, val + cnt1 * (i - i1)};
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) {
        a[i].resize(m + 1);
        rep(j, 1, m) cin >> a[i][j];
    }
    ans = solve('R') + solve('C');
    cerr << solve('R') << " " << solve('C') << endl;
    cout << ans;
    return 0;
}