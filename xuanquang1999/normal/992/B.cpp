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
#define MOD 1000000007
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

int l, r, x, y;

bool in(int l, int r, int x) {return (l <= x && x <= r);}

int gcd(int a, int b) {return (b == 0) ? a : gcd(b, a%b);}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d%d", &l, &r, &x, &y);
    if (y%x != 0) {
        puts("0");
        return 0;
    }

    y /= x;
    l = (l+x-1)/x;
    r /= x;

    vector<int> d;
    int ans = 0;
    fto(i, 1, sqrt(y)) {
        if (y%i == 0 && in(l, r, i) && in(l, r, y/i) && gcd(i, y/i) == 1) {
            ++ans;
            if (i*i != y) ++ans;
        }
    }

    printf("%d", ans);

    return 0;
}