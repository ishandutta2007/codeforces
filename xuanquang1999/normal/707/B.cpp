//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
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
#define maxN 200005
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, k;
bool sto[maxN];
pair<int, ii> e[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    fto(i, 1, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        e[i] = mp(c, mp(u, v));
    }
    fto(i, 1, k) {
        int x;
        scanf("%d", &x);
        sto[x] = true;
    }

    int ans = oo;
    fto(i, 1, m) {
        int c = e[i].ff, u = e[i].ss.ff, v = e[i].ss.ss;
        if (sto[u]^sto[v]) ans = min(ans, c);
    }
    if (ans == oo) puts("-1");
    else cout << ans;

    return 0;
}