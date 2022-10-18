//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 1005
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, xT, yT, xM, yM, d[maxN][maxN][4];
bool f[maxN][maxN][4][4];
int dx[5] = {-1, 0, 1, 0, 0};
int dy[5] = {0, 1, 0, -1, 0};
int ddir[5] = {0, 0, 0, 0, 1};
queue<pair<ii, int> > q;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d\n", &n, &m);
    fto(i, 1, n) {
        fto(j, 1, m) {
            char c;
            scanf("%c", &c);
            switch(c) {
                case '+': {
                    f[i][j][0][0] = f[i][j][0][1] = f[i][j][0][2] = f[i][j][0][3] = true;
                    break;
                }
                case '-': {
                    f[i][j][0][1] = f[i][j][0][3] = true;
                    break;
                }
                case '|': {
                    f[i][j][0][0] = f[i][j][0][2] = true;
                    break;
                }
                case '^': {
                    f[i][j][0][0] = true;
                    break;
                }
                case '>': {
                    f[i][j][0][1] = true;
                    break;
                }
                case '<': {
                    f[i][j][0][3] = true;
                    break;
                }
                case 'v': {
                    f[i][j][0][2] = true;
                    break;
                }
                case 'L': {
                    f[i][j][0][0] = f[i][j][0][1] = f[i][j][0][2] = true;
                    break;
                }
                case 'R': {
                    f[i][j][0][0] = f[i][j][0][2] = f[i][j][0][3] = true;
                    break;
                }
                case 'U': {
                    f[i][j][0][1] = f[i][j][0][2] = f[i][j][0][3] = true;
                    break;
                }
                case 'D': {
                    f[i][j][0][0] = f[i][j][0][1] = f[i][j][0][3] = true;
                    break;
                }
            }
        }
        scanf("\n");
    }

    fto(i, 1, n) {
        fto(j, 1, m) {
            fto(k, 1, 3) {
                fto(d, 0, 3) f[i][j][k][d] = f[i][j][k-1][(d+3)%4];
            }
        }
    }
//    fto(z, 0, 3) {
//        debug(z);
//        fto(i, 1, n) {
//            fto(j, 1, m) printf("%d ", f[i][j][1][z]);
//            puts("");
//        }
//    }

    scanf("%d%d%d%d", &xT, &yT, &xM, &yM);
    d[xT][yT][0] = 1;
    q.push(mp(mp(xT, yT), 0));
    while (!q.empty()) {
        int x = q.front().ff.ff, y = q.front().ff.ss, z = q.front().ss; q.pop();
        fto(i, 0, 4) {
            int u = x+dx[i], v = y+dy[i], t = (z+ddir[i])%4;
            int ri;
            switch (i) {
                case 0: {ri = 2; break;}
                case 2: {ri = 0; break;}
                case 1: {ri = 3; break;}
                case 3: {ri = 1; break;}
            }
            if (i < 4 && (u < 1 || u > n || v < 1 || v > m || !f[x][y][z][i] || !f[u][v][z][ri])) continue;
            if (!d[u][v][t]) {
                d[u][v][t] = d[x][y][z]+1;
                q.push(mp(mp(u, v), t));
            }
        }
    }
//    fto(z, 0, 3) {
//        debug(z);
//        fto(i, 1, n) {
//            fto(j, 1, m) printf("%d ", d[i][j][z]);
//            puts("");
//        }
//    }

    int minD = oo;
    fto(z, 0, 3) {
        if (d[xM][yM][z] > 0) minD = min(minD, d[xM][yM][z]-1);
    }
    if (minD == oo) puts("-1");
    else printf("%d", minD);

    return 0;
}