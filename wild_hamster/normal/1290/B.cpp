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

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 1000000
#define OFF 200001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll a[200500][30];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    string s;
    cin >> s;
    ll n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            a[i+1][j] = a[i][j];
        }
        a[i+1][s[i]-'a']++;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        l--; r--;
        if (l == r) {
            cout << "Yes\n";
            continue;
        }
        ll letters = 0;
        for (int j = 0; j < 26; j++) {
            ll x = a[r+1][j] - a[l][j];
            if (x > 0) {
                letters++;
            }
        }
        if (letters > 2) {
            cout << "Yes\n";
            continue;
        }
        if (letters == 1) {
            cout << "No\n";
            continue;
        }
        if (s[l] == s[r]) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }

    return 0;

}