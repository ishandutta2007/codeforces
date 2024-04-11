#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 30000
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q;


ll b[200500];
vector<ll> g, f, ans, removed_odds, cur_odds;
ll a[1005];
ll asz;

ll gcd(ll a, ll b) {
    return b == 0? a : gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        f.push_back(b[i]);
    }
    asz = n;
    ll p = 1;

    while (!f.empty()) {
        g.clear();
        ll odds = 0, evens = 0;
        ll resz = removed_odds.size();
        for (auto x : f) {
            if (x % 2) {
                odds++;
                cur_odds.push_back(x);
            } else {
                evens++;
                g.push_back(x/2);
            }
        }
        if (evens + resz < asz) {
            asz = evens + resz;
            ans.clear();
            for (auto x : removed_odds) {
                ans.push_back(x);
            }
            for (auto x : g) {
                ans.push_back(x * 2 * p);
            }
        }
        for (auto x : cur_odds) {
            removed_odds.push_back(x * p);
        }
        p *= 2;
        f.clear();
        for (auto x : g) {
            f.push_back(x);
        }

    }
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << " ";
    }
    return 0;
}