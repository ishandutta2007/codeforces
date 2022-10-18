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

ll n, k;
vector<int> ans;

bool Solve(ll n, int y) {
//    debug(y);

    int lim = max(0, y);
    if (y < 0) n <<= (-y);

    ans.clear();
//    debug(n);
    while (n > 0) {
        fdto(i, lim, 0) {
            if ((1LL<<i) <= n) {
//                debug(i);
                ans.pb(i);
                n -= 1LL<<i;
                break;
            }
        }
        if (sz(ans) > k) return false;
    }

    while (sz(ans) < k) {
        int x = ans.back(); ans.pop_back();
        fto(i, 0, 1) ans.pb(x-1);
    }
    if (y < 0) {
        fto(i, 0, k-1) ans[i] += y;
    }

    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> k;
    if (__builtin_popcountll(n) > k) {
        puts("No");
        return 0;
    }

//    Solve(3);

    int y;
    for(int i = 0; ; ++i)
        if ((n<<i) > k) {y = -i; break;}

    for(; ; ++y) {
        ll x = (y > 0) ? (k<<y) : (k>>(-y));
        if (Solve(n, y)) {
            puts("Yes");
            for(int x: ans) printf("%d ", x);
            return 0;
        }
    }


    return 0;
}