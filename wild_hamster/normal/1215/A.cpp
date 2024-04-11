#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 30000
#define MOD 1000000007
#define LOG 18
ll n, x, k, z, m, pos, q;


ll used[100500], a[200500], b[200500];
vector<ll> g, f;
int main() {
    ll a1,a2,k1,k2,n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    ll min_ans = 0, max_ans = 0;
    if (n >= a1 * k1 + a2 * k2 - a1 - a2) {
        min_ans = n - (a1 * k1 + a2 * k2 - a1 - a2);
    }
    if (k1 > k2) {
        swap(k1, k2);
        swap(a1, a2);
    }
    if (n <= k1 * a1) {
        max_ans =  n/k1;
    } else {
        max_ans = a1 + (n - k1 * a1) / k2;
    }
    cout << min_ans << " "  << max_ans << endl;
    return 0;
}