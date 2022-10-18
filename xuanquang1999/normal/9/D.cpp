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
#define maxN 55
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

int n, h;
ll f[maxN][maxN][maxN];

ll Solve(int l, int r, int h) {
    if (l > r) return 1;
    if (h <= 0) return 0;
    if (f[l][r][h] != -1) return f[l][r][h];
//    printf("%d %d %d\n", l, r, h);
    ll res = 0;
    fto(i, l, r) {
//        debug(i);
//        debug(Solve(l, i-1, h-1));
//        debug(Solve(i+1, r, h-1));
        res += Solve(l, i-1, h-1) * Solve(i+1, r, h-1);
    }
    return (f[l][r][h] = res);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &h);

    fto(l, 0, n) {
        fto(r, 0, n) {
            fto(k, 0, n) f[l][r][k] = -1;
        }
    }

    cout << Solve(1, n, n)-Solve(1, n, h-1);

    return 0;
}