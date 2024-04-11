#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 115
#define oo 1000000007

int nTest, n, m, tmp, xS, yS;
int dx[3] = {-1, 0, 1},
    dy[3] = {1, 1, 1};
char a[5][maxN];
bool visited[5][maxN];

void DFS(int x, int y) {
//    debug(x);
//    debug(y);
    visited[x][y] = true;
    fto(i, 0, 2) {
        int u = x+dx[i], v = y+dy[i];
        if (!visited[u][v+2] && a[x][y+1] == '.' && a[u][v] == '.' && a[u][v+1] == '.'&& a[u][v+2] == '.') DFS(u, v+2);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        n = 3;
        scanf("%d%d\n", &m, &tmp);

        memset(visited, false, sizeof(visited));
        fto(j, 0, m+1) a[0][j] = a[n+1][j] = '#';
        fto(i, 1, n) {
            a[i][0] = '#';
            fto(j, 1, m) {
                scanf("%c", &a[i][j]);
                if (a[i][j] == 's') xS = i, yS = j;
            }
            scanf("\n");
            a[i][m+1] = a[i][m+2] = '.';
            a[i][m+3] = a[i][m+4] = a[i][m+5] = '#';
        }

        DFS(xS, yS);

        bool ok = false;
        fto(i, 1, n)
            fto(j, m, m+2)
                if (visited[i][j]) {
                    ok = true;
                    break;
                }
        puts((ok) ? "YES" : "NO");
    }

    return 0;
}