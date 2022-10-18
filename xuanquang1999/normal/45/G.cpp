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
#define maxX 18003005
#define maxN 6005
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

int n, ans[maxN];

int Find(int sum) {
    fdto(i, n, 1) {
        if (i <= sum) {
            sum -= i;
            ans[i] = 2;
        }
    }
}

bool isPrime(int n) {
    if (n < 2) return false;
    int lim = sqrt(n);
    fto(i, 2, lim)
        if (n%i == 0) return false;
    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) ans[i] = 1;

    int sum = n*(n+1)/2;
    if (!isPrime(sum)) {
        if (isPrime(sum-2)) {
            ans[2] = 2;
            sum -= 2;
        } else {
            if (sum%2 == 1) {
                ans[3] = 3;
                sum -= 3;
            }

            fto(i, 2, sum) {
                if (isPrime(i) && isPrime(sum-i)) {
                    Find(i);
                    break;
                }
            }
        }
    }

    fto(i, 1, n) printf("%d ", ans[i]);

    return 0;
}