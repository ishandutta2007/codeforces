
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
#include <fstream>

#define pii pair<ll,ll>
#define mp make_pair
#define X first
#define Y second

typedef int ll;
using namespace std;
#define N 10000000
#define OFF 400001
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll ii;
ll a[200500], b[200500], c[200500], dp[2005000];
vector<ll> f;

void apply(string& hyu, ll n) {
    for (int i = 0; i < n; i++) {
        hyu[i] = (hyu[i] == '1' ? '0' : '1');
    }
    reverse(hyu.begin(), hyu.begin()+n);
}
void solve() {
    f.clear();
    string s, t;
    cin >> n;
    cin >> s;
    cin >> t;
    ll i = 0;
    ll p = s[i];
    while (i < n) {
        if (s[i] != p) {
            f.push_back(i);
            p = s[i];
        }
        i++;
    }
    i = n-1;
    while (i >= 0) {
        if (t[i] != p) {
            f.push_back(i+1);
            p = t[i];
        }
        i--;
    }
    cout << f.size();
    for (auto x : f) {
        cout << " " << x;
    }
    cout << "\n";
    /*cout << s << " " << t << " " ;
    for (auto x : f) {
        apply(s, x);
    }
    cout << s << "\n";
    if (s != t) {
        cout << "ZALUPA";
    }*/
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}