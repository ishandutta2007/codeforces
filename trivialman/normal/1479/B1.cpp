#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int n, a[N], diff[N];
int ma[N], ma_idx[2];
int dp[N][2]; //0: same; 1: different

void insert(int idx, int x) {
    if (x > ma[ma_idx[0]]) {
        ma_idx[1] = ma_idx[0], ma_idx[0] = idx;
    } else if (idx != ma_idx[0] && x > ma[ma_idx[1]]) {
        ma_idx[1] = idx;
    }
}

int main() {
    cin >> n;
    rep(i, 1, n) scanf("%d", a + i);
    diff[1] = 1;
    rep(i, 2, n) diff[i] = diff[i - 1] + (a[i] != a[i - 1]);
    //rep(i, 1, n) cerr << diff[i] << " ";
    //cerr << endl;

    rep(i, 0, 1) dp[1][i] = 1;
    ma_idx[0] = 1, ma_idx[1] = 2;

    rep(i, 2, n) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + (a[i] != a[i - 1]);
        dp[i][1] = ma[a[i]] + diff[i - 1];
        dp[i][1] = max(dp[i][1], ma[ma_idx[0] == a[i] ? ma_idx[1] : ma_idx[0]] + diff[i - 1] + 1);
        ma[a[i - 1]] = max(ma[a[i - 1]], dp[i][1] - diff[i]);
        insert(a[i - 1], ma[a[i - 1]]);
        //cerr << i << " " << a[i] << " " << dp[i][0] << " " << dp[i][1] << endl;
        //cerr << ma_idx[0] << " " << ma_idx[1] << endl;
        //rep(i, 1, n) cerr << ma[i] << " ";
        //cerr << endl;
    }
    int ans = 0;
    rep(i, 0, 1) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}