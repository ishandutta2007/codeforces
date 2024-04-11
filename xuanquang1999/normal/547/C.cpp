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
#define maxX 500005
#define maxN 200005
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

int n, q, np[maxX], a[maxN], f[maxX];
bool avail[maxX];
ll ans;

void update(int n, int x) {
    vector<int> d;
    while (n != 1) {
        int i = np[n];
        //debug(i);
        while (np[n/i] == i) n /= i;
        n /= i;
        d.pb(i);
    }

//    debug(n);
//    for(int p: d) printf("%d ", p);
//    puts("");

    fto(b, 0, (1<<sz(d))-1) {
        int cnt = 0, p = 1;
        fto(i, 0, sz(d)-1) {
            if ((b>>i)&1) {
                ++cnt; p *= d[i];
            }
        }
        int sign = (cnt&1) ? -1 : 1;
        if (x == 1) {
            ans += f[p]*sign;
            ++f[p];
        } else {
            --f[p];
            ans -= f[p]*sign;
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    np[1] = 1;
    fto(i, 2, maxX-1) {
        if (!np[i]) {
            for(int j = i; j <= maxX; j += i) {
                if (!np[j]) np[j] = i;
            }
        }
    }
//    fto(i, 1, 15) printf("%d ", np[i]);
//    puts("");

    scanf("%d%d", &n, &q);
    fto(i, 1, n) scanf("%d", &a[i]);

    fto(i, 1, q) {
        int x; scanf("%d", &x);
        if (avail[x]) update(a[x], -1);
        else update(a[x], 1);
        avail[x] ^= true;

        printf("%lld\n", ans);
    }

    return 0;
}