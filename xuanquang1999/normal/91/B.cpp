using namespace std;
#include <bits/stdc++.h>
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100000+5
#define maxM 16+1
//#define maxC 1000000009

int e2[maxM], sp[maxM][maxN], ans[maxN], n, m;
ii a[maxN];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    e2[0] = 1;
    fto(i, 1, maxM) e2[i]=e2[i-1]*2;

    scanf("%d", &n);
    fto(i, 0, n-1) {
        scanf("%d", &a[i].fi);
        a[i].se = i;
    }

    sort(a, a+n);
    m = trunc(log2(n));

    fto(j, 0, n-1) sp[0][j] = j;
    fto(i, 1, m)
        fto(j, 0, n-e2[i]) {
            int x = sp[i-1][j], y = sp[i-1][j+e2[i-1]];
            if (a[x].se > a[y].se) sp[i][j] = x; else sp[i][j] = y;
        }

//    fto(i, 0, m) {
//        fto(j, 0, n-e2[i]) printf("%d ", sp[i][j]);
//        printf("\n");
//    }


    ans[a[0].se] = -1;
    fto(i, 1, n-1) {
        int m = trunc(log2(i));
        int x = sp[m][0], y = sp[m][i-e2[m]+1];
        //int p = max(-1, max(a[x].se, a[y].se)-i);
        //printf("%d %d %d\n", i, x, y);
        ans[a[i].se] = max(-1, max(a[x].se, a[y].se)-a[i].se-1);
    }

    fto(i, 0, n-1) printf("%d ", ans[i]);

    return 0;
}