#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k;
    cin >> k;
    vector<vector<int>> a(k), vis(k);
    vector<vector<pair<int,int>>> nxt(k), pre(k);
    map<ll, pair<int,int>> pos;
    const pair<int,int> nil = {-1, -1};
    for(int i = 0; i < k; ++i) {
        int m;
        cin >> m;
        a[i].resize(m);
        vis[i].resize(m);
        pre[i].resize(m, nil);
        nxt[i].resize(m, nil);
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
            pos[a[i][j]] = {i, j};
        }
    }
    ll sum = 0;
    for(auto b : a) {
        for(int i : b) {
            sum += i;
        }
    }
    if(sum % k) {
        cout << "No\n";
        return 0;
    }
    sum /= k;
    for(int i = 0; i < k; ++i) {
        ll s = 0;
        for(int j : a[i]) s += j;
        for(int j = 0; j < a[i].size(); ++j) {
            // + x - a[i][j] = sum - s
            // x = a[i][j] + sum - s
            if(sum == s) {
                nxt[i][j] = {i, j};
            } else if(pos.count(a[i][j] + sum - s) && pos[a[i][j] + sum - s].first != i) {
                nxt[i][j] = pos[a[i][j] + sum - s];
            }
        }
    }

    vector<int> dp(1 << k);
    vector<vector<pair<int,int>>> cyc(1 << k);
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < a[i].size(); ++j) {
            if(!vis[i][j] && nxt[i][j] != nil) {
                function<void(int,int)> dfs = [&](int x, int y) {
                    vis[x][y] = 1;
                    auto [nx, ny] = nxt[x][y];
                    if(nx == x) {
                        dp[1 << x] = 1;
                        cyc[1 << x] = {{x, y}};
                    } else if(nxt[x][y] == nil) {

                    } else if(!vis[nx][ny]) {
                        pre[nx][ny] = {x, y};
                        dfs(nx, ny);
                    } else if(vis[nx][ny] == 1) {
                        int cx = x, cy = y, g = 0, ok = 1;
                        vector<pair<int,int>> f;
                        while(make_pair(cx, cy) != make_pair(nx, ny)) {
                            f.push_back({cx, cy});
                            if(g >> cx & 1) ok = 0;
                            g |= 1 << cx;
                            auto p = pre[cx][cy];
                            cx = p.first;
                            cy = p.second;
                        }
                        if(g >> nx & 1) ok = 0;
                        g |= 1 << nx; f.push_back({nx, ny});
                        if(ok) {
                            dp[g] = 1;
                            cyc[g] = f;
                        }
                    }
                    vis[x][y] = 2;
                };
                dfs(i, j);
            }
        }
    }
    for(int i = 1; i < 1 << k; ++i) {
        if(dp[i]) continue;
        for(int j = (i - 1) & i; j; j = (j - 1) & i) {
            if(dp[j] && dp[j ^ i]) {
                dp[i] = 1;
                break;
            }
        }
    }
    if(dp[(1 << k) - 1]) {
        cout << "Yes\n";
        queue<int> q;
        q.push((1 << k) - 1);
        vector<pair<int,int>> ans(k);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(!cyc[u].empty()) {
                // 1 2 0
                int m = cyc[u].size();
                for(int i = 0; i < m; ++i) {
                    auto [x, y] = cyc[u][i];
                    auto [nx, ny] = cyc[u][(i + 1) % m];
                    ans[x] = {a[x][y], nx};
                }
                continue;
            }
            for(int j = (u - 1) & u; j; j = (j - 1) & u) {
                if(dp[j] && dp[j ^ u]) {
                    q.push(j);
                    q.push(j ^ u);
                    break;
                }
            }
        }
        for(auto [x, y] : ans) {
            cout << x << ' ' << y + 1 << '\n';
        }
    } else {
        cout << "No\n";
    }
}