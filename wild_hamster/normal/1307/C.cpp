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
vector<pii> g[200500];
ll a[1000500];
vector<ll> f;
ll d[27][27];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    ll n = s.size();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            d[j][s[i]-'a'] += a[j];
        }
        a[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        ans = max(ans, a[i]);
    }
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++) {
            ans = max(ans, d[i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}