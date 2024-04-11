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
#define maxN 55
#define MOD 1000003

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}


int n, a[maxN][maxN], f[5][maxN][maxN];

int cnt(int x, int x1, int y1, int x2, int y2) {
    return f[x][x2][y2]-f[x][x1-1][y2]-f[x][x2][y1-1]+f[x][x1-1][y1-1];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d\n", &n);
    fto(i, 1, n) {
        fto(j, 1, n) {
            char c;
            scanf("%c", &c);
            a[i][j] = c-'0';
            fto(x, 0, 4) f[x][i][j] = f[x][i-1][j]+f[x][i][j-1]-f[x][i-1][j-1];
            ++f[a[i][j]][i][j];
        }
        scanf("\n");
    }
//    fto(i, 1, n) {
//        fto(j, 1, n) printf("%d ", a[i][j]);
//        puts("");
//    }

    fto(x1, 1, n) {
        fto(x2, x1, n) {
            fto(y1, 1, n) {
                fto(y2, y1, n) {
                    bool ok = (cnt(4, x1, y1, x2, y2) == (x2-x1+1)*(y2-y1+1));
                    if (x1 > 1) ok &= (cnt(2, x1-1, y1, x1-1, y2) == y2-y1+1);
                    if (x2 < n) ok &= (cnt(2, x2+1, y1, x2+1, y2) == y2-y1+1);
                    if (y1 > 1) ok &= (cnt(2, x1, y1-1, x2, y1-1) == x2-x1+1);
                    if (y2 < n) ok &= (cnt(2, x1, y2+1, x2, y2+1) == x2-x1+1);
                    if (x1 > 1 && y1 > 1) ok &= (a[x1-1][y1-1] == 1);
                    if (x1 > 1 && y2 < n) ok &= (a[x1-1][y2+1] == 1);
                    if (x2 < n && y1 > 1) ok &= (a[x2+1][y1-1] == 1);
                    if (x2 < n && y2 < n) ok &= (a[x2+1][y2+1] == 1);
                    int u1 = max(1, x1-1), u2 = min(n, x2+1), v1 = max(1, y1-1), v2 = min(n, y2+1);
                    ok &= (cnt(0, 1, 1, n, n)-cnt(0, u1, v1, u2, v2) == n*n-(u2-u1+1)*(v2-v1+1));
                    if (ok) {
                        puts("YES");
                        return 0;
                    }
                }
            }
        }
    }

    puts("NO");

    return 0;
}