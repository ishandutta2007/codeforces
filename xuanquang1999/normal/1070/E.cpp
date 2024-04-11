#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()
#define left apeifhae
#define right apoefbnuaebfh

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

const int MAXN = 200005;

int nTest, n, m, a[MAXN];
pii ans;
vector<int> pos[MAXN], val;
ll t;

bool check(int k) {
//    debug(k);
    int r = (k-1)%m+1;
    k -= r;

    set<pii> lo, hi;
    ll sum = 0;
//    printf("%d %d\n", k, r);
    for(int x: val) {
        for(int i: pos[x]) {
            pii p = {i, x};
            sum += 2*x;
            lo.insert(p);

            while (!lo.empty() && !hi.empty() && *lo.rbegin() > *hi.begin()) {
                pii plo = *lo.rbegin(); lo.erase(plo);
                pii phi = *hi.begin(); hi.erase(phi);
                lo.insert(phi); hi.insert(plo);
                sum += phi.ss - plo.ss;
            }

            if (sz(lo) > k || sz(hi) < r) {
                pii plo = *lo.rbegin(); lo.erase(plo);
                hi.insert(plo);
                sum -= plo.ss;
            }

            if (sz(hi) > r) {
                pii phi = *hi.rbegin(); hi.erase(phi);
                sum -= phi.ss;
            }
//            printf("%d %d %lld\n", x, i, sum);
        }

        if (sz(lo) + sz(hi) >= k+r && sum <= t) {
            ans = {k+r, x};
            return true;
        }
    }

    return false;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        scanf("%d%d%lld", &n, &m, &t);
        fto(i, 1, n) {
            scanf("%d", &a[i]);
            if (sz(pos[a[i]]) == 0)
                val.pb(a[i]);
            pos[a[i]].pb(i);
        }
        sort(val.begin(), val.end());

//        for(int x: val) {
//            debug(x);
//            for(int i: pos[x]) printf("%d ", i);
//            puts("");
//        }

        ans = {0, 1};
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (check(mid))
                lo = mid+1;
            else
                hi = mid-1;
        }

        printf("%d %d\n", ans.ff, ans.ss);


        for(int x: val)
            pos[x].clear();
        val.clear();
    }

    return 0;
}