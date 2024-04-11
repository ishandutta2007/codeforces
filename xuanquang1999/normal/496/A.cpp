#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); ++it)
#define ll long long
#define ii pair<int, int>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define maxN 100005
#define oo 1000000007

int n, a[maxN], ans, cur;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 2, n) cur = max(cur, a[i]-a[i-1]);

    ans = oo;
    fto(i, 3, n) ans = min(ans, max(cur, a[i]-a[i-2]));
    cout << ans;

    return 0;
}