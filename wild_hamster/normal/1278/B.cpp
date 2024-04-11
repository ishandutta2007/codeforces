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
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
ll a[300500], b[300500];
vector<ll> f;
string str;

bool equal() {
    for (int j = 0; j < 26; j++) {
        if (a[j] != b[j]) {
            return false;
        }
    }
    return true;
}
int main() {
    cin >> n;
    string s, t;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (x < y) {
            swap(x, y);
        }
        x -= y;
        z = 0;
        for (int i = 0; i <= 100000; i++) {
            z += i;
            if (z % 2 == x % 2 && z >= x) {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;

}