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
#define maxN 35
#define maxN 35
#define maxK 55
#define oo 1000000007

int nTest, f[maxN][maxN][maxK];

int Solve(int n, int m, int k) {
    if (k < 0) return oo;
    if (k == 0 || n*m == k) return 0;
    if (f[n][m][k] > -1) return f[n][m][k];
    int res = oo;
    fto(i, 1, n-1) {
        int x1 = min(Solve(i, m, k), Solve(i, m, k-(n-i)*m));
        int x2 = min(Solve(n-i, m, k), Solve(n-i, m, k-i*m));
        res = min(res, m*m+min(x1, x2));
    }
    fto(j, 1, m-1) {
        int x1 = min(Solve(n, j, k), Solve(n, j, k-(m-j)*n));
        int x2 = min(Solve(n, m-j, k), Solve(n, m-j, k-j*n));
        res = min(res, n*n+min(x1, x2));
    }
    return (f[n][m][k] = res);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(i, 0, maxN-1)
        fto(j, 0, maxN-1)
            fto(k, 0, maxK-1) f[i][j][k] = -1;

    scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        printf("%d\n", Solve(n, m, k));
    }

    return 0;
}