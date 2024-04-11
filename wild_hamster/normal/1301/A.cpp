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
ll a[100500];
vector<ll> f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        ll n = s1.size();
        ll hyu = 1;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s3[i] && s2[i] != s3[i]) {
                hyu = 0;
            }
        }
        cout << (hyu ? "YES":"NO") << "\n";
    }

    return 0;
}