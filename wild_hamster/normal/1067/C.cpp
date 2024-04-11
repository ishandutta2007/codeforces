#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<ll,ll>
#define X first
#define Y second
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
ll i,j,k,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c,z;
int knights[5005][5005], potentials[5005][5005];
int dirs[8][2] = {{2, -1}, {2, 1}, {1, 2}, {-1, -2}, {-2, 1}, {1, -2}, {-1, 2}, {-2, -1}};
set<pii> g[5];
vector<pii> p;
void update(int x, int y) {
    for (int j = 0; j < 8; j++) {
        int nx = x + dirs[j][0];
        int ny = y + dirs[j][1];
        if (potentials[nx][ny] != 0 && potentials[nx][ny] < 4) {
            g[potentials[nx][ny]].erase(mp(nx, ny));
        }
        potentials[nx][ny]++;
        if (potentials[nx][ny] < 4) {
            g[potentials[nx][ny]].insert(mp(nx, ny));
        }
        if (potentials[nx][ny] == 4 && knights[nx][ny] == 0) {
            boom++;
            knights[nx][ny] = 1;
            update(nx, ny);
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    knights[2500][2500] = 1;
    update(2500, 2500);
    p.push_back(mp(2500, 2500));
    int flag = 1;
    boom = 0;
    for (int i = 1; i < n; i++) {
        if (i*i/10 > boom)
            cout << i*i/10 << " " << boom << endl;
        int max1 = 0;
        for (int j = 3; j >= 0; j--) {
            if (!g[j].empty()) {
                auto itr = g[j].begin();
                int cnt = 0;
                int id = -1, optval = -111;
                int nxc, nyc;
                while (itr != g[j].end() && cnt < 33) {
                    pii v = *itr;
                    cnt++;
                    itr++;
                    for (int k = 0; k < 8; k++) {
                        int nx = v.X + dirs[k][0];
                        int ny = v.Y + dirs[k][1];
                        if (knights[nx][ny] == 0) {
                            int val = -potentials[nx][ny]*potentials[nx][ny];
                            for (int l = 0; l < 8; l++) {
                                int nxx = nx + dirs[l][0];
                                int nyy = ny + dirs[l][1];
                                if (knights[nxx][nyy] == 0)
                                    val += potentials[nxx][nyy]+1;
                            }
                            if (val > optval)
                                optval = val, nxc = nx, nyc = ny;
                        }
                    }
                }
                int nx = nxc;
                int ny = nyc;
                boom++;
                knights[nx][ny] = 1;
                update(nx, ny);
                p.push_back(mp(nx, ny));
                break;
            }
        }
    }
    for (int i = 0; i < p.size(); i++)
        cout << p[i].X << " " << p[i].Y << endl;
    return 0;
}