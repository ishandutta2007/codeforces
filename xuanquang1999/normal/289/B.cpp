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
#define maxK 10005

int a[maxK], n, m, d;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &d);
    int k = m*n;
    fto(i, 0, k-1) scanf("%d", &a[i]);

    fto(i, 0, k-2)
        if (a[i]%d != a[i+1]%d) {
            printf("-1");
            return 0;
        }

    sort(a, a+k);

    int med;
    if (k%2 == 0) med = a[k/2-1];
    else med = a[k/2];

    int ans = 0;
    fto(i, 0, k-1) ans+=abs(a[i]-med)/d;

    printf("%d", ans);

    return 0;
}