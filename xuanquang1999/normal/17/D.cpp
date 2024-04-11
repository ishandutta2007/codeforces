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
#define maxN 1000005
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

void read(string &s) {
    char tmp[maxN];
    scanf("%s", tmp);
    s.assign(tmp);
}

string B, N;
int b, n, c;

int phi(int n) {
    int res = 1;
    fto(i, 2, sqrt(n)) {
        if (n%i == 0) {
            int cur = 1;
            while (n%i == 0) {
                cur *= i;
                n /= i;
            }
            res *= cur-cur/i;
        }
    }
    if (n > 1) res *= n-1;

    return res;
}

int power(int x, int n, int c) {
    if (n == 0) return 1%c;
    if (n&1) return (1LL*x*power(x, n-1, c))%c;
    int p = power(x, n/2, c);
    return (1LL*p*p)%c;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    read(B);
    read(N);
    scanf("%d", &c);

    fto(i, 0, sz(B)-1) b = (10LL*b+B[i]-'0')%c;
    fdto(i, sz(N)-1, 0) {
        if (N[i] == '0') N[i] = '9';
        else {
            --N[i];
            break;
        }
    }

    int p = phi(c);
    fto(i, 0, sz(N)-1) {
        ll x = 10LL*n+N[i]-'0';
        n = (x > p) ? p+x%p : x;
    }

//    debug(b);
//    debug(N);
//    debug(n);
//    debug(c);
//    debug(p);

    cout << (1LL*(b-1)*power(b, n, c)+c-1)%c+1;

    return 0;
}