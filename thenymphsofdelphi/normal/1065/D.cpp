#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1061109567
#define int long long
#define INFLL 4557430888798830399
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s,"r",stdin);
#define out(s) freopen(s,"w",stdout);
#define fi first
#define se second
#define bw(i,r,l) for (int i=r-1;i>=l;i--)
#define fw(i,l,r) for (int i=l;i<r;i++)
#define fa(i,x) for (auto i:x)

typedef pair<int, int> ii;
typedef pair<ii, ii> pii;

const int N = 15;

int n, a[N][N];
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, -2, 2};
int bx[] = {0, -1, 1, 0, 1, -1, 1, -1};
int by[] = {-1, 0, 0, 1, 1, 1, -1, -1};

ii f[N][N][230][4], pos[105];
bool vis[N][N][230][4];

bool check(int x, int y){
	if (x < 1 || y < 1 || x > n || y > n) return 0;
	return 1;
}
void proc(){
    fw (i, 0, N) fw (j, 0, N) fw (t, 0, N * N) fw (k, 0, 4) f[i][j][t][k] = ii(INF, 0);
    queue<pii> q;
    fw (i, 1, 4) {
        f[pos[1].fi][pos[1].se][1][i] = ii(0, 0);
        vis[pos[1].fi][pos[1].se][1][i] = true;
        q.push({{pos[1].fi, pos[1].se},{1, i}});
    }
    while (!q.empty()){
        pii cur = q.front(); q.pop();
        vis[cur.fi.fi][cur.fi.se][cur.se.fi][cur.se.se] = false;
        fw (i, 0, 8){
            int nxtx = cur.fi.fi + dx[i], nxty = cur.fi.se + dy[i];
            if (check(nxtx, nxty)) {
                ii val = f[cur.fi.fi][cur.fi.se][cur.se.fi][cur.se.se];
                if (cur.se.se != 1) val.se++, val.fi++;
                val.fi++;
                int nxt = cur.se.fi;
                if (a[nxtx][nxty] == nxt + 1) nxt++;
                if (f[nxtx][nxty][nxt][1] > val) {
                    f[nxtx][nxty][nxt][1] = val;
                    if (!vis[nxtx][nxty][nxt][1]) {
                        vis[nxtx][nxty][nxt][1] = true;
                        q.push({{nxtx, nxty}, {nxt, 1}});
                    }
                }
            }
        }
        fw (i, 1, n + 1){
            fw (t, 0, 8){
                int nxtx = cur.fi.fi + bx[t] * i, nxty = cur.fi.se + by[t] * i;
                if (check(nxtx, nxty)) {
                    ii val = f[cur.fi.fi][cur.fi.se][cur.se.fi][cur.se.se];
                    int ty = 2;
					if (t < 4) ty = 3;
                    if (cur.se.se != ty) val.se++, val.fi++;
                    val.fi++;
                    int nxt = cur.se.fi;
                    if (a[nxtx][nxty] == nxt + 1) nxt ++;
                    if (f[nxtx][nxty][nxt][ty] > val) {
                        f[nxtx][nxty][nxt][ty] = val;
                        if (!vis[nxtx][nxty][nxt][ty]) {
                            vis[nxtx][nxty][nxt][ty] = true;
                            q.push({{nxtx, nxty}, {nxt, ty}});
                        }
                    }
                }
            }
        }
    }
    ii ans = {INF, 0};
    fw (i, 1, 4) ans = min(ans, f[pos[n * n].fi][pos[n * n].se][n * n][i]);
    cout << ans.fi << " " << ans.se << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    fw (i, 1, n + 1){
        fw (j, 1, n + 1){
            cin >> a[i][j];
            pos[a[i][j]] = ii(i, j);
        }
    }
    proc();
    //THANKS DUC NHA
}