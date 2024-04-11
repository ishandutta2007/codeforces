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
#define maxN 300005
#define maxX 1000005
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

struct BIT {
    vector<ll> t;
    BIT(int n) {t.assign(n+1, 0);}
    void update(int p, int x) {
        for(int i = p; i < t.size(); i += i&(-i)) t[i] += x;
    }
    ll query(int p) {
        ll res = 0;
        for(int i = p; i > 0; i -= i&(-i)) res += t[i];
        return res;
    }
};

int p[maxX], D[maxX], a[maxN], n, m;
vector<int> prime;
set<int> s;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(i, 2, maxX-1) {
        if (p[i] == 0) {
            p[i] = i;
            prime.pb(i);
        }
        for(int j = 0; prime[j] <= (maxX-1)/i; ++j) {
            p[prime[j]*i] = prime[j];
            if (i%prime[j] == 0) break;
        }
    }

//    fto(i, 1, 50) printf("%d ", p[i]);
//    puts("");


    fto(i, 1, maxX-1) {
        int x = i; D[i] = 1;
        while (x > 1) {
            int k = p[x], cnt = 1;
            while (p[x] == k) {
                ++cnt;
                x /= k;
            }
            D[i] *= cnt;
        }
    }

    scanf("%d%d", &n, &m);
    fto(i, 1, n) scanf("%d", &a[i]);
    BIT t(n);

    set<int> s;
    fto(i, 1, n) {
        t.update(i, a[i]);
        if (a[i] > 2) s.insert(i);
    }
    s.insert(n+1);

    fto(i, 1, m) {
        int type, l, r;
        scanf("%d%d%d", &type, &l, &r);
        if (type == 1) {
            vector<int> toDel;
            for(auto it = s.lower_bound(l); *it <= r; ++it) {
                int p = *it;
                t.update(p, D[a[p]]-a[p]);
                a[p] = D[a[p]];
                if (a[p] <= 2) toDel.pb(p);
            }
            for(int p: toDel) s.erase(p);

//            debug(i);
//            fto(i, 1, n) printf("%d ", a[i]);
//            puts("");
//            for(int x: s) printf("%d ", x);
//            puts("");
        } else {
            printf("%lld\n", t.query(r)-t.query(l-1));
        }
    }

    return 0;
}