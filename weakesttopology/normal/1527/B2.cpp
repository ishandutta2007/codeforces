#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

constexpr int nmax = 1e3;
int dp[nmax/2 + 1][nmax/2 + 1][2][2];
bool vis[nmax/2 + 1][nmax/2 + 1][2][2];

int solve(int s, int d, bool mid, bool rev) {
    if (s == 0 && d == 0) return mid;

    int& res = dp[s][d][mid][rev];
    bool& vis0 = vis[s][d][mid][rev];
    if (vis0) return res;
    vis0 = true;
    res = +INF;

    vector<tuple<int, int, bool, bool, int>> candidates;
    if (s > 0) candidates.emplace_back(s - 1, d, mid, false, 1);
    if (d > 0) candidates.emplace_back(s + 1, d - 1, mid, false, 1);
    if (mid) candidates.emplace_back(s, d, false, false, 1);
    if (not rev && s > 0) candidates.emplace_back(s, d, mid, true, 0);

    for (auto [ns, nd, nmid, nrev, pay] : candidates) {
        res = min(res, pay - solve(ns, nd, nmid, nrev));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string r;
        cin >> r;

        int s = 0, d = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (r[i] != r[n - 1 - i]) s += 1;
            else if (r[i] == '0') d += 1;
        }

        int mx = solve(s, d, n % 2 && r[n / 2] == '0', false);
        string ans = mx <= 0 ? mx < 0 ? "ALICE" : "DRAW" : "BOB";
        cout << ans << endl;
    }

    exit(0);
}