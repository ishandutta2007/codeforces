//84104971101048411497
#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define maxN 1005
#define oo 1000000000000000007LL
#define EPS 10e-9

int n, k;

int main() {
    scanf("%d%d", &n, &k);
    printf("%d\n", (6*n-1)*k);
    fto(i, 0, n-1) printf("%d %d %d %d\n", (6*i+1)*k, (6*i+2)*k, (6*i+3)*k, (6*i+5)*k);

    return 0;
}