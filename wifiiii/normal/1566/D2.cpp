#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> sa(n, vector<int>(m));
        vector<int> a(n * m);
        for(int i = 0; i < n * m; ++i) cin >> a[i];
        auto aa = a;
        sort(aa.begin(), aa.end());
        aa.resize(unique(aa.begin(), aa.end()) - aa.begin());
        auto f = [&](int x) {return lower_bound(aa.begin(), aa.end(), x) - aa.begin();};
        for(int &i : a) i = f(i);
        auto a2 = a;
        sort(a2.begin(), a2.end());
        vector<queue<int>> col(n * m);
        for(int i = 0; i < n; ++i) {
            vector<int> see(n * m);
            for(int j = 0; j < m; ++j) {
                sa[i][j] = a2[i * m + j];
                if(!see[sa[i][j]]) {
                    col[sa[i][j]].push(i);
                }
                see[sa[i][j]] = 1;
            }
        }
        vector<vector<int>> vis(n, vector<int>(m));
        int ans = 0;
        for(int i : a) {
            int pos = -1;
            assert(!col[i].empty());
            int cur = col[i].front();
            for(int j = m - 1; j >= 0; --j) {
                if(vis[cur][j]) continue;
                if(sa[cur][j] == i) {
                    pos = j;
                    break;
                }
            }
            if(pos == -1) {
                col[i].pop();
                assert(!col[i].empty());
                cur = col[i].front();
                for(int j = m - 1; j >= 0; --j) {
                    if(vis[cur][j]) continue;
                    if(sa[cur][j] == i) {
                        pos = j;
                        break;
                    }
                }
            }
            assert(pos != -1);
            vis[cur][pos] = 1;
            for(int j = 0; j < pos; ++j) {
                ans += vis[cur][j];
            }
        }
        cout << ans << '\n';
    }
}