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
    ll k = 0;
    string t, x;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'a') {
            k++;
            t.push_back(s[i]);
        }
        x.push_back(s[i]);
        if (k + i + 1 == n) {
            string ans = x;
            x.append(t);
            if (x == s) {
                cout << ans << endl;
                return 0;
            }


        }
    }
    cout << ":(" << endl;
    return 0;
}