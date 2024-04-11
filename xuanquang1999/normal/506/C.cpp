//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define X real()
#define Y imag()
#define maxN 100005
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

struct bamboo {ll d, cur; int id;};

struct compBamboo {
    bool operator() (const bamboo &l, const bamboo &r) {
        if (l.d > r.d) return true;
        if (l.d < r.d) return false;
        if (l.cur > r.cur) return true;
        if (l.cur < r.cur) return false;
        if (l.id > r.id) return true;
        return false;
    }
};

int n, m, k, p, a[maxN], h[maxN];

bool Check(ll st) {
    priority_queue<bamboo, vector<bamboo>, compBamboo> s;
    fto(i, 1, n) {
        ll x = (a[i] != 0) ? (st/a[i]) : oo;
        s.push({x, st, i});
    }

//    debug(st);
//    forit(it, s) printf("%lld %lld %d\n", it->d, it->cur, it->id);

    ll hammerLeft = m*k;
    fto(i, 1, m) {
        fto(j, 1, k) {
            ll d = s.top().d, cur = s.top().cur; int id = s.top().id;
            if (d >= m) break;
            if (d < i) return false;

            s.pop();
            ll x = (a[id] != 0) ? ((cur+p)/a[id]) : oo;
            s.push({x, cur+p, id});
            --hammerLeft;
        }
    }

    while (!s.empty()) {
        ll cur = s.top().cur; int id = s.top().id;
        if (cur-1LL*a[id]*m < h[id]) hammerLeft -= (h[id]-(cur-1LL*a[id]*m)+p-1)/p;
        s.pop();
    }

    return (hammerLeft >= 0);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d%d", &n, &m, &k, &p);
    fto(i, 1, n) scanf("%d%d", &h[i], &a[i]);

    ll lo = 0, hi = 0, res = oo;
    fto(i, 1, n) {
        lo = max(lo, 1LL*a[i]);
        hi = max(hi, h[i] + 1LL*a[i]*m);
    }

    while (lo <= hi) {
        ll mid = (lo+hi)/2;
        if (Check(mid)) {
            res = mid;
            hi = mid-1;
        } else lo = mid+1;
    }

    printf("%lld", res);

    return 0;
}