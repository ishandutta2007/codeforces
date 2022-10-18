#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long
#define ull unsigned long long
#define maxN 105
#define maxQ 10005
#define oo 1000000007

int n, m, q, a[maxN][maxN], t[maxQ], r[maxQ], c[maxQ], x[maxQ];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &q);
    fto(iq, 1, q) {
        scanf("%d", &t[iq]);
        if (t[iq] == 1) scanf("%d", &r[iq]);
        else if (t[iq] == 2) scanf("%d", &c[iq]);
        else scanf("%d%d%d", &r[iq], &c[iq], &x[iq]);
    }

    fdto(iq, q, 1) {
        if (t[iq] == 1) {
            fdto(j, m-1, 1) swap(a[r[iq]][j], a[r[iq]][j+1]);
        }
        else if (t[iq] == 2) {
            fdto(i, n-1, 1) swap(a[i][c[iq]], a[i+1][c[iq]]);
        }
        else a[r[iq]][c[iq]] = x[iq];
    }

    fto(i, 1, n) {
        fto(j, 1, m) printf("%d ", a[i][j]);
        puts("");
    }


    return 0;
}