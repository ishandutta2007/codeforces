#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read() {
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int main() {
    int n = read(), m = read(), w = read();
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            a[i][j] = read();
        }
    }
    int dir1[] = {-1, 1, 0, 0};
    int dir2[] = {0, 0, -1, 1};
    vector<vector<int>> vis(n, vector<int>(m));
    vector<vector<ll>> dis(n, vector<ll>(m));
    queue<pair<int,int>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    ll min_port_from_start = 1e18;
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if(a[x][y] > 0) min_port_from_start = min(min_port_from_start, dis[x][y] * w + a[x][y]);
        for(int i = 0; i < 4; ++i) {
            int xx = x + dir1[i], yy = y + dir2[i];
            if(xx < 0 || yy < 0 || xx == n || yy == m || a[xx][yy] == -1 || vis[xx][yy]) continue;
            vis[xx][yy] = 1;
            dis[xx][yy] = dis[x][y] + 1;
            q.push({xx, yy});
        }
    }
    ll ans = 1e18;
    if(vis[n-1][m-1]) ans = min(ans, dis[n-1][m-1] * w);
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) vis[i][j] = 0;
    ll min_port_from_dest = 1e18;
    q.push({n-1, m-1});
    vis[n-1][m-1] = 1;
    dis[n-1][m-1] = 0;
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if(a[x][y] > 0) min_port_from_dest = min(min_port_from_dest, dis[x][y] * w + a[x][y]);
        for(int i = 0; i < 4; ++i) {
            int xx = x + dir1[i], yy = y + dir2[i];
            if(xx < 0 || yy < 0 || xx == n || yy == m || a[xx][yy] == -1 || vis[xx][yy]) continue;
            vis[xx][yy] = 1;
            dis[xx][yy] = dis[x][y] + 1;
            q.push({xx, yy});
        }
    }
    ans = min(ans, min_port_from_start + min_port_from_dest);
    if(ans >= 1e18) cout << -1 << '\n';
    else cout << ans << '\n';
}