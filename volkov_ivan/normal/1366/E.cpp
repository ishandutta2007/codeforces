#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int M = 998244353, N = 2e5 + 7, INF = 1e9 + 7;
int a[N], b[N];
pair <int, int> gr[N];

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pair <int, int>> poss;
    int mini = INF;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mini = min(mini, a[i]);
        poss.push_back({a[i], i});
    }
    for (int i = 0; i < m; i++) cin >> b[i];
    if (mini < b[0]) {
        cout << 0 << endl;
        return 0;
    }
    sort(poss.begin(), poss.end());
    int maxi = 0;
    int l = 0;
    for (int i = 0; i < m; i++) {
        int poscur = -1; 
        int nxt = (i == m - 1 ? INF : b[i + 1]);
        while (l != n && poss[l].first < nxt) {
            if (poss[l].first == b[i]) poscur = max(poscur, poss[l].second);
            maxi = max(maxi, poss[l].second);
            l++;
        }
        if (poscur == -1) {
            cout << 0 << endl;
            return 0;
        }
        gr[i] = {poscur, maxi};
    }
    int res = 1;
    for (int i = 1; i < m; i++) {
        if (gr[i].first <= gr[i - 1].second) {
            cout << 0 << endl;
            return 0;
        }
        int cnt = gr[i].first - gr[i - 1].second;
        res = (res * cnt) % M;
    }
    cout << res << endl;
}