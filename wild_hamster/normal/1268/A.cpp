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
ll a[300500];
vector<ll> f;
string s;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    cin >> s;
    cout << n << "\n";
    for (int i = k; i < n; i++) {
        if (s[i] != s[i-k]) {
            if (s[i] > s[i-k]) {
                ll j = k - 1;
                while (s[j] == '9') {
                    s[j] = '0';
                    j--;
                }
                s[j]++;
                for (int j = k; j < n; j++) {
                    s[j] = s[j-k];
                }
                cout << s << "\n";
                return 0;
            } else {
                s[i] = s[i-k];
                for (int j = i+1; j < n; j++) {
                    s[j] = s[j-k];
                }
                cout << s << "\n";
                return 0;
            }
        }
    }
    cout << s << "\n";
    return 0;
}