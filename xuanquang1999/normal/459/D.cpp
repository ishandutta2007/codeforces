#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

template<class Node_CItr, class Node_Itr, class Cmp_Fn, class _Alloc>
struct my_node_update {
    typedef int metadata_type;

    int order_of_key(ii x) {
        auto it = node_begin();
        int ans = 0;
        while (it != node_end()) {
            auto l = it.get_l_child();
            auto r = it.get_r_child();
            if (Cmp_Fn()(x, **it)) {
                it = l;
            } else {
                ++ans;
                if (l != node_end()) ans += l.get_metadata();
                it = r;
            }
        }
        return ans;
    }

    void operator()(Node_Itr it, Node_CItr end_it) {
        auto l = it.get_l_child();
        auto r = it.get_r_child();
        int left = 0, right = 0;
        if (l != end_it) left = l.get_metadata();
        if (r != end_it) right = r.get_metadata();
        const_cast<int&>(it.get_metadata()) = left+right+1;
    }

    virtual Node_CItr node_begin() const = 0;
    virtual Node_CItr node_end() const = 0;
};

typedef tree<ii, null_type, less<ii>, rb_tree_tag, my_node_update> ordered_set;

const int MAXN = 1e6 + 5;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int n; scanf("%d", &n);
    vector<int> a(n);
    fto(i, 0, n-1) scanf("%d", &a[i]);

    vector<int> fl(n), fr(n);
    map<int, int> cnt[2];
    fto(i, 0, n-1) fl[i] = ++cnt[0][a[i]];
    fdto(i, n-1, 0) fr[i] = ++cnt[1][a[i]];

//    fto(i, 0, n-1) printf("%d %d\n", fl[i], fr[i]);

    ordered_set s;
    ll ans = 0;
    fto(i, 0, n-1) {
        ans += i - s.order_of_key({fr[i], i});
        s.insert({fl[i], i});
    }

    printf("%lld", ans);

    return 0;
}