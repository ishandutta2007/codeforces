//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define X real()
#define Y imag()
#define maxN 105
#define oo 2000000007
#define EPS 1e-9
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

char s[maxN][maxN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char dir[4] = {'U', 'R', 'D', 'L'};
int m, n, a[maxN][maxN], swapLR, swapUD, x, y, u, v, trace[maxN][maxN];

void findSwapUD() {
    puts("D"); fflush(stdout);
    scanf("%d%d", &u, &v);
    if (a[u][v] == 2) exit(0);
    swapUD = (u == x && v == y) ? 1 : 0;
    if (!swapUD) {
        puts("U"); fflush(stdout);
        scanf("%d%d", &u, &v);
    } else swap(dir[0], dir[2]);
}

void findSwapLR() {
    puts("R"); fflush(stdout);
    scanf("%d%d", &u, &v);
    if (a[u][v] == 2) exit(0);
    swapLR = (u == x && v == y) ? 1 : 0;
    if (!swapLR) {
        puts("L"); fflush(stdout);
        scanf("%d%d", &u, &v);
    } else swap(dir[1], dir[3]);
}

void BFS() {
    a[x][y] = 0;
    queue<ii> q;
    q.push(mp(x, y));
    while (!q.empty()) {
        int x = q.front().ff, y = q.front().ss; q.pop();
        fto(i, 0, 3) {
            int u = x+dx[i], v = y+dy[i];
            if (u > 0 && u <= m && v > 0 && v <= n && a[u][v]) {
                trace[u][v] = i;
                a[u][v] = 0;
                q.push(mp(u, v));
            }
        }
    }
}

int main () {
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        //freopen("output.txt", "w", stdout);
//    #endif // ONLINE_JUDGE

    scanf("%d%d", &m, &n);
    fto(i, 0, m-1) scanf("%s", s[i]);
    fto(i, 1, m) fto(j, 1, n) {
        if (s[i-1][j-1] == '#') a[i][j] = 0;
        if (s[i-1][j-1] == '.') a[i][j] = 1;
        if (s[i-1][j-1] == 'F') a[i][j] = 2;
    }

//    freopen("", "r", stdin);

    swapLR = -1; swapUD = -1;
    x = 1; y = 1;
    if (n > 1 && a[x][y+1]) {
        findSwapLR();
        while (m > 1 && swapUD == -1) {
            if (a[x+1][y]) {
                findSwapUD();
                break;
            }
            puts((swapLR) ? "L" : "R"); fflush(stdout);
            scanf("%d%d", &u, &v); x = u; y = v;
            if (a[u][v] == 2) exit(0);
        }
    } else if (m > 1 && a[x+1][y]) {
        findSwapUD();
        while (n > 1 && swapLR == -1) {
            if (a[x][y+1]) {
                findSwapLR();
                break;
            }
            puts((swapUD) ? "U" : "D"); fflush(stdout);
            scanf("%d%d", &u, &v); x = u; y = v;
            if (a[u][v] == 2) exit(0);
        }
    }

    fto(i, 1, m) fto(j, 1, n) {
        if (a[i][j] == 2) u = i, v = j;
    }
    BFS();
//    printf("%d %d %d %d\n", x, y, u, v);

    string ans;
    while (u != x || v != y) {
        int i = trace[u][v];
        ans += dir[i];
        u -= dx[i]; v -= dy[i];
    }

    reverse(ans.begin(), ans.end());
    forit(it, ans) {
        printf("%c\n", *it); fflush(stdout);
        scanf("%d%d", &u, &v);
    }

    return 0;
}
/*
1 3
..F
*/