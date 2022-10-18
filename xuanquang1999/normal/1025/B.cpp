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

ll GCD(ll a, ll b) {
    return (b == 0) ? a : GCD(b, a%b);
}

const int MAXN = 2e5 + 5;

int n, a[MAXN], b[MAXN];

void addDiv(vector<int> &prime, int x) {
    fto(i, 2, sqrt(x)) {
        if (x%i == 0) {
            prime.pb(i);
            while (x%i == 0) x /= i;
        }
    }
    if (x > 1) prime.pb(x);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d%d", &a[i], &b[i]);

    vector<int> prime;
    addDiv(prime, a[1]);
    addDiv(prime, b[1]);

    for(int d: prime) {
        bool ok = true;
        fto(i, 1, n) {
            if (a[i]%d != 0 && b[i]%d != 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            printf("%d", d);
            return 0;
        }
    }

    puts("-1");

    return 0;
}