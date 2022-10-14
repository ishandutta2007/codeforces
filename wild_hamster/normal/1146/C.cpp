#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 1000000007
#define mp make_pair
#define X first
#define Y second
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r;
vector<ll> f, g;
ll a[100500], b[100500];
int main() {
    //freopen("input.txt", "r", stdin);
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> n;
        ll ans = 0;
        for (int j = 1; j <= 9; j++) {
            ll y;
            f.clear();
            g.clear();
            for (int k = 1; k <= n; k++) {
                if ((k % (1<<j)) < (1<<(j-1))) {
                    f.push_back(k);
                } else {
                    g.push_back(k);
                }
            }
            if (f.size() == 0 || g.size() == 0)
                continue;
            cout << f.size() << " " << g.size();
            for (int k = 0; k < f.size(); k++)
                cout << " " << f[k];
            for (auto x : g)
                cout << " " << x;
            cout << endl;
            fflush(stdout);
            cin >> y;
            ans = max(ans, y);
        }
        cout << "-1 " << ans << endl;
        fflush(stdout);
    }
    return 0;
}