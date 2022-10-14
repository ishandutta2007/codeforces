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
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
using namespace std;
#define N 10000000
#define OFF 400001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll ii;
ll a[200500], b[200500], c[200500];
vector<pii> f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    cout << 3 * n + 4 << "\n";
    f.push_back(mp(1, 1));

    f.push_back(mp(1, 2));
    f.push_back(mp(2 + n, n + 1));

    f.push_back(mp(2 + n, n + 2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            f.push_back(mp(i+2, j + i + 1));
        }
    }
    for (auto x : f) {
        cout << x.X << " " << x.Y << "\n";
    }
    return 0;
}