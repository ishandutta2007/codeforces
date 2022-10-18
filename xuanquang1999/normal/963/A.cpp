//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
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
#define maxN 100005
#define oo 1000000000000000007LL
#define sz(a) (int)a.size()
#define MOD 1000000009

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

int power(int x, int n) {
    if (n == 0) return 1;
    if (n%2 == 1) return (1LL*x*power(x, n-1))%MOD;
    int p = power(x, n/2);
    return (1LL*p*p)%MOD;
}

int n, a, b, k;
char s[maxN];

int Calc(int i, int j, int k, int n) {
//    printf("%d %d %d %d\n", i, j, k, n);
    if (n == 0) return 0;
    if (n%2 == 1) return (1LL*power(a, i)*power(b, j)+Calc(i+k, j-k, k, n-1))%MOD;
    int t = k*n/2;
    int p = Calc(i, j-t, k, n/2);
    return (1LL*p*(power(a, t)+power(b, t)))%MOD;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d%d", &n, &b, &a, &k);
    scanf("%s", s);

    int p = Calc(0, n-k+1, k, (n+1)/k);
    int ans = 0;

    fto(i, 0, k-1) {
        int x = ((1LL*p*power(a, i))%MOD * 1LL*power(b, k-i-1))%MOD;
//        debug(x);
        if (s[i] == '+') ans = (ans+x)%MOD;
        else ans = (ans-x+MOD)%MOD;
    }

    printf("%d", ans);

    return 0;
}