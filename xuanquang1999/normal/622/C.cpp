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
#define maxX 1000005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, q, a[maxN];
vector<int> v[maxX];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    fto(i, 1, n) {
        scanf("%d", &a[i]);
        v[a[i]].pb(i);
    }
    fto(i, 1, q) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        if (a[l] != x) printf("%d\n", l);
        else if (a[r] != x) printf("%d\n", r);
        else {
            int pl = lower_bound(v[x].begin(), v[x].end(), l)-v[x].begin();
//            printf("%d %d %d %d\n", l, r, x, v[x].size());
            if (pl == v[x].size()) printf("%d\n", pl);
            else {
                int pr = (--upper_bound(v[x].begin(), v[x].end(), r))-v[x].begin();
                int tmp_pl = pl;
//                printf("%d %d\n", pl, pr);
                int res = maxN+1;
                while (pl <= pr) {
//                    debug(pl);
//                    debug(pr);
                    int mid = (pl+pr)/2;
                    if (v[x][mid]-l > mid-tmp_pl) {
                        res = min(res, mid);
                        pr = mid-1;
                    }
                    else pl = mid+1;
                }
                if (res == maxN+1) puts("-1");
                else printf("%d\n", v[x][res]-1);
            }
        }
    }
}