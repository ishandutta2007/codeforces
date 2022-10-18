//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
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
#define maxN 200005
#define oo 1000000000000000007LL

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, k, a[maxN];
ll d[maxN];
double d1[maxN], d2[maxN], f1[maxN], f2[maxN];

double Cost(int l, int r) {
    return d1[r]-d1[l-1]-d[l-1]*(d2[r]-d2[l-1]);
}

void Calc(int l, int r, int kmin, int kmax) {
    int m = (l+r)/2, best = 0;
    f2[m] = oo;
    fto(k, kmin, min(kmax, m)) {
        double x = f1[k]+Cost(k+1, m);
        if (x < f2[m]) f2[m] = x, best = k;
    }

    if (l < r) {
        Calc(l, m, kmin, best);
        Calc(m+1, r, best, kmax);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 1, n) scanf("%d", &a[i]);

    fto(i, 1, n) {
        d[i] = d[i-1]+a[i];
        d1[i] = d1[i-1]+1.0*d[i]/a[i];
        d2[i] = d2[i-1]+1.0/a[i];
    }

    fto(i, 1, n) f1[i] = Cost(1, i);
    fto(j, 2, k) {
        Calc(1, n, 1, n);
        fto(i, 1, n) f1[i] = f2[i];
    }

    printf("%.9f", f1[n]);

    return 0;
}