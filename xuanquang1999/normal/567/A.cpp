using namespace std;
#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005
#define oo 2000000007

int n, a[maxN], minD, maxD;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &a[i]);

    fto(i, 0, n-1) {
        minD = oo;
        if (i > 0) minD = min(minD, a[i]-a[i-1]);
        if (i < n-1) minD = min(minD, a[i+1]-a[i]);
        maxD = max(a[i]-a[0], a[n-1]-a[i]);
        printf("%d %d\n", minD, maxD);
    }

    return 0;
}