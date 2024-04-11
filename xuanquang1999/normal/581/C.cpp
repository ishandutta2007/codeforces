#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 100005
#define oo 1000000007

int n, k, ans, a[maxN];

bool cmp(int a, int b) {
    return (10-a%10 < 10-b%10);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 0, n-1) scanf("%d", &a[i]);

    sort(a, a+n, cmp);

    fto(i, 0, n-1) {
        int x = min((10-a[i]%10)%10, k);
        a[i] += x; k-=x;
    }
    fto(i, 0, n-1) {
        int x = min(100-a[i], k);
        a[i] += x; k-=x;
    }

    fto(i, 0, n-1) ans+=a[i]/10;

    printf("%d", ans);

    return 0;
}