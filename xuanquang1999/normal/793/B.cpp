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
#define maxN 1005
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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, xS, yS, xT, yT;
char s[maxN][maxN];
bool visited[maxN][maxN][4][3];

void DFS(int x, int y, int dir, int turn) {
    if (turn > 2 || visited[x][y][dir][turn]) return;
    visited[x][y][dir][turn] = true;
    fto(i, 0, 3) {
        if ((i^dir) == 2) continue;
        int u = x+dx[i], v = y+dy[i];
        bool addTurn = (i^dir)&1;
        if (u >= 0 && u < n && v >= 0 && v < m && s[u][v] != '*') {
            //printf("%d %d %d %d %d %d %d %d\n", x, y, dir, turn, u, v, i, addTurn);
            DFS(u, v, i, turn+(addTurn));
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 0, n-1) scanf("%s", s[i]);

    fto(i, 0, n-1) {
        fto(j, 0, m-1) {
            if (s[i][j] == 'S') xS = i, yS = j;
            if (s[i][j] == 'T') xT = i, yT = j;
        }
    }

    fto(dir, 0, 3) DFS(xS, yS, dir, 0);

    fto(dir, 0, 3) {
        fto(turn, 0, 2) {
            if (visited[xT][yT][dir][turn]) {
                puts("YES");
                return 0;
            }
        }
    }

    puts("NO");


    return 0;
}