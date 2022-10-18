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
#define EPS 1e-9

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

int n, k, ans, cnt[32], f[32];
ii a[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 1, n) {
        int x, cnt = 0;
        scanf("%d", &x);
        if (k > 1) {
            while (x%k == 0) {x /= k; ++cnt;}
        }
        a[i] = mp(x, cnt);
    }
    sort(a+1, a+n+1);

    fto(i, 1, n+1) {
        if ((i > 1 && a[i].ff != a[i-1].ff) || i == n+1) {
            f[0] = cnt[0];
            fto(b, 1, 31) {
                f[b] = max(cnt[b], f[b-1]);
                fto(k, 0, b-2) f[b] = max(f[b], f[k]+cnt[b]);
            }
            ans += *max_element(f, f+32);
            memset(cnt, 0, sizeof cnt);
        }
        if (i <= n) ++cnt[a[i].ss];
    }

    printf("%d", ans);

    return 0;
}