#include <string>
#include <time.h>
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

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 228228
#define MOD 1000000007
ll x, y, n, m, k, R, C, q;
deque<ll> a;
vector<pii> ans;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    ll l = 1, r = n;
    while (l < r) {
        for (int i = 1; i <= m; i++) {
            cout << l << " " << i << "\n" << r << " " << m-i+1 << "\n";
        }
        l++;
        r--;
    }
    if (l == r) {
        ll L = 1, R = m;
        while (L < R) {
           cout << l << " " << L << "\n" << l << " " << R << "\n";
           L++;
           R--;
        }
        if (L == R) {
            cout << l << " " << L << endl;
        }
    }

    return 0;
}