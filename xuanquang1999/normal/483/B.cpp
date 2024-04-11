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

ll cnt1, cnt2, x, y;

bool Check(ll n) {
    ll b = (x/__gcd(x, y))*y;
    int k1 = n/y - n/b, k2 = n/x - n/b;
    return (max((ll)0, cnt1-k1)+max((ll)0, cnt2-k2) <= n-(n/y+n/x-n/b));
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> cnt1 >> cnt2 >> x >> y;

    ll l = 1, r = 2000000007, res = r+1;
    while (l <= r) {
        //cout << l << " " << r << endl;
        ll mid = (l+r)/2;
        if (Check(mid)) {
            if (mid < res) res = mid;
            r = mid-1;
        }
        else l = mid+1;
    }

    cout << res;

    return 0;
}