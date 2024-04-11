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
set<ll> f;
ll a[100500], b[100500];
int main() {
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    ll n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a')
            k++;
    }
    if (k * 2 > n) {
        cout << n << endl;
    } else {
        cout << k * 2 - 1 << endl;
    }
    return 0;
}