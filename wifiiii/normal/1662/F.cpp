#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, x, y;
        cin >> n >> x >> y;
        --x, --y;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<int> dis(n, -1);
        queue<int> q;
        dis[x] = 0;
        q.push(x);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(u == y) break;
            int l = max(0, u - a[u]), r = min(n - 1, u + a[u]);
            for(int i = u + 1; i <= r; ++i) {
                if(i - u <= min(a[u], a[i]) && dis[i] == -1) {
                    dis[i] = dis[u] + 1;
                    q.push(i);
                }
                if(dis[i] != -1 && dis[i] <= dis[u] && i - u >= a[u] - a[i]) {
                    break;
                }
            }
            for(int i = u - 1; i >= l; --i) {
                if(u - i <= min(a[u], a[i]) && dis[i] == -1) {
                    dis[i] = dis[u] + 1;
                    q.push(i);
                }
                if(dis[i] != -1 && dis[i] <= dis[u] && u - i >= a[u] - a[i]) {
                    break;
                }
            }
        }
        cout << dis[y] << '\n';
    }
}