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
#define maxN 100005
#define oo 1000000007
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

int n, dp[maxN], sumDp[maxN], trace[maxN];
vector<ii> p[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(l, 1, n) {
        int sum = l;
        fto(r, l+1, n) {
            sum += r;
            if (sum > n) break;
            p[sum].pb(mp(l-1, r));
        }
    }
    fto(i, 1, n) trace[i] = oo;
    fto(i, 1, 2) dp[i] = sumDp[i] = 0;
    fto(i, 3, n) {
        set<int> s;
        forit(it, p[i]) {
            int l = it->ff, r = it->ss, x = sumDp[r]^sumDp[l];
            s.insert(x);
            if (x == 0 && r-l < trace[i]) trace[i] = r-l;
        }
        while (s.count(dp[i])) ++dp[i];
        sumDp[i] = sumDp[i-1]^dp[i];
    }

    if (dp[n]) printf("%d", trace[n]);
    else puts("-1");

    return 0;
}