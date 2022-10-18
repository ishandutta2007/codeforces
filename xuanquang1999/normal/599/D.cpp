//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(ll i = (r); i >= (l); --i)
#define fto(i, l, r) for(ll i = (l); i <= (r); ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define fordit(rit, type, var) for(type::reverse_iterator rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005
#define tmp_type vector<pair<ll, ll> >
ll x;
tmp_type ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> x;
    fto(k, 0, 10000000)
        if ((x*6)%(k+1) == 0) {
//            debug(k);
            ll y = (x*6)/(k+1) - 2*k*k - k;
            if (y < 0) break;
            if (y % 3 != 0) continue;
//            debug(y);
            y/=3;
            ll a = k+1;
//            debug(a);
            if ((y + k*a) % (2*a-k) != 0) continue;
            ll b = (y + k*a) / (2*a-k);
            if (b < a) continue;
//            debug(b);
            ans.pb(mp(a, b));
            if (a != b) ans.pb(mp(b, a));
        }

    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    forit(it, tmp_type, ans) printf("%I64d %I64d\n", it->ff, it->ss);

    return 0;
}