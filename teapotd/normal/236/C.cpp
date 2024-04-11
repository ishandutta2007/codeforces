#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for (int i = (b); i < (e); i++)
#define each(a,x) for (auto& a : (x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

ll gcd(ll a, ll b) {
    while (b) {
        ll c = a%b;
        a = b;
        b = c;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a*b / gcd(a, b);
}

ll lcm(ll a, ll b, ll c) {
    ll l = lcm(a, b);
    return l*c / gcd(l, c);
}

int main() {
    cin.sync_with_stdio(0);
    cout << fixed << setprecision(15);

    ll n; cin >> n;
    ll lower = max(1LL, n-50);
    ll best = 0;

    for (ll a = lower; a <= n; a++) {
        for (ll b = lower; b <= n; b++) {
            for (ll c = lower; c <= n; c++) {
                best = max(best, lcm(a, b, c));
            }
        }
    }

    cout << best << '\n';
    return 0;
}