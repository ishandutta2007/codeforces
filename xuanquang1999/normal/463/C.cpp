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
#define maxN 2005
#define oo 1000000007
#define EPS 10e-9

int n, a[maxN][maxN], ans[2][2];
ll fcc[maxN][maxN], fcp[maxN][maxN], maxA[2];


int main() {
    scanf("%d", &n);
    fto(i, 1, n) {
        fto(j, 1, n) {
            scanf("%d", &a[i][j]);
            fcc[i][j] = fcc[i-1][j-1]+a[i][j];
            fcp[i][j] = fcp[i-1][j+1]+a[i][j];
        }
    }

    fto(i, 1, n) {
        fto(j, 1, n) {
            int k1 = min(n-i, n-j), k2 = min(n-i, j-1), p = (i+j)%2;
            ll sum = fcc[i+k1][j+k1] + fcp[i+k2][j-k2] - a[i][j];
            if (maxA[p] <= sum) {
                maxA[p] = sum;
                ans[p][0] = i, ans[p][1] = j;
            }
        }
    }

    cout << maxA[0]+maxA[1] << endl;
    fto(i, 0, 1)
        fto(j, 0, 1) cout << ans[i][j] << " ";

    return 0;
}