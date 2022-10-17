#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    const int N = 100000;
    vector<vector<int>> ax(N), ay(N);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            --x;
            ax[x].push_back(i);
            ay[x].push_back(j);
        }
    }
    ll ans = 0;
    auto solve = [&](vector<int> &a) -> ll {
        if(a.empty()) return 0;
        sort(a.begin(), a.end());
        ll s = 0;
        for(int i : a) s += i;
        ll ret = 0;
        for(int i = 0; i < a.size(); ++i) {
            ret += s - 1ll * (a.size() - i) * a[i];
            s -= a[i];
        }
        return ret;
    };
    for(int i = 0; i < N; ++i) {
        ans += solve(ax[i]);
        ans += solve(ay[i]);
    }
    cout << ans << '\n';
}