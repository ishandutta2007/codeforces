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

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
ll a[300500];
vector<pii> f;
string s;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    ll cnt = 0;
    /*for (int i = 0; i < n; i++) {
        cin >> x;
        if (cnt == 0) {
            cnt = 1;
            z = x;
        } else if (z == x) {
            cnt++;
        } else {
            f.push_back(mp(z, cnt));
            cnt = 1;
            z = x;
        }
    }
    f.push_back(mp(z, cnt));
    for (auto x : f) {
        cout << x.X << " " << x.Y << "\n";
    }*/

    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i % 2) {
            sum1 += x / 2;
            sum2 += x - x/2;
        } else {
            sum1 += x - x/2;
            sum2 += x / 2;
        }
    }
    cout << min(sum1, sum2) << "\n";
    return 0;
}