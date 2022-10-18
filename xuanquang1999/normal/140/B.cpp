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
#define maxN 305

int n, p[maxN][maxN], a[maxN], ans[maxN], maxP[maxN], maxC, semaxC;


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        p[i][0] = n+1;
        fto(j, 1, n) {
            int x;
            scanf("%d", &x);
            p[i][x] = j;
        }
    }
    fto(i, 1, n) {
        int x;
        scanf("%d", &x);
        a[x] = i;
    }
    a[0] = n+1;

    maxC = 0; semaxC = 0;
    fto(i, 1, n) {
        if (a[i] < a[maxC]) {
            semaxC = maxC;
            maxC = i;
        }
        else if (a[i] < a[semaxC]) semaxC = i;
        fto(j, 1, n) {
            if (maxC != j) {
                //printf("%d %d %d %d\n", i, j, maxC, maxP[j]);
                if (p[j][maxC] < p[j][maxP[j]]) {
                    maxP[j] = maxC;
                    ans[j] = i;
                }
            }
            else if (semaxC != 0) {
                if (p[j][semaxC] < p[j][maxP[j]]) {
                    maxP[j] = semaxC;
                    ans[j] = i;
                }
            }
        }
        //printf("%d %d\n", maxC, semaxC);
    }

    fto(i, 1, n) printf("%d ", ans[i]);

    return 0;
}