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
#define N 1000000
#define OFF 200001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
vector<pii> g[200500];
pii a[200500], b[200500];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i <n; i++) {
        cin >> a[i].X >> a[i].Y;
    }
    if (n % 2) {
        cout << "NO" << "\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        b[i] = {a[i].X - a[(i+1)%n].X, a[i].Y - a[(i+1)%n].Y};
    }
    for (int i = 0; i < n/2; i++) {
        if (b[i].X != -b[i+n/2].X || b[i].Y != -b[i+n/2].Y) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;

}