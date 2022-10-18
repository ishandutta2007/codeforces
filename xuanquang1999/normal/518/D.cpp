#include <bits/stdc++.h>
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define maxN 2005

using namespace std;

int n, t;
double p, f[maxN][maxN], ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> p >> t;

    f[0][0] = 1;
    fto(i, 0, t)
        fto(j, 0, n) if (j == n) f[i+1][j]+=f[i][j];
        else {
            f[i+1][j+1]+=f[i][j]*p;
            f[i+1][j]+=f[i][j]*(1-p);
        }
//    fto(i, 0, t) {
//        fto(j, 0, n) cout << f[i][j] << " ";
//        printf("\n");
//    }

    fto(j, 0, n) ans+=f[t][j]*j;
    printf("%.101g", ans);
}