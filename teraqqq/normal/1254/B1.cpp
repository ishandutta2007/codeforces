#include <bits/stdc++.h>

#define F first
#define S second
#define rsz resize
#define pb push_back

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vl = vector<ll>;

const int INF = 1e9;
const ll LINF = 1e18;
const ld PI = 4*atan((ld)1);

mt19937 rng;

void solve() {
    int n; cin >> n;
    vl a(n); ll sum = 0;
    for(ll& x : a) cin >> x, sum += x;

    vl dv; ll res = LINF;
    for(ll i = 2; i*i <= sum; ++i) {
        if(sum%i == 0) {
            dv.pb(i);
            while(sum%i == 0) sum /= i;
        }
    }
    if(sum > 1) dv.pb(sum);

    for(ll d : dv) {
        //cout << "!" << d << endl;
        vl b(n); ll t = 0, k = 0;
        for(int i = 0, l = 0; i < n; ++i) {
            t += b[i] = a[i] % d; t %= d;
            if(t == 0 && l < i) {
                //cout << ". " << l << ' ' << i << endl;
                ll sum_l = 0, sum_r = 0; ll add = LINF;
                vl p_l(i-l+1), p_r(i-l+1); p_l[0] = b[l]; p_r[i-l] = b[i];
                for(int j = l+1; j <= i; ++j) p_l[j-l] = p_l[j-l-1] + b[j];
                for(int j = i-1; j >= l; --j) p_r[j-l] = p_r[j-l+1] + b[j];
                for(int j = l; j <= i; ++j) sum_r += p_r[j-l];
                for(int j = l; j <= i; ++j) {
                    if(j > l) sum_l += p_l[j-l-1]; sum_r -= p_r[j-l];
                    //cout << sum_l << ' ' << sum_r << endl;
                    add = min(add, sum_l + sum_r);
                }
                l = i+1; k += add;
            }
        }
        //cout << d << ": " << k << endl;

        res = min(res, k);
    }

    if(res == LINF) cout << -1 << endl;
    else cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());
    solve();
}