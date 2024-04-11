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
#define N 1000000
#define OFF 400001
#define MOD 998244353
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
vector<ll> g[200500];
string s, t;
ll a[5], b[5];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll n = s.size();
        for (int i = 0; i < 2; i++) {
            a[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            a[s[i] - '0']++;
        }
        ll ans = n;
        for (int i = 0; i < 2; i++) {
            b[i] = 0;
        }
        for (int i = 0; i <= n; i++) {
            ans = min(ans, i - b[0] + (n - i) - (a[1] - b[1]));
            ans = min(ans, i - b[1] + (n - i) - (a[0] - b[0]));
            if (i == n) {
                break;
            }
            b[s[i]-'0']++;
        }
        cout << ans << "\n";
    }
    return 0;
}