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
#define maxN 2000000005
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

bool isPrime(int n) {
    if (n < 2) return false;
    int lim = sqrt(n);
    fto(i, 2, lim)
        if (n%i == 0) return false;
    return true;
}

vector<int> prime;
int a, b, k, n;
ll res;

void Try(int i, ll x, int sign) {
    if (i == sz(prime) || prime[i] >= k || x*prime[i] > n) {
        res += (n/x)*sign;
        return;
    }
    Try(i+1, x, sign);
    Try(i+1, x*prime[i], -sign);
}

int Solve(int x) {
    n = x;
    if (n == 0) return 0;
    if (k > n) return 1;

    res = 0;
    Try(0, 1, 1);
    return res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &a, &b, &k);
    if (!isPrime(k)) {
        puts("0");
        return 0;
    }

    fto(i, 2, sqrt(maxN))
        if (isPrime(i)) prime.pb(i);

    cout << Solve(b/k)-Solve((a-1)/k);


    return 0;
}