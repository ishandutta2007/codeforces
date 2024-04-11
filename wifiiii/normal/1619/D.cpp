#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector a(m, vector<int>(n)), b = a;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        int lo = 1, hi = 1e9;
        while(lo < hi) {
            int mid = (lo + hi + 1) / 2;
            vector<int> vis(n), cnt(m);
            int dup = 0;
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(a[i][j] >= mid) {
                        vis[j] = 1;
                        if(cnt[i]++) {
                            dup = 1;
                        }
                    }
                }
            }
            if(count(vis.begin(), vis.end(), 1) == n && dup) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << '\n';
    }
}