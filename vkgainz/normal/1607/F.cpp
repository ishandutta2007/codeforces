#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <queue>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> rev(n * m);
        vector<int> nxt(n * m);
        vector<int> dp(n * m);
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < m; j++) {
                int dx = i, dy = j;
                if (s[j] == 'U') --dx;
                if (s[j] == 'D') ++dx;
                if (s[j] == 'R') ++dy;
                if (s[j] == 'L') --dy;
                if (dx < 0 || dx >= n 
                        || dy < 0 || dy >= m) {
                    nxt[i * m + j] = i * m + j;
                    rev[i * m + j].push_back(i * m + j);
                } else {
                    nxt[i * m + j] = dx * m + dy;
                    rev[dx * m + dy].push_back(i * m + j);
                }
            }
        }
        vector<bool> vis(n * m);
        vector<bool> tmp(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i * m + j]) continue;
                int st = i * m + j;
                while (!tmp[st]) {
                    tmp[st] = true;
                    st = nxt[st];
                }
                int len = 0;
                vector<int> in;
                //get in
                int sto = st;
                in.push_back(st);
                while (nxt[st] != sto) {
                    in.push_back(nxt[st]);
                    st = nxt[st];
                }
                len = in.size();
                for (int x : in) {
                    vis[x] = true;
                }
                queue<int> q;
                for (int x : in) {
                    q.push(x);
                    dp[x] = len;
                    while (!q.empty()) {
                        int curr = q.front();
                        q.pop();
                        for (int next : rev[curr]) {
                            if (!vis[next]) {
                                vis[next] = true;
                                q.push(next);
                                dp[next] = dp[curr] + 1;
                            }
                        }
                    }
                }
            }
        }
        pair<int, int> ans = {-1, 0};
        for (int i = 0; i < n * m; i++) {
            if (dp[i] > ans.first) {
                ans = {dp[i], i};
            }
        }
        cout << ans.second / m  + 1 << " " << ans.second % m + 1 << " " << ans.first << "\n";
    }
}