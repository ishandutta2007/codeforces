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
#define maxN 200005
#define oo 1000000000000000007LL
#define EPS 1e-9
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

int GCD(int a, int b) {
    return (b == 0) ? a : GCD(b, a%b);
}

pair<ll, ll> GCDEx(ll a, ll b, ll xa, ll xb) {
    if (b == 0) return mp(a, xa);
    return GCDEx(b, a%b, xb, xa-xb*(a/b));
}

int n, m, cnt[maxN], dp[maxN], trace[maxN];
bool forbid[maxN];
vector<int> allX[maxN], _div[maxN], prod;

int Solve(int i, int j) {
    int a = i, b = -m, c = j;
    pair<ll, ll> p = GCDEx(a, b, 1, 0);

    ll x = p.ss;
    x *= c/p.ff;
    return (x%m+m)%m;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        int x;
        scanf("%d", &x);
        forbid[x] = true;
    }

    fto(x, 0, m-1) {
        if (!forbid[x]) {
            int d = GCD(x, m);
            ++cnt[d];
            allX[d].pb(x);
        }
    }

//    fto(x, 1, m) {
//        debug(x);
//        forit(it, allX[x]) printf("%d ", *it);
//        puts("");
//    }

    fto(i, 1, m) {
        for(int j = i*2; j <= m; j += i) _div[j].pb(i);
    }

    fto(i, 1, m) {
        dp[i] = cnt[i];
        forit(it, _div[i]) {
            int x = *it;
            if (dp[x]+cnt[i] > dp[i]) {
                dp[i] = dp[x]+cnt[i];
                trace[i] = x;
            }
        }
    }
//    fto(i, 1, m) printf("%d %d\n", dp[i], trace[i]);

    int i = m;
    while (i != 0) {
        forit(it, allX[i]) prod.pb(*it);
        i = trace[i];
    }
    prod.pb(1);
    reverse(prod.begin(), prod.end());

//    forit(it, prod) printf("%d ", *it);
//    puts("");

    printf("%d\n", sz(prod)-1);
    fto(i, 0, sz(prod)-2) printf("%d ", Solve(prod[i], prod[i+1]));

    return 0;
}