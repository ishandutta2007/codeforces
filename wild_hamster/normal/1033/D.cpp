#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define MAXN 1000005
typedef long long ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2;
ll a[100500], b[100500], ans[100500];
map<ll, ll> f, two;
vector<ll> twos;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}
ll pw(ll x, ll y) {
    ll ans = 1;
    for (int i = 0; i < y; i++)
        ans *= x;
    return ans;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        ll x = a[i], flag = 0;
        for (int j = 4; j >= 2; j--) {
            ll p = exp(1./j*log(x));
            p -= 2;
            if (p < 0)
                p = 0;
            while (pw(p+1, j) <= x)
                p++;
            if (pw(p, j) == x) {
                flag = 1;
                f[p] += j;
                break;
            }
        }
        if (!flag) {
            twos.push_back(a[i]);
        }
    }
    for (int i = 0; i < twos.size(); i++) {
        int flag = 0;
        for (int j = 0; j < n; j++) {
            ll g = gcd(a[j], twos[i]);
            if (g != 1 && g != twos[i]) {
                f[g]++;
                f[twos[i]/g]++;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            two[twos[i]]++;
        }

    }
    ll ans = 1;
    for (auto itr = two.begin(); itr != two.end(); itr++) {
        ans *= (*itr).Y + 1;
        ans *= (*itr).Y + 1;
        //cout << (*itr).Y + 1 << endl;
        ans %= MOD;
    }

    for (auto itr = f.begin(); itr != f.end(); itr++) {
        ans *= (*itr).Y + 1;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}