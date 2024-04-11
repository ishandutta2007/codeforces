using namespace std;
#include <bits/stdc++.h>
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
#define maxN 100005

int n, a[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    if (n%4 < 2) {
        fto(i, 1, n/2) {
            if (i%2 == 1) a[i] = i+1;
            else a[i] = n+2-i;
            a[n-i+1] = n+1-a[i];
        }
        if (n%4 == 1) a[n/2+1] = n/2+1;
        fto(i, 1, n) printf("%d ", a[i]);
    }
    else printf("-1");

    return 0;
}