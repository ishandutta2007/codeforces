#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int ddx[] = {-1, -1, 1, 1};
const int ddy[] = {-1, 1, 1, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        vector<string> g(N);
        for (int i = 0; i < N; ++i){
            cin >> g[i];
        }

        auto in = [&](int i, int j){
            return i >= 0 && i < N && j >= 0 && j < M;
        };

        auto valid = [&](int i, int j){
            for (int d = 0; d < 4; ++d){
                int nx = i + dx[d], ny = j + dy[d];
                if (in(nx, ny) && g[nx][ny] == '#') return 0;
            }
            return 1;
        };

        vector<vector<int>> dist(N, vector<int>(M, 1e9));
        using pii = pair<int, int>;
        vector<vector<pii>> from(N, vector<pii>(M, {-1, -1}));
        queue<pii> q;
        for (int i = 0; i < N; ++i){
            if (!valid(i, 0)) continue;
            dist[i][0] = g[i][0] == '.';
            q.push({i, 0});
        }
        while (!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d){
                int nx = x + ddx[d], ny = y + ddy[d];
                if (!in(nx, ny)) continue;
                if (!valid(nx, ny)) continue;
                int ndist = dist[x][y] + (g[nx][ny] == '.');
                if (ndist < dist[nx][ny]){
                    dist[nx][ny] = ndist;
                    from[nx][ny] = {x, y};
                    q.push({nx, ny});
                }
            }
        }
        int argmn = 0;
        for (int i = 1; i < N; ++i){
            if (dist[i][M-1] < dist[argmn][M-1]){
                argmn = i;
            }
        }
        if (dist[argmn][M-1] == 1e9){
            cout << "NO" << '\n';
        }
        else{
            int x = argmn, y = M-1;
            while (x != -1 && y != -1){
                g[x][y] = '#';
                pii nxt = from[x][y];
                x = nxt.first, y = nxt.second;
            }
            cout << "YES" << '\n';
            for (int i = 0; i < N; ++i){
                cout << g[i] << '\n';
            }
        }
    }
}