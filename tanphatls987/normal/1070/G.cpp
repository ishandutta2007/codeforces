#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
int n, m;
int x[105], hp[105];
int a[105];
int b[105];
int seen[105];

int go(int id, int from, int to) {
    int sgn = (from < to) ? 1 : -1;
    int mau = hp[id];
    int cur = from;
    while (cur != to) {
        cur += sgn;
        mau += a[cur];
        if (mau < 0) return 0;
    }
    for (int i = from; i != to + sgn; i += sgn) a[i] = 0;
    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> x[i] >> hp[i];
    for (int i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i];
    for (int i = 1; i <= n; ++i) {
        vector <int> ans;
        for (int j = 1; j <= n; ++j) a[j] = b[j];
        for (int j = 1; j <= m; ++j) seen[j] = 0;
        int nseen = 0;
        int flag = 1;
        while (flag) {
            flag = 0;
            for (int j = 1; j <= m; ++j) if (!seen[j] && go(j, x[j], i)) {
                seen[j] = 1;
                ans.push_back(j);
                flag = 1;
                ++nseen;
            }
        }
        if (nseen < m) continue;
        cout << i << endl;
        for (auto g: ans) cout << g << ' ';
        cout << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}