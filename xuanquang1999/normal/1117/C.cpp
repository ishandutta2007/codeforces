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
#define y1 ipanhefioaenf

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
const ll oo = 1e15;

ll x1, y1, x2, y2;
int n;
char s[MAXN];

bool check(ll t) {
    ll deltaX = 0, deltaY = 0;
    fto(i, 0, n-1) {
        ll step = (t - i + n - 1)/n;
        if (s[i] == 'U')
            deltaY += step;
        else if (s[i] == 'D')
            deltaY -= step;
        else if (s[i] == 'L')
            deltaX -= step;
        else
            deltaX += step;
    }

    return llabs(x1 + deltaX - x2) + llabs(y1 + deltaY - y2) <= t;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> x1 >> y1 >> x2 >> y2;
    scanf("%d", &n);
    scanf("%s", s);

    ll lo = 0, hi = oo, res = -1;
    while (lo <= hi) {
        ll mid = (lo + hi)/2;
        if (check(mid)) {
            res = mid;
            hi = mid - 1;
        } else
            lo = mid + 1;
    }

    cout << res;

    return 0;
}