//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
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
#define maxN 505

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int m, n, q, a[maxN][maxN], fh[maxN][maxN], fv[maxN][maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d\n", &m, &n);
    fto(i, 1, m) {
        fto(j, 1, n) {
            char c;
            scanf("%c", &c);
            a[i][j] = (c == '#');
        }
        scanf("\n");
    }
//    fto(i, 1, m) {
//        fto(j, 1, n) printf("%d ", a[i][j]);
//        puts("");
//    }

    fto(i, 1, m) {
        fto(j, 2, n) {
            fh[i][j] = fh[i][j-1]+fh[i-1][j]-fh[i-1][j-1];
            if (a[i][j-1] == 0 && a[i][j] == 0) ++fh[i][j];
        }
    }
    fto(i, 2, m) {
        fto(j, 1, n) {
            fv[i][j] = fv[i][j-1]+fv[i-1][j]-fv[i-1][j-1];
            if (a[i-1][j] == 0 && a[i][j] == 0) ++fv[i][j];
        }
    }

    scanf("%d", &q);
    fto(i, 1, q) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", (fh[x2][y2]-fh[x2][y1]-fh[x1-1][y2]+fh[x1-1][y1]) + (fv[x2][y2]-fv[x2][y1-1]-fv[x1][y2]+fv[x1][y1-1]));
    }

    return 0;
}