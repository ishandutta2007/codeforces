#include <time.h>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <stdint.h>
#include <assert.h>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 1000000000
#define OFF 2001
#define N 100000000
#define PI 3.14159265358979323846
ll n, x, k, z, m, pos, q, ans_v, y, mx;
ll x1, p1, x2;
ll a[200505], b[200505];
vector<ll> g[20050];
vector<ll> deleted;
vector<vector<ll>> ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    string s;
    cin >> s;
    ll n = s.size();
    for (int i = 0; i < 2 * n; i++) {
        deleted.clear();
        ll l = 0, r = n - 1;
        while (l < r) {
            while (l < n && (s[l] != '(' || a[l])) {
                l++;
            }
            while (r >= 0 && (s[r] != ')' || a[r])) {
                r--;
            }
            if (l < r) {
                deleted.push_back(l);
                deleted.push_back(r);
                l++;
                r--;
            }
        }
        sort(deleted.begin(), deleted.end());
        for (auto x : deleted) {
            a[x] = 1;
        }
        if (deleted.empty()) {
            break;
        }
        ans.push_back(deleted);
    }
    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x.size() << "\n";
        for (auto y : x) {
            cout << y + 1 << " ";
        }
        cout << "\n";
    }


    return 0;
}