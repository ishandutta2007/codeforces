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
#define maxN 100005
#define maxK 15

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, k, a[maxN];
ll f[maxK][maxN], t[maxN];

void init() {
    memset(t, 0, sizeof t);
}

void update(int b, ll x) {
    for(int i = b; i <= n; i += i & (-i)) {
        t[i] += x;
    }
}

ll query(int x) {
    ll res = 0;
    for(int i = x; i >= 1; i -= i & (-i)) {
        res += t[i];
    }
    return res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(j, 1, n) f[1][j] = 1;
    fto(i, 2, k+1) {
        init();
        fto(j, 1, n) {
            f[i][j] = query(a[j]-1);
            update(a[j], f[i-1][j]);
//            debuga1(t, 1, n);
        }
    }
//    fto(i, 1, k+1) {
//        fto(j, 1, n) printf("%d ", f[i][j]);
//        printf("\n");
//    }

    ll ans = 0;
    fto(j, 1, n) ans += f[k+1][j];
    cout << ans;

    return 0;
}