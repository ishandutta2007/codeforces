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
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x;
ll a[1005][1005], rowmx[1005], rownow[1005][1005], colmx[1005], colnow[1005][1005];
map<ll, ll> f;

vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}
int main() {
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    string T = t+t;
    vector<int> z = z_function(t);
    x = t.size();
    for (int i = 1; i < z.size(); i++) {
        if (z[i] >= t.size() - i) {
            x = i;
            break;
        }
    }
    int tt[2];
    tt[0] =tt[1] = 0;
    for (int i = 0; i < s.size(); i++) {
        tt[s[i]-'0']++;
    }
    int r[2];
    r[0] = r[1] = 0;
    for (int i = 0; i < t.size(); i++) {
        r[t[i]-'0']++;
    }
    string ans = t;
    if (r[0] > tt[0] || r[1] > tt[1]) {
        cout << s << endl;
        return 0;
    }
    int p[2];
    p[0] = p[1] = 0;
    for (int i = t.size() - x; i < t.size(); i++) {
        p[t[i]-'0']++;
    }
    while (r[0] + p[0] <= tt[0] && r[1] + p[1] <= tt[1]) {
        ans.append(t.substr(t.size()-x));
        r[0] += p[0];
        r[1] += p[1];
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < tt[i] - r[i]; j++)
            ans.push_back(i+'0');
        cout << ans << endl;

    return 0;
}