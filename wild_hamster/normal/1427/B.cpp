
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
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 13
#define OFF 400001
#define MOD 1000000007
#define NN 1000000
ll n, m, k, x, y, w;
ll l[1005000], h[1005000], a[1005000];
vector<ll> f, g;
ll Abs(ll x) {
    return x > 0 ? x : -x;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    //srand(time(0));
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        string s;
        cin >> s;
        ll bad = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                bad++;
            }
        }
        if (bad == n) {
            cout << max(0LL, 2 * k - 1) << "\n";
            continue;
        }
        ll score = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'W') {
                if (i == 0 || s[i-1] == 'L') {
                    score++;
                } else {
                    score += 2;
                }
            }
        }
        if (bad <= k) {
            cout << 2 * n - 1 << "\n";
            continue;
        }
        f.clear();
        g.clear();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'W') {
                f.push_back(i);
            }
        }
        for (int i = 0; i + 1 < f.size(); i++) {
            if (f[i+1] - f[i] > 1) {
                g.push_back(f[i+1] - f[i] - 1);
            }
        }
        sort(g.begin(), g.end());
        score += k * 2;
        ll pshe = 0;
        for (auto x : g) {
            pshe += x;
            if (pshe <= k) {
                score++;
            }
        }
        cout << score << "\n";
    }

    return 0;
}