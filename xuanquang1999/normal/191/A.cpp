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
#define maxN 500005
int dp1[26][26], dp2[26][26], n;


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int ans = 0;
    scanf("%d\n", &n);
    fto(i, 1, n) {
        char s[10];
        scanf("%s\n", &s);

        int l = strlen(s);
        int d1 = s[0]-97, d2 = s[l-1]-97;
        dp2[d1][d2] = max(dp2[d1][d2], l);

        fto(j, 0, 25)
            if (dp1[j][d1] > 0) dp2[j][d2] = max(dp2[j][d2], dp1[j][d1]+l);

        fto(j, 0, 25) ans = max(ans, dp2[j][j]);

        fto(j, 0, 25)
            fto(k, 0, 25) dp1[j][k] = dp2[j][k];
    }

//    fto(i, 1, n) {
//        fto(j, 0, 25) {
//            fto(k, 0, 25) printf("%d ", dp[i][j][k]);
//            printf("\n");
//        }
//        printf("\n");
//    }

    printf("%d", ans);

    return 0;
}