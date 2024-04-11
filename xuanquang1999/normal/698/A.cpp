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
#define maxN 105

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, a[maxN], f[maxN][3];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 0, n) f[i][0] = f[i][1] = f[i][2] = maxN;
    f[0][0] = f[0][1] = f[0][2] = 0;

    fto(i, 1, n) {
        f[i][0] = min(min(f[i-1][0], f[i-1][1]), f[i-1][2]) + 1;
        if (a[i]&2) f[i][2] = min(f[i-1][0], f[i-1][1]);
        if (a[i]&1) f[i][1] = min(f[i-1][0], f[i-1][2]);
    }

    printf("%d", min(f[n][0], min(f[n][1], f[n][2])));

    return 0;
}