#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define forrit(rit, type, var) for(type::reverse_iterator rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define ull unsigned long long
#define maxN 200005
#define oo 1000000007

int n, a[maxN], ans;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    ans = oo;
    fto(l, 1, n/2) {
        int r = l+n/2;
        ans = min(ans, a[r]-a[l]);
    }
    cout << ans;

    return 0;
}