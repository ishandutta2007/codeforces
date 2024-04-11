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
#define y1 jksdhgsjrgbiwrbgij

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

const int MAXN = 2e5 + 5;

int n, b[MAXN];
ll a[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1)
        scanf("%d", &b[i]);

    int startInd = -1;
    fto(i, 0, n-1) {
        if (b[i%n] > b[(i+n-1)%n]) {
            startInd = i;
            break;
        }
    }

    if (startInd == -1) {
        if (b[0] == 0) {
            puts("YES");
            fto(i, 0, n-1)
                printf("1 ");
        } else
            puts("NO");
        return 0;
    }

    a[startInd] = b[startInd];
//    debug(startInd);
    fdto(i, startInd+n-1, startInd+1) {
        int cur = i%n, nxt = (i+1)%n, pre = (i+n-1)%n;

        ll q = (b[pre]-b[cur]+a[nxt])/a[nxt];
        a[cur] = q*a[nxt] + b[cur];
    }

    puts("YES");
    fto(i, 0, n-1)
        printf("%lld ", a[i]);

    return 0;
}