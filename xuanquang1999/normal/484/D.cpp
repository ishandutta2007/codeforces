//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
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
#define maxN 1000005
#define oo 2000000007
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, a[maxN], l[maxN], b[maxN];
ll dp[maxN];

int sign(int x) {return (x > 0) ? 1 : ((x < 0) ? -1 : 0);}
ll maximize(ll &a, ll b) {a = max(a, b);}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d", &a[i]);
//        if (i > 1 && a[i] == a[i-1]) {
//            --i;
//            --n;
//        }
    }

//    fto(i, 1, n) printf("%d ", a[i]);
//    puts("");

    fto(i, 1, n-1) b[i] = a[i+1]-a[i];

//    fto(i, 1, n-1) printf("%d ", b[i]);
//    puts("");

    l[1] = 1;
    fto(i, 2, n-1) {
        l[i] = (sign(b[i-1])*sign(b[i]) > 0) ? l[i-1] : i;
    }

//    fto(i, 1, n-1) printf("%d ", l[i]);
//    puts("");

    dp[0] = 0;
    dp[1] = abs(b[1]);
    fto(i, 2, n-1) {
        dp[i] = max(dp[i-1], dp[l[i]-2]+abs(a[i+1]-a[l[i]]), dp[l[i]-1]+abs(a[i+1]-a[l[i]+1]));
    }

    printf("%lld", dp[n-1]);

    return 0;
}