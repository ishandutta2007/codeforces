//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
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
#define maxN 200005
#define maxX 5005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

double f[3][maxX], ans;
int n, a[maxN], cnt[maxX];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    fto(i, 1, n) {
        fto(j, i+1, n) ++cnt[a[j]-a[i]];
    }

    f[0][0] = 1;
    fto(i, 1, 2) {
        fto(j, 1, maxX-1)
            fto(k, 0, maxX-j-1) f[i][k+j] += (2.0*cnt[j]*f[i-1][k])/(n*(n-1));
    }

    fto(j, 1, maxX-1) {
        fto(k, j+1, maxX-1) ans += (2.0*cnt[k]*f[2][j])/(n*(n-1));
    }

    cout << setprecision(10) << ans;

    return 0;
}