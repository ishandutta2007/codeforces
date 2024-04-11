//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define fordit(rit, type, var) for(type::reverse_iterator rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 1005

int m, n, q, CCcnt, Pcnt, CC[maxN][maxN], cnt[maxN*maxN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char a[maxN][maxN];

void DFS(int x, int y) {
    CC[x][y] = CCcnt;
    fto(i, 0, 3) {
        int u = x+dx[i], v = y+dy[i];
        if (a[u][v] == '.') {
            if (!CC[u][v]) DFS(u, v);
        }
        else ++Pcnt;
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &m, &n, &q);
    fto(i, 0, m-1) scanf("%s", &a[i]);

    fto(i, 0, m-1) {
        fto(j, 0, n-1) {
            if (!CC[i][j] && a[i][j] == '.') {
                ++CCcnt;
                Pcnt = 0;
                DFS(i, j);
                cnt[CCcnt] = Pcnt;
            }
        }
    }
//    fto(i, 0, m-1) {
//        fto(j, 0, n-1) printf("%d ", CC[i][j]);
//        printf("\n");
//    }

    fto(i, 1, q) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", cnt[CC[x-1][y-1]]);
    }

    return 0;
}