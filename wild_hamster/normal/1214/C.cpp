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

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 228228
#define MOD 1000000007
ll n, x, k, z, m, a[200500], b[200500], ra[200500], rb[200500], pa, pb;
bool check(string s) {
    ll p = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            p++;
        } else {
            p--;
        }
        if (p < 0) {
            return false;
        }
    }
    if (p == 0) {
        return true;
    }
    return false;
}
int main() {
    cin >> n;
    string s;
    cin >> s;
    if (check(s)) {
        cout << "Yes" << endl;
        return 0;
    }
    ll x = 0, y = 0;
    ll l = 0, r = n;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            x++;
            l = max(l, 1LL*i);
        } else {
            y++;
            r = min(r, 1LL*i);
        }
    }
    if (x != y) {
        cout << "No" << endl;
        return 0;
    }

    {
        string t;
        t.push_back('(');
        for (int i = 0; i < s.size(); i++) {
            if (i != l) {
                t.push_back(s[i]);
            }
        }
        if (check(t)) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    {
        string t;
        for (int i = 0; i < s.size(); i++) {
            if (i != r) {
                t.push_back(s[i]);
            }
        }

        t.push_back(')');
        if (check(t)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;




    return 0;
}