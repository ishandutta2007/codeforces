//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
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
#define maxN 300005
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, q, t[maxN], x[maxN], max3, cnt[maxN], lp[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    max3 = -1;
    fto(i, 1, q) {
        scanf("%d%d", &t[i], &x[i]);
        if (t[i] == 3) max3 = max(max3, x[i]);
    }

    int cnt1 = 0, j = 0, ans = 0;
    fto(i, 1, q) {
        if (t[i] == 1) {
            ++cnt[x[i]];
            ++ans;
        }
        else if (t[i] == 2) {
            ans -= cnt[x[i]];
            cnt[x[i]] = 0;
            lp[x[i]] = i;
        }
        else if (t[i] == 3) {
            while (j < q && cnt1 < x[i]) {
                ++j;
                if (t[j] == 1) {
                    if (lp[x[j]] < j) {
                        --ans;
                        --cnt[x[j]];
                    }
                    ++cnt1;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}