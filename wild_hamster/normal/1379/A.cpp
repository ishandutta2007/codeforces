
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
ll n, x, k, z, m, pos, q, ans_v, y, root, xx;
ll ii;
ll a[100500];
string hyu = "abacaba";
bool can(string s, ll i) {
    ll n = s.size();
    for (int j = i; j < i+7; j++) {
        if (!(s[j] == hyu[j-i] || s[j] == '?')) {
            return false;
        }
    }
    for (int j = i; j < i+7; j++) {
        s[j] = hyu[j-i];
    }
    for (int j = 0; j < n; j++) {
        if (s[j] == '?') {
            s[j] = 'z';
        }
    }
    ll k = 0;
    for (int i = 0; i < n - 6; i++) {
        if (s.substr(i, 7) == "abacaba") {
            k++;
        }
    }
    if (k == 1) {
        cout << "Yes\n";
        cout << s << "\n";
        return true;
    } else {
        return false;
    }
}

void solve() {
    cin >> n;
    string s;
    cin >> s;
    ll k = 0;
    for (int i = 0; i < n - 6; i++) {
        if (s.substr(i, 7) == "abacaba") {
            k++;
        }
    }
    if (k > 1) {
        cout << "No" << endl;
        return;
    }
    if (k == 1) {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                s[i] = 'z';
            }
        }
        cout << s << "\n";
        return;
    }
    for (int i = n-7; i >= 0; i--) {
        if (can(s, i)) {
            return;
        }
    }
    cout << "No" << endl;
    return;
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