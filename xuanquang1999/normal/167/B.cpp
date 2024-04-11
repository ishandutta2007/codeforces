//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 205
#define oo 3000000000000000000LL

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
void read(vector<T> &v) {
    T x;
    cin >> x;
    v.pb(x);
}

int n, l, m, a[maxN];
double f[maxN][maxN][maxN], p[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &l, &m);
    fto(i, 0, n-1) scanf("%lf", &p[i]), p[i] /= 100;
    fto(i, 0, n-1) scanf("%d", &a[i]), ++a[i];

    f[0][0][0] = 1;
    fto(i, 0, n-1) {
        fto(j, 0, n-1) {
            fto(k, 0, n) {
                f[i+1][j][k] += f[i][j][k]*(1-p[i]);
                f[i+1][j+1][min(k+a[i], n)] += f[i][j][k]*p[i];
            }
        }
    }

    double ans = 0;
    fto(j, l, n) {
        fto(k, max(0, j-m), n) ans += f[n][j][k];
    }

    printf("%.9g", ans);

    return 0;
}