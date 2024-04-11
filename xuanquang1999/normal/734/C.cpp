//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
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
#define ll long long
#define maxN 200005
#define oo 5000000000000000000LL

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
void read(vector<T> &v) {
    T x;
    cin >> x;
    v.pb(x);
}

int n, m, k, x, s, a[maxN], b[maxN], c[maxN], d[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    scanf("%d%d", &x, &s);
    a[0] = x;
    fto(i, 1, m) scanf("%d", &a[i]);
    fto(i, 1, m) scanf("%d", &b[i]);
    fto(i, 1, k) scanf("%d", &c[i]);
    fto(i, 1, k) scanf("%d", &d[i]);

    ll ans = oo;
    fto(i, 0, m) {
        if (b[i] > s) continue;
        int j = upper_bound(d, d+k+1, s-b[i])-d-1;
//        printf("%d %d\n", i, j);
        ans = min(ans, (ll)(n-c[j])*a[i]);
    }

    cout << ans;

    return 0;
}