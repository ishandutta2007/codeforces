using namespace std;
#include <bits/stdc++.h>
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define ii pair<int, int>
#define mp make_pair
#define pb push_back

int R, S, P;
double f[105][105][105];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &R, &S, &P);
    f[R][S][P] = (double)1;
    fdto(sum, R+S+P, 1)
        fdto(r, R, 0)
            fdto(s, S, 0) {
                int p = sum-r-s;
                if (p < 0 || p > P) continue;
                if ((r==0 && s==0) || (s==0 && p==0) || (p==0 && r==0)) continue;
                int wayS = r*s, wayP = s*p, wayR = p*r;
                int total = wayS+wayP+wayR;
                double cur = f[r][s][p];
                if (r > 0) f[r-1][s][p]+=cur*wayR/total;
                if (s > 0) f[r][s-1][p]+=cur*wayS/total;
                if (p > 0) f[r][s][p-1]+=cur*wayP/total;
            }

    double ansR = 0, ansS = 0;
    fto(r, 1, R) ansR+=f[r][0][0];
    fto(s, 1, S) ansS+=f[0][s][0];
    printf("%.17g %.17g %.17g", ansR, ansS, 1-ansR-ansS);

    return 0;
}