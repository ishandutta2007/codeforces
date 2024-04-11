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
#define maxN 100005

int n, d;
vector<int> a;
ll ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &d);
    fto(i, 0, n-1) {
        int x;
        scanf("%d", &x);
        a.pb(x);
    }

    fto(i, 0, n-3) {
        int p = upper_bound(a.begin(), a.end(), a[i]+d)-a.begin();
        ll tmp = p-(i+1);
        ans+=(tmp*(tmp-1))/2;
    }

    cout << ans;

    return 0;
}