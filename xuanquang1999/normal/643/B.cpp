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
#define maxN 5005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, k, a, b, c, d, ans[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    scanf("%d%d%d%d", &a, &b, &c, &d);

    if (n == 4 || k < n+1) puts("-1");
    else {
        ans[1] = a;
        ans[2] = c;
        int i = 3;
        fto(u, 1, n) {
            if (u != a && u != b && u != c && u != d) {
                ans[i++] = u;
            }
        }
        ans[n-1] = d;
        ans[n] = b;

        fto(i, 1, n) printf("%d ", ans[i]);
        puts("");
        swap(ans[1], ans[2]);
        swap(ans[n-1], ans[n]);
        fto(i, 1, n) printf("%d ", ans[i]);
        puts("");
    }


    return 0;
}