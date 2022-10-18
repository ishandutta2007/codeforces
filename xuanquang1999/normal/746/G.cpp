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
#define maxK 20
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

int n, k, t, a[maxN], cur[maxN];
vector<ii> ans;
vector<int> lev[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &t, &k);
    fto(i, 1, t) scanf("%d", &a[i]);

    lev[0].pb(1);
    int cnt = 1;
    fto(i, 1, t) {
        fto(j, 1, a[i]) lev[i].pb(++cnt);
    }

    k -= a[t];
    fto(i, 1, t-1) {
        cur[i] = max(0, a[i]-a[i+1]);
        k -= cur[i];
    }
    if (k < 0) {
        puts("-1");
        return 0;
    }

    fto(i, 1, t-1) {
        while (k > 0 && cur[i] < a[i]-1) {
            ++cur[i]; --k;
        }
    }
    if (k > 0) {
        puts("-1");
        return 0;
    }

    forit(it, lev[1]) ans.pb(mp(lev[0][0], *it));
    fto(i, 1, t-1) {
        fto(j, 0, a[i]-cur[i]-1) ans.pb(mp(lev[i][j], lev[i+1][j]));
        fto(j, a[i]-cur[i], a[i+1]-1) ans.pb(mp(lev[i][0], lev[i+1][j]));
    }

    printf("%d\n", n);
    forit(it, ans) printf("%d %d\n", it->ff, it->ss);

    return 0;
}