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
#define maxN 100005
#define maxB 20
#define oo 1000000007
#define EPS 10e-9

int n, m, x[maxN], y[maxN], ans[9];
set<int> r[maxN], c[maxN], ld[2*maxN-1], rd[2*maxN-1];

int main() {
    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        scanf("%d%d", &x[i], &y[i]);
        r[x[i]].insert(y[i]);
        c[y[i]].insert(x[i]);
        ld[x[i]-y[i]+n].insert(x[i]);
        rd[x[i]+y[i]-1].insert(x[i]);
    }
    fto(i, 1, m) {
        int cnt = 0;
        set<int>::iterator it;
        it = c[y[i]].find(x[i]);
        if (it != c[y[i]].begin()) ++cnt;
        if (it != --c[y[i]].end()) ++cnt;
        it = r[x[i]].find(y[i]);
        if (it != r[x[i]].begin()) ++cnt;
        if (it != --r[x[i]].end()) ++cnt;
        it = ld[x[i]-y[i]+n].find(x[i]);
        if (it != ld[x[i]-y[i]+n].begin()) ++cnt;
        if (it != --ld[x[i]-y[i]+n].end()) ++cnt;
        it = rd[x[i]+y[i]-1].find(x[i]);
        if (it != rd[x[i]+y[i]-1].begin()) ++cnt;
        if (it != --rd[x[i]+y[i]-1].end()) ++cnt;
        ++ans[cnt];
    }

    fto(i, 0, 8) printf("%d ", ans[i]);


    return 0;
}