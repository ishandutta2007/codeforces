#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>

#define MOD 1000000007
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair
typedef int ll;
using namespace std;
ll n, m, k, x, y, z;
ll a[3005];



int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= 30000 ;i++) {
        if (!a[i]) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}