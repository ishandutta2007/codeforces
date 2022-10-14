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
#include <stdint.h>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
ll a[MAXN], b[MAXN];
vector<ll> f;
vector<ll> g[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        for (int i = 0;i < 10; i++) {
            a[i] = 0;
        }
        ll sum = 0;
        for (int i = 0; i < s.size(); i++) {
            a[s[i]-'0']++;
            sum += s[i] - '0';
        }
        ll evens = a[0] + a[2] + a[4] + a[6] + a[8];
        if (sum % 3 != 0 || evens < 2 || a[0] == 0) {
            cout << "cyan\n";
        } else {
            cout << "red\n";
        }
    }


    return 0;
}