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

int n, k, a[maxN], cntUnd;
ll h[maxN];
char s[maxN][10];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 0, n) {
        scanf("%s", s[i]);
        if (strcmp(s[i], "?") == 0) ++cntUnd;
        else sscanf(s[i], "%d", &a[i]);
    }
    if (k == 0) {
        if (strcmp(s[0], "?") == 0) {
            if ((n-cntUnd+2)%2 == 1) puts("No");
            else puts("Yes");
        }
        else puts((a[0] == 0) ? "Yes" : "No");
    }
    else if (cntUnd == 0) {
//        fto(i, 0, n) printf("%d ", a[i]);
        fdto(i, n, 0) {
            h[i] = h[i+1]*k+a[i];
            if (abs(h[i]) > 1000000007) {
                puts("No");
                return 0;
            }
        }
        puts((h[0] == 0) ? "Yes" : "No");
    }
    else if (n%2 == 0) puts("No");
    else puts("Yes");


    return 0;
}