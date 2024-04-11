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
#define maxN (1<<20)
#define MOD 1000000007

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

int n, a[maxN], cnt[maxN], f[maxN], e2[maxN];

void add(int &a, int b) {
    a += b;
    while (a >= MOD) a -= MOD;
    while (a < 0) a += MOD;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d", &a[i]);
        ++cnt[a[i]];
    }

    e2[0] = 1;
    fto(i, 1, maxN-1) e2[i] = (e2[i-1]*2)%MOD;

    fto(mask, 0, maxN-1) f[mask] = cnt[mask];
    fto(i, 0, 19) {
        fdto(mask, maxN-1, 0) {
            if (!(mask&(1<<i))) f[mask] += f[mask^(1<<i)];
        }
    }

//    fto(mask, 0, 3) printf("%d ", f[mask]);
//    puts("");

    int ans = 0;
    fto(mask, 0, maxN-1) {
        int s = (__builtin_popcount(mask) & 1) ? -1 : 1;
        add(ans, s*e2[f[mask]]);
    }

    printf("%d", ans);

    return 0;
}