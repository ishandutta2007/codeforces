#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
 
const int N = 23;
 
int x[N * N * 2], y[N * N * 2], t[N * N * 2];
 
int n, m, ma, fe;
 
char map[N][N];
 
int dis[N][N][N][N];
 
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
 
void init() {
    memset(dis, -1, sizeof(dis));
    for (int sx = 0; sx < n; ++sx) {
        for (int sy = 0; sy < m; ++sy) {
            if (map[sx][sy] != '.') {
                continue;
            }
            dis[sx][sy][sx][sy] = 0;
            queue<pair<int, int> > q;
            q.push(make_pair(sx, sy));
            while (q.size()) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int tx = x + dx[d], ty = y + dy[d];
                    if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
                        continue;
                    }
                    if (map[tx][ty] == '.' && dis[sx][sy][tx][ty] == -1) {
                        dis[sx][sy][tx][ty] = dis[sx][sy][x][y] + 1;
                        q.push(make_pair(tx, ty));
                    }
                }
            }
        }
    }
}
 
const int M = 5000005;
 
#define next NEXT
int etop, htop, head[M], to[M], next[M], c[M];
 
void addedge(int u, int v, int cap) {
//cout << "add" << ' ' << u << ' ' << v << ' ' << cap << endl;
    to[etop] = v, c[etop] = cap, next[etop] = head[u], head[u] = etop++;
}
 
int source, target;
 
int dis2[M], gap[M];
 
bool over;
 
const int INF = 1000000000;
 
int go(int u, int delta) {
    if (u == target) {
        return delta;
    }
 
    int t = delta, tmp;
 
    for (int i = head[u]; ~i; i = next[i]) {
        if (c[i]) {
            int v = to[i];
            if (dis2[v] == dis2[u] - 1) {
                tmp = min(t, c[i]);
                tmp = go(v, tmp);
                t -= tmp, c[i] -= tmp, c[i ^ 1] += tmp;
                if (t == 0 || over) {
                    return delta - t;
                }
            }
        }
    }
 
    if (--gap[dis2[u]] == 0) {
        over = true;
    }
    ++gap[++dis2[u]];
    
    return delta - t;
}
 
int flow() {
    for (int i = 0; i <= htop; ++i) {
        dis2[i] = 0;
        gap[i] = 0;
    }
    over = false;
    int ret = 0;
    while (!over && dis2[source] < htop) {
        ret += go(source, INF);
    }
//cout << "flow" << ' ' << ret << endl;
    return ret;
}
 
bool check(long long BAR) {
    etop = 0;
    source = ma + fe, target = ma + fe + 1, htop = ma + fe + 2; 
    for (int i = 0; i < htop; ++i) {
        head[i] = -1;
    }
    for (int i = 0; i < ma; ++i) {
        addedge(source, i, 1);
        addedge(i, source, 0);
    }
    for (int i = 0; i < fe; ++i) {
        addedge(ma + i, target, 1);
        addedge(target, ma + i, 0);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '#') {
                continue;
            }
            int u = htop++, v = htop++;
            head[u] = -1;
            head[v] = -1;
            addedge(u, v, 1);
            addedge(v, u, 0);
            for (int k = 0; k < ma + fe; ++k) {
                int xx = x[k], yy = y[k], tt = t[k];
                if (dis[i][j][xx][yy] == -1) {
                    continue;
                }
                long long d = (long long)dis[i][j][xx][yy] * tt;
                if (d <= BAR) {
                    if (k < ma) {
                        addedge(k, u, 1);
                        addedge(u, k, 0);
                    } else {
                        addedge(v, k, 1);
                        addedge(k, v, 0);
                    }
                }
            }
        }
    }
    return flow() == ma;
}
 
int main() {
    scanf("%d%d%d%d", &n, &m, &ma, &fe);
    for (int i = 0; i < n; ++i) {
        scanf("%s", map + i);
    }
    init();
    int k = 1 + ma + fe;
    int maxt = 0;
    for (int i = 0; i < k; ++i) {
        scanf("%d%d%d", x + i, y + i, t + i); 
        maxt = max(maxt, t[i]);
        --x[i], --y[i];
    }
    if (ma == fe) {
        printf("-1\n");
        return 0;
    }
    if (ma + 1 == fe) {
        ++ma;
    } else if (fe + 1 == ma) {
        swap(x[0], x[ma]);
        swap(y[0], y[ma]);
        swap(t[0], t[ma]);
        ++fe;
    } else {
        printf("-1\n");
        return 0;
    }
    long long l = 0, r = (long long)n * m * maxt + 1;
    while (l < r) {
//cout << "divd" << l << ' ' << r << endl;
        long long m = l + r >> 1;
        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (r == (long long)n * m * maxt + 1) {
        l = -1;
    }
	cout << l << endl;
    return 0;
}