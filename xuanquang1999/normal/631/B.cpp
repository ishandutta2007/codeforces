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
#define maxN 5005
#define maxK 100005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int m, n, k, t[maxK], p[maxK], a[maxK], ans[maxN][maxN];
bool r[maxN], c[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &m, &n, &k);
    fto(i, 1, k) scanf("%d%d%d", &t[i], &p[i], &a[i]);

    fdto(i, k, 1) {
        if (t[i] == 1) {
            if (!r[p[i]]) {
                r[p[i]] = true;
                fto(j, 1, n) {
                    if (ans[p[i]][j] == 0) ans[p[i]][j] = a[i];
                }
            }
        }
        else {
            if (!c[p[i]]) {
                c[p[i]] = true;
                fto(j, 1, m) {
                    if (ans[j][p[i]] == 0) ans[j][p[i]] = a[i];
                }
            }
        }
    }

    fto(i, 1, m) {
        fto(j, 1, n) printf("%d ", ans[i][j]);
        puts("");
    }

    return 0;
}