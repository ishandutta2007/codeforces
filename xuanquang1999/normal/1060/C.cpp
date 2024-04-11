#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
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

const int MAXN = 2005;
const int oo = 1000000007;

int m, n, a[MAXN], b[MAXN], x, minA[MAXN], minB[MAXN];

void calcMin(int a[], int n, int minA[]) {
    fto(i, 1, n)
        minA[i] = oo;
    fto(i, 1, n)
        fto(j, i, n)
            minA[j-i+1] = min(minA[j-i+1], a[j]-a[i-1]);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &m, &n);
    fto(i, 1, m) {
        scanf("%d", &a[i]);
        a[i] += a[i-1];
    }
    fto(i, 1, n) {
        scanf("%d", &b[i]);
        b[i] += b[i-1];
    }
    scanf("%d", &x);

    calcMin(a, m, minA);
    calcMin(b, n, minB);

    int ans = 0;
    fto(i, 1, m)
        fto(j, 1, n)
            if (1LL*minA[i]*minB[j] <= x)
                ans = max(ans, i*j);

    printf("%d", ans);

    return 0;
}