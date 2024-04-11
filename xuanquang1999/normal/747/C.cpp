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

int n, q, t[maxN], k[maxN], d[maxN], last[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    fto(i, 1, q) scanf("%d%d%d", &t[i], &k[i], &d[i]);

    fto(i, 1, q) {
        int sum = 0;
        vector<int> v;
        fto(j, 1, n) {
            if (k[i] > 0 && last[j] <= t[i]) {
                --k[i]; v.pb(j);
            }
        }
//        forit(it, v) printf("%d ", *it);
//        puts("");
//        debug(k[i]);
        if (k[i] == 0) {
            int ans = 0;
            forit(it, v) {
                last[*it] = t[i]+d[i];
                ans += *it;
            }
            printf("%d\n", ans);
        }
        else puts("-1");
    }

    return 0;
}