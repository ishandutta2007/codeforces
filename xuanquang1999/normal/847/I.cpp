//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 255
#define oo 1000000007
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct point{int x, y;};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, Q, P, d[maxN][maxN], ans[maxN][maxN];
char s[maxN][maxN];
vector<point> save;

void BFS(int xS, int yS) {
    for(point p: save) d[p.x][p.y] = 0;
    save.clear();

    d[xS][yS] = (s[xS][yS]-'A'+1)*Q;
    queue<point> q;
    q.push({xS, yS});

    while (!q.empty()) {
        int x = q.front().x, y = q.front().y; q.pop();
        save.pb({x, y});
        //ans[x][y] = ans[x][y]+d[x][y];
        ans[x][y] = min(ans[x][y]+d[x][y], P+1);
        if (d[x][y] < 2) continue;
        fto(i, 0, 3) {
            int u = x+dx[i], v = y+dy[i];
            if (u >= 0 && u < n && v >= 0 && v < m && s[u][v] != '*' && d[u][v] == 0) {
                d[u][v] = (d[x][y]>>1);
                q.push({u, v});
            }
        }
    }
//    fto(i, 0, n-1) {
//        fto(j, 0, m-1) printf("%d ", d[i][j]);
//        puts("");
//    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d%d", &n, &m, &Q, &P);
    fto(i, 0, n-1) scanf("%s", s[i]);

    fto(i, 0, n-1) {
        fto(j, 0, m-1) {
            if (s[i][j] != '.' && s[i][j] != '*') BFS(i, j);
        }
    }

//    fto(i, 0, n-1) {
//        fto(j, 0, m-1) printf("%d ", ans[i][j]);
//        puts("");
//    }

    int cnt = 0;
    fto(i, 0, n-1) fto(j, 0, m-1) {
        if (ans[i][j] > P) ++cnt;
    }
    printf("%d", cnt);

    return 0;
}