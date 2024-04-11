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
#define maxN 5005

int n, m, f[maxN][maxN], cnt[maxN];
char a[maxN][maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d\n", &n, &m);
    fto(i, 0, n-1) scanf("%s\n", &a[i]);

    fto(i, 0, n-1) {
        f[i][0] = a[i][0]-48;
        fto(j, 1, m-1)
            if (a[i][j] == '1') f[i][j] = f[i][j-1]+1;
    }

//    fto(i, 0, n-1) {
//        fto(j, 0, m-1) printf("%d ", f[i][j]);
//        printf("\n");
//    }

    int ans = 0;
    fto(j, 0, m-1) {
        memset(cnt, 0, sizeof(cnt));
        fto(i, 0, n-1) ++cnt[f[i][j]];
        //fto(i, 0, 10) printf("%d ", cnt[i]);
        //printf("\n");
        int cur = 0;
        fdto(i, m, 1) {
            cur+=cnt[i];
            ans = max(ans, i*cur);
        }
    }

    printf("%d", ans);

    return 0;
}