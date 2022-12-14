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
#define maxX 2000005
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

bool isPrime[maxX];
set<int> s;
int n, x;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE


    memset(isPrime, true, sizeof isPrime);
    fto(i, 2, sqrt(maxX)) {
        for(int j = i*i; j <= maxX; j += i) isPrime[j] = false;
    }

//    int cnt = 0;
//    fto(i, 2, maxX-1) cnt += isPrime[i];
//
//    fto(i, 1, 100) printf("%d %d\n", i, isPrime[i]);
//
//    debug(cnt);

    scanf("%d%d", &n, &x);
    fto(i, 1, n) {
        int x; scanf("%d", &x);
        s.insert(x);
    }

    if (x == 2) puts("0");
    else if (s.find(1) != s.end()) puts("1");
    else {
        int cnt = 0;
        fto(p, 2, maxX-1) {
            if (isPrime[p]) {
                if (p >= x) break;
                if (s.find(p) == s.end()) {
                    puts("-1");
                    return 0;
                } else ++cnt;
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}