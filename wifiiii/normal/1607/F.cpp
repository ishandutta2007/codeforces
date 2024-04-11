#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        auto chk = [&](int x, int y) {
            return 0 <= x && x < n && 0 <= y && y < m;
        };
        vector<int> nxt(n * m, -1), deg(n * m), dp(n * m), dp2(n * m);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                char c;
                cin >> c;
                int x = i, y = j;
                if(c == 'L') --y;
                if(c == 'R') ++y;
                if(c == 'U') --x;
                if(c == 'D') ++x;
                if(chk(x, y)) {
                    nxt[i * m + j] = x * m + y;
                    deg[x * m + y] += 1;
                }
            }
        }
        for(int i = 0; i < n * m; ++i) dp2[i] = i;
        queue<int> q;
        for(int i = 0; i < n * m; ++i) if(deg[i] == 0) q.push(i);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(nxt[u] != -1) {
                int v = nxt[u];
                if(dp[v] < dp[u] + 1) {
                    dp[v] = dp[u] + 1;
                    dp2[v] = dp2[u];
                }
                if(--deg[v] == 0) q.push(v);
            }
        }
        int ans = 0;
        for(int i = 0; i < n * m; ++i) {
            if(deg[i] == 0) continue;
            int p = nxt[i];
            vector<int> loop;
            while(p != i) {
                loop.push_back(p);
                p = nxt[p];
            }
            loop.push_back(i);
            for(int j : loop) dp[j] += loop.size() - 1, deg[j] = 0;
        }
        int mx = -1, x = -1, y = -1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(dp[i * m + j] > mx) {
                    mx = dp[i * m + j];
                    x = dp2[i * m + j] / m;
                    y = dp2[i * m + j] % m;
                }
            }
        }
        cout << x + 1 << " " << y + 1 << " " << mx + 1 << endl;
    }
}