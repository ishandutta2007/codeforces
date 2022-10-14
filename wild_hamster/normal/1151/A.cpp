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
string pat = "ACTG";
ll get(string s) {
    ll ans = 0;
    for (int i = 0; i < 4; i++)
        ans += min((s[i] - pat[i] + 26) % 26, 26 - (s[i] - pat[i] + 26) % 26);
    return ans;
}
int main() {
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    cin >> n;
    string s;
    cin >> s;
    l = 3902582;
    for (int i = 0; i + 4 <= n; i++) {
        l = min(l, get(s.substr(i, 4)));
    }
    cout << l << endl;
    return 0;
}