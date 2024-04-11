#include <time.h>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <stdint.h>
#include <assert.h>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 1000000000
#define OFF 2001
#define N 100000000
#define PI 3.14159265358979323846
ll n, x, k, z, m, pos, q, ans_v, y, mx;
ll x1, p1, x2;
ll a[200505], b[200505];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        string s;
        cin >> s;
        for (int i = 0; i <= n; i++) {
            a[i] = 0;
        }
        a[n-1]++;
        for (int i = 0; i < m; i++) {
            cin >> x;
            a[x-1]++;
        }
        for (int i = 0; i < 26; i++) {
            b[i] = 0;
        }
        ll sum = 0;
        for (int i = n-1; i >= 0; i--) {
            sum += a[i];
            b[s[i] - 'a'] += sum;
        }
        for (int i = 0; i < 26; i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}