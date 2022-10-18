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

int n, a[maxN], cnt;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &a[i]);

    cnt = (a[n-1] > a[0]);
    fto(i, 1, n-1) cnt+=(a[i-1] > a[i]);

    if (cnt > 1) {
        printf("-1");
        return 0;
    }

    fto(i, 1, n-1)
        if (a[i-1] > a[i]) {
            printf("%d", n-i);
            return 0;
        }

    printf("0");

    return 0;
}