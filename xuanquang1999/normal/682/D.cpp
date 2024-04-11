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
#define maxN 1005
#define maxK 15

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, k, z[maxN][maxN], f[maxN][maxN][maxK];
string s, t;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    cin >> s;
    cin >> t;
    fto(i, 1, n) {
        fto(j, 1, m) {
            if (s[i-1] == t[j-1]) z[i][j] = z[i-1][j-1]+1;
            else z[i][j] = 0;
        }
    }

    int ans = 0;
    fto(x, 1, k) {
//        debug(x);
        fto(i, 1, n) {
            fto(j, 1, m) {
                int l = z[i][j];
                f[i][j][x] = max(max(f[i-1][j][x], f[i][j-1][x]), f[i-l][j-l][x-1]+l);
                ans = max(ans, f[i][j][x]);
//                printf("%d ", f[i][j][x]);
            }
//            puts("");
        }

    }
    cout << ans;

    return 0;
}