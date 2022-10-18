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
#define ftoa(i, l, r, a) for(int i = (l); i <= (r); i += a)
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
#define MOD 1000000007
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

int n, a[maxN], cnt[maxN];
vector<int> d[maxN];

int power(int x, int n) {
    if (n == 0) return 1;
    if (n&1) return ((ll)x*power(x, n-1))%MOD;
    int p = power(x, n/2);
    return ((ll)p*p)%MOD;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d", &a[i]);
        ++cnt[a[i]];
    }

    int m = *max_element(a+1, a+n+1);
    fto(x, 1, m) cnt[x] += cnt[x-1];
    fto(x, 1, m)
        ftoa(i, x, m, x) d[i].pb(x);

    int ans = 0;
    fto(x, 1, m) {
        int k = sz(d[x]), q[k];
        fto(i, 0, k-2) q[i] = cnt[d[x][i+1]-1]-cnt[d[x][i]-1];
        q[k-1] = cnt[m]-cnt[d[x][k-1]-1];

        int prod = 1;
        fto(i, 0, k-2) prod = ((ll)prod*power(i+1, q[i]))%MOD;
        prod = ((ll)prod*(power(k, q[k-1])-power(k-1, q[k-1])+MOD))%MOD;

        ans = (ans+prod)%MOD;
    }

    printf("%d", ans);

    return 0;
}