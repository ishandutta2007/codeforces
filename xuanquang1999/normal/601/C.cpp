//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 105
#define maxM 1005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, a[maxN], kle_rank;
long double f[2][maxN*maxM], sum[maxN*maxM], lower[maxN], higher[maxN], ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) scanf("%d", &a[i]);
    if (m == 1) {
        puts("1");
        return 0;
    }
    f[0][0] = m-1;
//    debuga1(f[0], 0, n*m);
    fto(i, 1, n) {
        kle_rank += a[i];
        sum[0] = f[0][0];
        fto(j, 1, i*m) sum[j] = sum[j-1]+f[0][j];
//        cout << sum[i*m] << endl;
        fto(j, 1, i*m) {
            f[1][j] = sum[j-1];
            if (j-m-1 >= 0) f[1][j] -= sum[j-m-1];
            if (j-a[i] >= 0) f[1][j] -= f[0][j-a[i]];
            f[1][j] /= (m-1);
        }
        fto(j, 0, i*m) f[0][j] = f[1][j];
//        debuga1(f[0], 0, n*m);
    }
    sum[0] = f[0][0];
    fto(j, 1, n*m) sum[j] = sum[j-1]+f[0][j];
    cout << setprecision(10);
    cout << sum[kle_rank-1]+1 << endl;




    return 0;
}