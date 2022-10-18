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

const int MAXN = 100005;

int n, k, m, a[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &k, &m);
    fto(i, 1, n) scanf("%d", &a[i]);

    sort(a+1, a+n+1);

    double ans = 0;

    ll sum = accumulate(a+1, a+n+1, 0LL);

    fto(i, 1, min(n, m+1)) {
        int cnt = n-i+1;
        int x = min(1LL*cnt*k, 1LL*(m-i+1));
        ans = max(ans, 1.0*(sum + x)/cnt);
        sum -= a[i];
    }

    printf("%.15g", ans);

    return 0;
}