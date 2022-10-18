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

int n, a[maxN];
ll k;
set<int> s;

void Generate() {
    n = rand()%10+1; k = rand()%10000+1;
    fto(i, 1, n) a[i] = rand()%100+1;
}

ll BruteForce() {
    fdto(x, 100000, 1) {
        int cnt = 0;
        fto(i, 1, n) {
            if (a[i]%x != 0) cnt += (a[i]/x+1)*x - a[i];
        }
        if (cnt <= k) return x;
    }
}

ll Solve() {
    s.clear();
    fto(i, 1, n) {
        s.insert(a[i]);
        fto(x, 1, sqrt(a[i]-1)+1) {
            if (x == 1 || (a[i]-1)/x != (a[i]-1)/(x-1)) s.insert(x);
            s.insert((a[i]-1)/x+1);
        }
    }

    if (*s.begin() == 0) s.erase(s.begin());

//    for(int x: s) printf("%d ", x);
//    puts("");

    ll ans = 0;
    for(int l: s) {
        ll p = k, q = 0;
        fto(i, 1, n) {
            p += a[i];
            q += (a[i]-1)/l + 1;
        }
        ll x = p/q;
//        printf("%d %lld %lld %lld\n", l, p, q, x);
        if (x >= l) ans = max(ans, x);
    }

    return ans;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    srand(time(NULL));

//    while (true) {
//        Generate();
//        ll x = BruteForce(), y = Solve();
//        if (x != y) {
//            printf("%d %lld\n", n, k);
//            fto(i, 1, n) printf("%d ", a[i]);
//            puts("");
//        }
//    }

    cin >> n >> k;
    fto(i, 1, n) scanf("%d", &a[i]);
    cout << Solve();

//    debug(BruteForce());
//    debug(Solve());


    return 0;
}