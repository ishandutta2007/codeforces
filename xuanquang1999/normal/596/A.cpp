//84104971101048411497
#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define forrit(rit, type, var) for(type::reverse_iterator rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define ll long long
#define ull unsigned long long
#define mapii map<int, int>
#define maxN 100005
#define oo 1000000007

int n, x[2][4], cnt[2005];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(j, 0, n-1)
        fto(i, 0, 1) scanf("%d", &x[i][j]);

    //fto(i, 0, 1) sort(x[i], x[i]+4);

    fto(i, 0, 1) {
        memset(cnt, 0, sizeof(cnt));
        fto(j, 0, n-1) ++cnt[x[i][j]+1000];

        int cntDif = 0, maxCnt = 0;
        fto(x, 0, 2000) {
            maxCnt = max(maxCnt, cnt[x]);
            cntDif += (cnt[x] > 0);
        }
//        debug(cntDif);
//        debug(maxCnt);

        if (cntDif != 2 || maxCnt > 2) {
            puts("-1");
            return 0;
        }
    }

    fto(i, 0, 1) sort(x[i], x[i]+n);
    printf("%d", (x[0][n-1]-x[0][0])*(x[1][n-1]-x[1][0]));

    return 0;
}