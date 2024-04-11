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
#define maxN 500005
#define oo 1000000007

int n, r, ans;
ii a[maxN];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("vongtron.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d%d", &a[i].ss, &a[i].ff);
    sort(a, a+n);

    fto(i, 0, n-1) {
        if (a[i].ss > r) {
            r = a[i].ff;
            ++ans;
        }
    }

    cout << ans;

    return 0;
}