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
#define maxQ 200005
#define oo 1000000007

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

int n, Q, l[maxN], r[maxN], cnt[maxN], a[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &Q);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 1, Q) scanf("%d%d", &l[i], &r[i]);

    sort(l+1, l+Q+1);
    sort(r+1, r+Q+1);

    int i = 1, j = 1;
    fto(x, 1, n) {
        while (i <= Q && l[i] <= x) ++i;
        while (j <= Q && r[j] < x) ++j;
        cnt[x] = i-j;
    }

    sort(cnt+1, cnt+n+1);
    sort(a+1, a+n+1);

    ll ans = 0;
    fdto(i, n, 1) ans += (ll)cnt[i]*a[i];

    cout << ans;


    return 0;
}