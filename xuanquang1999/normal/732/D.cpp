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
#define maxN 100005
#define oo 3000000000000000000LL

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, d[maxN], a[maxN], maxD[maxN];
vector<int> v[maxN];

bool Check(int t) {
    fto(x, 1, m) {
        vector<int>::iterator it = upper_bound(v[x].begin(), v[x].end(), t);
        if (it == v[x].begin()) return false;
        else maxD[x] = *(--it);
    }
    sort(maxD+1, maxD+m+1);
    int cur = 1;
//    debug(t);
//    fto(x, 1, m) printf("%d ", maxD[x]);
//    puts("");
    fto(x, 1, m) {
//        printf("%d %d\n", x, cur);
        if (maxD[x]-cur < a[x]) return false;
        cur += a[x]+1;
    }
    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        scanf("%d", &d[i]);
        if (d[i] > 0) v[d[i]].pb(i);
    }
    fto(i, 1, m) scanf("%d", &a[i]);

    fto(x, 1, m) sort(v[x].begin(), v[x].end());

    int l = 1, r = n, res = n+1;
    while (l <= r) {
        int mid = (l+r)/2;
        if (Check(mid)) {
            res = min(res, mid);
            r = mid-1;
        }
        else l = mid+1;
    }

    if (res == n+1) cout << -1;
    else cout << res;

    return 0;
}