#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2007, M = 1e6 + 7;
pair <int, int> gr[N], pr[N];
int minn[M];

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    memset(minn, 0, sizeof(minn));
    for (int i = 0; i < n; i++) cin >> gr[i].first >> gr[i].second;
    for (int i = 0; i < m; i++) cin >> pr[i].first >> pr[i].second;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (gr[i].first <= pr[j].first && gr[i].second <= pr[j].second) {
                int dx = pr[j].first - gr[i].first + 1;
                int dy = pr[j].second - gr[i].second + 1;
                minn[dx - 1] = max(minn[dx - 1], dy);
                //cout << dx << ' ' << dy << endl;
            }
        }
    }
    int res = M + M;
    for (int i = M - 2; i >= 0; i--) {
        minn[i] = max(minn[i], minn[i + 1]);
        res = min(res, i + minn[i]);
    }
    cout << res << endl;
    return 0;
}