//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 2005
#define oo 1000000000000000007LL

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

ll n, ans;
pair<ll, ll> p1, p2, p[maxN];
bool avail[maxN];

ll sqr(ll x) {
    return x*x;
}

ll dist (pair<ll, ll> p1, pair<ll, ll> p2) {
    return (sqr(p1.ff-p2.ff) + sqr(p1.ss-p2.ss));
}
bool cmp1 (pair<ll, ll> a, pair<ll, ll> b) {
    return (dist(a, p1) < dist(b, p1));
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> p1.ff >> p1.ss >> p2.ff >> p2.ss;
    fto(i, 1, n) cin >> p[i].ff >> p[i].ss;
    p[0] = p1;
    sort(p+1, p+n+1, cmp1);

    ans = oo;
    fto(i, 0, n) {
        ll maxD = 0;
        fto(j, i+1, n) maxD = max(maxD, dist(p[j], p2));
        ans = min(ans, maxD+dist(p[i], p1));
    }

    cout << ans;


    return 0;
}