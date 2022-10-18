//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<ll> point;
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
#define X real()
#define Y imag()
#define maxN 100005
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

point p[3];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(i, 0, 2) {
        int x, y; scanf("%d%d", &x, &y);
        p[i] = {x, y};
//        debug(i);
//        printf("%d %d\n", x, y);
//        printf("%lld %lld\n", p[i].X, p[i].Y);
    }

    point A = p[1]-p[0], B = p[2]-p[1];
    ll val = (conj(A)*B).Y;
//    printf("%lld %lld\n", A.X, A.Y);
//    printf("%lld %lld\n", B.X, B.Y);
    puts((val == 0) ? "TOWARDS" : ((val < 0) ? "RIGHT" : "LEFT"));

    return 0;
}