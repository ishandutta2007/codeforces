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

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll n, x, k, z, m, pos, q, ans_v, y, mx;
ll x1, p1, x2;
set<ll> f;
ll a[400500];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 0;i < x; i++) {
        f.insert(i);
        a[i] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> y;
        y %= x;
        f.erase(a[y]);
        a[y] += x;
        f.insert(a[y]);
        cout << *(f.begin())  << "\n";
    }


    return 0;
}