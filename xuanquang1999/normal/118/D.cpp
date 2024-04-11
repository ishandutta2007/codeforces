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
#define maxN 105
#define maxK 15
#define e 100000000

int n1, n2, k1, k2, f1[maxN][maxN], f2[maxN][maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
    f1[0][0] = 1; f2[0][0] = 1;
    fto(i, 0, n1)
        fto(j, 0, n2) {
            fto(k, 1, min(i, k1)) f1[i][j]=(f1[i][j]+f2[i-k][j])%e;
            fto(k, 1, min(j, k2)) f2[i][j]=(f2[i][j]+f1[i][j-k])%e;
        }

    printf("%d", (f1[n1][n2]+f2[n1][n2])%e);

    return 0;
}