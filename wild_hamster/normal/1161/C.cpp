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
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[100500], b[100500];
ll dp[505][505];
pii se[200500], de[200500];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    for (int i = 0; i < n/2; i++) {
        if (a[i] != a[i+1]) {
            cout << "Alice" << endl;
            return 0;
        }
    }
    cout << "Bob" << endl;
    return 0;
}