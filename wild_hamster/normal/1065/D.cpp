#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom;
ll a[500500], pa[500500];
pii p[105];
int d[105][12][12][3];
struct node {
    int dp;
    int x;
    int y;
    int fig;
    int num;
    node(int dp, int x, int y, int num, int fig) {
        this->dp = dp;
        this->x = x;
        this->y = y;
        this->num = num;
        this->fig = fig;
    }
    node() {
    }
    auto tie1() const {
        return tie(dp, x, y, num, fig);
    }
    bool operator < (const node& a) const {
        return this->tie1() < a.tie1();
    }
};
bool in_range(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}
int dirs[8][2] = {{1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {-1, -2}, {-1, 2}, {2, 1}, {2, -1}};
set<node> f;
void update(node y) {
    if (!in_range(y.x, y.y))
        return;

    if (d[y.num][y.x][y.y][y.fig] == MOD) {
        d[y.num][y.x][y.y][y.fig] = y.dp;
        f.insert(y);
    } else {
        if (y.dp < d[y.num][y.x][y.y][y.fig]) {
            int tmp = y.dp;
            y.dp = d[y.num][y.x][y.y][y.fig];
            f.erase(f.find(y));
            y.dp = tmp;
            d[y.num][y.x][y.y][y.fig] = tmp;
            f.insert(y);
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    //inp();
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> x;
            p[x] = mp(i, j);
        }
    for (int i = 0; i <= n*n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                for (int l = 0; l < 3; l++)
                    d[i][j][k][l] = MOD;
    for (int j = 0; j < 3; j++) {
        d[1][p[1].X][p[1].Y][j] = 0;
        f.insert(node(0, p[1].X, p[1].Y, 1, j));
    }
    while (!f.empty()) {
        node cur = *(f.begin());
        if (cur.num == n*n) {
            cout << cur.dp/15000 << " " << cur.dp%15000 << endl;
            return 0;
        }
        //cout << f.size() << endl;
        //cout << cur.num << " " << cur.x << " " << cur.y << " " << cur.fig << " " << cur.dp << endl;
        f.erase(cur);
        //cout << f.size() << endl;

        if (cur.fig == 0) {
            for (int j = 0; j < 8; j++) {
                node np;
                np.x = cur.x + dirs[j][0];
                np.y = cur.y + dirs[j][1];
                np.dp = cur.dp + 15000;
                np.fig = 0;
                np.num = cur.num;
                if (p[cur.num+1] == mp(np.x, np.y))
                    np.num++;
                update(np);
            }
            node np = cur;
            np.dp+=15001;
            np.fig = 1;
            update(np);
            np.fig = 2;
            update(np);
        }

        if (cur.fig == 1) {
            for (int j = -15; j < 15; j++) {
                node np;
                np.x = cur.x + j;
                np.y = cur.y + j;
                np.dp = cur.dp + 15000;
                np.fig = 1;
                np.num = cur.num;
                if (p[cur.num+1] == mp(np.x, np.y))
                    np.num++;
                update(np);
            }

            for (int j = -15; j < 15; j++) {
                node np;
                np.x = cur.x + j;
                np.y = cur.y - j;
                np.dp = cur.dp + 15000;
                np.fig = 1;
                np.num = cur.num;
                if (p[cur.num+1] == mp(np.x, np.y))
                    np.num++;
                update(np);
            }

            node np = cur;
            np.dp+=15001;
            np.fig = 2;
            update(np);
            np.fig = 0;
            update(np);
        }

        if (cur.fig == 2) {
            for (int j = -15; j < 15; j++) {
                node np;
                np.x = cur.x + j;
                np.y = cur.y;
                np.dp = cur.dp + 15000;
                np.fig = 2;
                np.num = cur.num;
                if (p[cur.num+1] == mp(np.x, np.y))
                    np.num++;
                update(np);
            }

            for (int j = -15; j < 15; j++) {
                node np;
                np.x = cur.x;
                np.y = cur.y + j;
                np.dp = cur.dp + 15000;
                np.fig = 2;
                np.num = cur.num;
                if (p[cur.num+1] == mp(np.x, np.y))
                    np.num++;
                update(np);
            }

            node np = cur;
            np.dp+=15001;
            np.fig = 1;
            update(np);
            np.fig = 0;
            update(np);
        }
    }
    return 0;
}