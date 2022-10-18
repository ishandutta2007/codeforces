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
#define maxN 300005
#define MOD 1000
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

struct monster {
    int h, d, id;
    bool inline operator < (const monster &rhs) const {
        return (h-d > rhs.h-rhs.d);
    }
};

int n, a, b;
monster m[maxN];
bool inRes[maxN];
ll sum, ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &a, &b);
    fto(i, 1, n) {
        scanf("%d%d", &m[i].h, &m[i].d);
        m[i].id = i;
    }

    if (b == 0) {
        ll sum = 0;
        fto(i, 1, n) sum += m[i].d;
        cout << sum;
        return 0;
    }

    sort(m+1, m+n+1);

    int minCost = 0;

    int i = 1;
    while (i <= n) {
        if (m[i].d >= m[i].h) {
            --i;
            break;
        }
        sum += m[i].h;
        inRes[i] = true;
        if (i == b) {
            minCost = m[i].h-m[i].d;
            break;
        }
        ++i;
    }

    ++i;
    while (i <= n) {
        sum += m[i].d;
        ++i;
    }

//    fto(i, 1, n) printf("%d %d %d\n", m[i].h, m[i].d, m[i].id);
//    debug(sum);

    ans = sum;
    fto(i, 1, n) {
        ll old = max(0, m[i].h-m[i].d);
        ll ext = max(0LL, (1LL<<a)*m[i].h-m[i].d);
        ll cur = sum + ext;

        if (inRes[i]) {
            cur -= old;
        } else {
            cur -= minCost;
        }

        ans = max(ans, cur);
    }

    cout << ans;

    return 0;
}