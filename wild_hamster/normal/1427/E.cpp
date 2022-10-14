
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 35000000
#define OFF 400001
#define MOD 1000000007
#define NN 1000000
ll n, m, k, x, y, w, r;
ll c[1005000], b[1005000], dp[1005000], maxdp[1005000];
vector<pii> f;
vector<ll> query;
vector<vector<ll> > queries;
ll L, R;
ll Abs(ll x) {
    return x > 0 ? x : -x;
}
struct hyu {
    ll op1;
    string c;
    ll op2;
};
vector<hyu> ans;

bool pr(ll x) {
    if (x == 1) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll exgcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = exgcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
vector<ll> zal;
void make_shit(ll x, ll y) {
    ll xx = x;
    ll needed = x * y;
    zal.clear();
    zal.push_back(xx);
    while (xx * 2 <= needed) {
        ans.push_back({xx, " + ", xx});
        xx *= 2;
        zal.push_back(xx);
    }
    sort(zal.begin(), zal.end());
    reverse(zal.begin(), zal.end());
    ll cur = zal[0];
    for (int i = 1; i < zal.size(); i++) {
        if (cur + zal[i] <= needed) {
            ans.push_back({cur, " + ", zal[i]});
            cur += zal[i];
        }
    }
    if (cur != needed) {
        cout << "SOSI CHLEN KURWA" << cur << " " << needed << "\n";
    }

}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(228);
    cin >> n;
    //n = 524289;

    for (int i = n; i <= n; i += 2) {
        b[0] = i;
        for (int j = 1; j < 1000; j++) {
            ll mul = (32768LL * rand() + rand()) % 900000;
            b[j] = i ^ (mul * i);
            c[j] = mul;

        }
        bool good = false;
        for (int k = 0; k < 1000; k++) {
            for (int j = k + 1; j < 1000; j++) {
                if (b[k] != b[j] && gcd(b[k], b[j]) == 1 && b[k] % 2 && b[j] % 2) {
                    ll x , y;
                    ll p = exgcd(b[k], b[j], x, y);
                    ll t1 = Abs(x * b[k]);
                    ll t2 = Abs(y * b[j]);
                    if (t1 > t2) {
                        swap(t1, t2);
                    }
                    ll ad = 0;
                    if (t1 % 2) {
                        ad = 1;
                        t1 += b[k] * b[j];
                        t2 += b[k] * b[j];
                    }
                    if (max(t1, t2) < 5LL * (ll)1e+17) {
                        //cout << b[k] << " " << b[j] << "\n";
                        if (c[k] != 0) {
                            make_shit(i, c[k]);
                            ans.push_back({i, " ^ ", i * c[k]});
                        }
                        if (c[j] != 0) {
                            make_shit(i, c[j]);
                            ans.push_back({i, " ^ ", i * c[j]});
                        }
                        make_shit(b[k], Abs(x));
                        make_shit(b[j], Abs(y));
                        if (ad) {
                            make_shit(b[k], b[j]);
                            ans.push_back({t1 - b[k] * b[j], " + ", b[k] * b[j]});
                            ans.push_back({t2 - b[k] * b[j], " + ", b[k] * b[j]});
                        }
                        ans.push_back({t1, " ^ ", t2});
                        cout << ans.size() << "\n";
                        for (auto x : ans) {
                            cout << x.op1 << x.c << x.op2 << "\n";
                        }
                        good = true;
                        return 0;
                    }
                }
                if (good) {
                    break;
                }
            }
            if (good) {
                break;
            }
        }
        if (!good) {
            cout << i << "\n";
        }
    }


    return 0;
}