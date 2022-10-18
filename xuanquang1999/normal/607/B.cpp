//84104971101048411497
#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ii pair<int, int>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define maxN 505
#define oo 1000000007
#define EPS 10e-9

int n, a[maxN], f[maxN][maxN];

int Solve(int l, int r) {
    if (l >= r) return 1;
    if (f[l][r] != -1) return f[l][r];

    int res = (a[l] == a[r]) ? Solve(l+1, r-1) : oo;
    fto(p, l, r-1) res = min(res, Solve(l, p) + Solve(p+1, r));
    return f[l][r] = res;
}

int main() {
    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(l, 1, n)
        fto(r, 1, n) f[l][r] = -1;

    cout << Solve(1, n);

    return 0;
}