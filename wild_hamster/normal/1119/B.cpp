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
ll n,m,k, y, z, l, i, j, x;
map<ll, ll> f;
ll a[500500], b[500500], c[500500];
ll used[500500];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = n; j >= 0; j--) {
        for (int i = 0; i < j; i++)
            b[i] = a[i];
        sort(b, b+j);
        x = 0;
        for (int i = j-1; i >= 0; i -= 2) {
            x += b[i];
        }
        if (x <= m) {
            cout << j << endl;
            return 0;
        }
    }
    return 0;
}