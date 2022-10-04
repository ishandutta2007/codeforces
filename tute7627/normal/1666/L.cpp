// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m, s;
    cin >> n >> m >> s;
    --s;
    vector<vector<int>> edge(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (v == s) continue;
        edge[u].push_back(v);
    }
    vector<int> adjs = edge[s];
    vector<int> prev(n, -1), root(n, -1);
    for (auto& s2 : adjs) {
        if (root[s2] != -1) {
            vector<int> ans1 = { s, s2 };
            vector<int> ans2;
            int now = s2;
            while (now != s) {
                ans2.push_back(now);
                now = prev[now];
            }
            ans2.push_back(now);
            reverse(ans2.begin(), ans2.end());
            cout << "Possible\n";
            cout << ans1.size() << '\n';
            for (int i = 0; i < (int)ans1.size(); ++i) {
                cout << ans1[i] + 1 << (i < (int)ans1.size() - 1 ? ' ' : '\n');
            }
            cout << ans2.size() << '\n';
            for (int i = 0; i < (int)ans2.size(); ++i) {
                cout << ans2[i] + 1 << (i < (int)ans2.size() - 1 ? ' ' : '\n');
            }
            return 0;
        }

        queue<int> q;
        prev[s2] = s;
        root[s2] = s2;
        q.push(s2);
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            for (auto& i : edge[p]) {
                if (root[i] != -1 && root[i] != s2) {
                    vector<int> ans1;
                    {
                        ans1.push_back(i);
                        int now = p;
                        while (now != s) {
                            ans1.push_back(now);
                            now = prev[now];
                        }
                        ans1.push_back(now);
                        reverse(ans1.begin(), ans1.end());
                    }
                    vector<int> ans2;
                    {
                        int now = i;
                        while (now != s) {
                            ans2.push_back(now);
                            now = prev[now];
                        }
                        ans2.push_back(now);
                        reverse(ans2.begin(), ans2.end());
                    }
                    cout << "Possible\n";
                    cout << ans1.size() << '\n';
                    for (int i = 0; i < (int)ans1.size(); ++i) {
                        cout << ans1[i] + 1 << (i < (int)ans1.size() - 1 ? ' ' : '\n');
                    }
                    cout << ans2.size() << '\n';
                    for (int i = 0; i < (int)ans2.size(); ++i) {
                        cout << ans2[i] + 1 << (i < (int)ans2.size() - 1 ? ' ' : '\n');
                    }
                    return 0;
                }
                else if (root[i] == -1) {
                    prev[i] = p;
                    root[i] = s2;
                    q.push(i);
                }
            }
        }
    }
    cout << "Impossible\n";

    return 0;
}