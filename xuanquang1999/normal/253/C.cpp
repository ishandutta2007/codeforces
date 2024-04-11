using namespace std;
#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxM 100005
#define maxN 105
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, a[maxN], r1, c1, r2, c2, d[maxN][maxM];
queue<ii> q;

int main () {
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]), ++a[i];
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

    q.push(mp(r1, c1));
    d[r1][c1] = 1;

    while (!q.empty()) {
        int x = q.front().fi, y = q.front().se; q.pop();
        fto(i, 0, 3) {
            int u = x+dx[i], v = y+dy[i];
            if (u > 0 && u <= n) {
                if (v < 0) v = 0;
                else if (v > a[u]) v = a[u];
                if (!d[u][v]) {
                    d[u][v] = d[x][y]+1;
                    q.push(mp(u, v));
                }
            }
        }
    }

    printf("%d", d[r2][c2]-1);

    return 0;
}