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
#define maxN 300005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int GCD(int a, int b) {
    return (b == 0) ? a : GCD(b, a%b);
}

int n, x[maxN], y[maxN];
map<pair<ii, ll>, int> m;

ll cntPair(ll x) {
    return (x*(x-1)/2);
}

ll sqr(ll x) {
    return x*x;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d%d", &x[i], &y[i]);

    fto(i, 1, n) {
        fto(j, i+1, n) {
            int a = y[j]-y[i];
            int b = x[i]-x[j];
            if (a < 0) a = -a, b = -b;
            int u = GCD(a, abs(b));
            a /= u; b /= u;
            if (a == 0 && b == -1) b = 1;
            ++m[mp(mp(a, b), sqr(x[i]-x[j])+sqr(y[j]-y[i]))];
        }
    }

    ll ans = 0;
//    ll cnt = 0;
//    forit(it, m) cnt += cntPair(it->ss);
//    forit(it, m) ans += (cnt-cntPair(it->ss))*cntPair(it->ss);
    forit(it, m) ans += cntPair(it->ss);

    cout << ans/2;

    return 0;
}