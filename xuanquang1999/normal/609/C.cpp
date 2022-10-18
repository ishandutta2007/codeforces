//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
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

int n, sum, n1, b1, a[maxN], b[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d", &a[i]);
        sum+=a[i];
    }
    sort(a+1, a+n+1);
    n1 = n-sum%n;
    b1 = sum/n;
    fto(i, 1, n1) b[i] = b1;
    fto(i, n1+1, n) b[i] = b1+1;
//    fto(i, 1, n) printf("%d %d\n", a[i], b[i]);

    sum = 0;
    fdto(i, n, 1) {
//        printf("%d %d\n", a[i], b[i]);
        if (a[i] <= b[i]) break;
        sum = sum+(a[i]-b[i]);
    }

    cout << sum;

    return 0;
}