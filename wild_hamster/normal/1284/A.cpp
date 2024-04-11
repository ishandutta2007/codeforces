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
#define OFF 200001
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
string a[300500], b[300500];
vector<ll> f, g[200500];



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    cin >> q;
    while (q--) {
        cin >> x;

        y = (x - 1) % m;
        x = (x - 1) % n;
        cout << a[x] << b[y] << "\n";
    }
    return 0;

}