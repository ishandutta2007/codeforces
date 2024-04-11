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
#define maxN 100005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int m, n, a[maxN], t[maxN], x[maxN], l[maxN], c[maxN];
ll cnt[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &m);
    fto(i, 1, m) {
//        debug(i);
        scanf("%d", &t[i]);
        if (t[i] == 1) {
            scanf("%d", &x[i]);
            cnt[i] = cnt[i-1]+1;
            if (cnt[i] <= 100000) a[cnt[i]] = x[i];
        }
        else {
            scanf("%d%d", &l[i], &c[i]);
            cnt[i] = cnt[i-1];
            fto(k, 1, c[i]) {
                if (cnt[i] >= 100000) break;
                fto(j, 1, l[i]) {
//                    debug(cnt[i]);
//                    debug(j);
                    if (cnt[i] < 100000) a[++cnt[i]] = a[j];
                    else break;
                }
            }
            cnt[i] = cnt[i-1]+(ll)l[i]*c[i];
        }
    }
//    fto(i, 1, m) printf("%d ", cnt[i]);
//    puts("");
//    fto(i, 1, cnt[m]) printf("%d ", a[i]);
//    puts("");

    scanf("%d", &n);
    fto(i, 1, n) {
        ll e = 0;
        cin >> e;
        int p = lower_bound(cnt+1, cnt+m+1, e)-cnt;
//        debug(p);
        if (t[p] == 1) printf("%d ", x[p]);
        else printf("%d ", a[(e-cnt[p-1]-1)%l[p]+1]);
    }

    return 0;
}