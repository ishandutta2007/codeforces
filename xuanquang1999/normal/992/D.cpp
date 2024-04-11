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
#define maxN 200005
#define MOD 1000000007
#define oo 2000000000000000007LL
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
    if (a >= oo/b) return oo;
    return a*b;
}

int n, k, a[maxN], nxt[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 1, n) scanf("%d", &a[i]);

    nxt[n+1] = n+1;
    fdto(i, n, 1) nxt[i] = (a[i] == 1) ? nxt[i+1] : i;

    int ans = 0;
    fto(l, 1, n) {
        ll prod = 1, sum = 0;
        int r = l;
        while (r <= n) {
            prod = mul(prod, a[r]);
            if (prod == oo) break;
            sum += a[r];
            if (prod%sum == 0 && prod/sum == k) {
//                printf("%d %d %lld %lld\n", l, r, prod, sum);
                ++ans;
            }

            ll x = prod - k*sum;
            if (x%k == 0) {
                ll pos = r+x/k;
                if (r < pos && pos < nxt[r+1]) {
//                    printf("%d %d\n", l, pos);
                    ++ans;
                }
            }
            sum += nxt[r+1]-r-1;
            r = nxt[r+1];
        }
    }

    printf("%d", ans);

    return 0;
}