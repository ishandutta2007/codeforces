#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> a(m);
    vector<bool> sto(1 << n);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        sto[a[i]] = true;
    }
    vector<bool> vis(1 << n);
    int ans = 0;
    vector<bool> seen(1 << n);
    for(int i = 0; i < m; i++) {
        if(seen[a[i]]) continue;
        vis[a[i]] = true;
        seen[a[i]] = true;
        ++ans;
        queue<int> in;
        in.push(a[i]);
        while(!in.empty()) {
            auto curr = in.front();
            in.pop();
            seen[(1 << n) - 1 - curr] = true;
            for(int nxt = 0; nxt < n; nxt++) {
                if(curr & (1 << nxt)) continue;
                if(!vis[curr ^ (1 << nxt)]) {
                    vis[curr ^ (1 << nxt)] = true;
                    in.push(curr ^ (1 << nxt));
                }
            }
            if(sto[(1 << n) - 1 - curr] && !vis[(1 << n) - 1 - curr]) in.push((1 << n) - 1 - curr);
        }
    }
    cout << ans;
}