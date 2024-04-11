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
#define maxN 200005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, a[maxN], b[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &a[i]);
    fto(i, 0, n-1) {
        if (a[i] == 0) {
            fto(j, i, n-2) a[j] = a[j+1];
        }
    }
    fto(i, 0, n-1) scanf("%d", &b[i]);
    fto(i, 0, n-1) {
        if (b[i] == 0) {
            fto(j, i, n-2) b[j] = b[j+1];
        }
    }

    int d =0;
    fto(i, 0, n-2) {
        if (a[0] == b[i]) {
            d = i;
            break;
        }
    }
    fto(i, 0, n-2) {
        if (a[i] != b[(i+d)%(n-1)]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");

    return 0;
}