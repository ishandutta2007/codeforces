//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ftoa(i, l, r, a) for(int i = (l); i <= (r); i += a)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 1000005
#define maxK 20
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

int f[maxN][maxK], lp[maxN];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(i, 2, maxN-1) {
        if (lp[i] == 0) {
            ftoa(j, i, maxN-1, i) {
                if (!lp[j]) lp[j] = i;
            }
        }
    }

//    fto(i, 0, 100) printf("%d %d\n", i, lp[i]);

    fto(j, 0, maxK-1) f[0][j] = (j == 0) ? 1 : 2;
    fto(i, 1, maxN-1) {
        f[i][0] = f[i-1][0];
        fto(j, 1, maxK-1) f[i][j] = (f[i][j-1]+f[i-1][j])%MOD;
    }

//    fto(i, 0, 10) {
//        fto(j, 0, 10) printf("%d ", f[i][j]);
//        puts("");
//    }

    int q;
    scanf("%d", &q);
    fto(i, 1, q) {
        int r, n;
        scanf("%d%d", &r, &n);

        int ans = 1;
        while (lp[n]) {
            int x = lp[n], cnt = 0;
            while (lp[n] == x) ++cnt, n /= x;
            ans = ((ll)ans*f[r][cnt])%MOD;
        }
        printf("%d\n", ans);
    }

    return 0;
}