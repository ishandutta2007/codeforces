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
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    for (int i = 0; i < n-1; i++)
        b[i+1] = a[i+1] - a[i];
    sort(b, b+n);
    c[0] = 0;
    for (int i = 1; i < n; i++) {
        //cout << "b= " << b[i] << endl;
        c[i] = c[i-1] + (b[i] - b[i-1]) * (n - i + 1);
        //cout << "c= " << c[i] << endl;
    }
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll x,y;
        cin >> x >> y;
        k = y-x+1;
        ll pos = upper_bound(b, b + n, k-1) - b - 1;
        cout << c[pos] + (n-pos) * (k - b[pos]) << " ";
    }
    return 0;
}