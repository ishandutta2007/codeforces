//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ftos(i, l, r, a) for(int i = (l); i <= (r); i += a)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 105

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, r, c, a[maxN][maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &r, &c);
    if (n > r*c) puts("-1");
    else {
        int cnt = 0;
        fto(i, 1, r) {
            if (i%2 == 1) {
                fto(j, 1, c) {
                    if (cnt < n) a[i][j] = ++cnt;
                }
            } else {
                fdto(j, c, 1) {
                    if (cnt < n) a[i][j] = ++cnt;
                }
            }
        }
        fto(i, 1, r) {
            fto(j, 1, c) {
                printf("%d ", a[i][j]);
            }
            puts("");
        }
    }

    return 0;
}