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
#define sz(a) (int)a.size()
#define maxN 1000005
#define maxK 20
#define oo 1000000000000000007LL
#define MOD 1000000007
#define EPS 1e-9

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

struct BIT {
private: vector<ll> t;
public:
    BIT(int n) {t.assign(n+1, 0);}
    void update(int p, ll x) {
        for(int i = p; i < sz(t); i += i&(-i)) t[i] += x;
    }
    ll query(int p) {
        ll res = 0;
        for(int i = p; i > 0; i -= i&(-i)) res += t[i];
        return res;
    }
};

int n;
ll f[3][maxN], ans;
ii a[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d", &a[i].ff);
        a[i].ss = i;
    }

    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);

    fto(j, 1, n) f[0][j] = 1;
    fto(i, 1, 2) {
        BIT t(n);
        fto(j, 1, n) {
            f[i][j] = t.query(a[j].ss-1);
            t.update(a[j].ss, f[i-1][j]);
        }
    }

    fto(j, 1, n) ans += f[2][j];
    printf("%lld", ans);

    return 0;
}