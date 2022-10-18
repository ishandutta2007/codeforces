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
#define maxN 20000000
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

vector<int> prime;
int d[maxN+1];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    for(int i = 2; i <= maxN; ++i) {
        if (d[i] == 0) {
            prime.pb(i);
            d[i] = i;
        }
        for(int j = 0; prime[j] <= maxN/i; ++j) {
            d[i*prime[j]] = prime[j];
            if (i%prime[j] == 0) break;
        }
    }

    int a, n;
    scanf("%d%d", &a, &n);

    ll ans = 0;
    fto(i, a, a+n-1) {
        int x = i, prod = 1;
        while (x > 1) {
            int p = d[x], cnt = 0;
            while (d[x] == p) {
                x /= p;
                ++cnt;
            }
            for(int i = 2; i <= cnt; i += 2) prod *= p*p;
        }
        ans += i/prod;
    }

    cout << ans;


    return 0;
}