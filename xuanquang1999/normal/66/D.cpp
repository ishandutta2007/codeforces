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
#define maxX 18003005
#define maxN 55
#define oo 1000000000000000007LL
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

ll mul(ll a, ll b) {
    if (a*b/a != b) return oo;
    return min(oo, a*b);
}

int prime[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

int n;
bool avail[1<<9];
vector<int> ans;

int get(int mask) {
    int res = 1;
    fto(i, 0, 8) {
        if ((mask>>i)&1) res *= prime[i];
    }
    return res;
}

void mark(int mask) {
    ans.pb(get(mask));
    avail[mask] = false;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    if (n == 2) {
        puts("-1");
        return 0;
    }

    memset(avail, true, sizeof avail);
    mark(0b000011111);
    mark(0b111100001);
    mark(0b111110000);

    fto(mask, 0, (1<<9)-1) {
        if (sz(ans) == n) break;
        if (__builtin_popcount(mask) == 5 && avail[mask]) mark(mask);
    }

    for(int x: ans) printf("%d\n", x);

    return 0;
}