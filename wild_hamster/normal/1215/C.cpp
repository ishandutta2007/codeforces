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
#include <stack>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 30000
#define MOD 1000000007
#define LOG 18
ll n, x, k, z, m, pos, q;


ll b[100500];
vector<ll> g, f;
vector<ll> a[27][27];
vector<pii> ans;
int main() {
    cin >> n;
    string s;
    string t;
    cin >> s;
    cin >> t;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            b[s[i]-'a']++;
            b[t[i]-'a']++;
            a[s[i]-'a'][t[i]-'a'].push_back(i+1);
        }
    }
    for (int i = 0; i < 26; i++) {
        if (b[i] % 2) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ll sz = a[i][j].size();
            while (a[i][j].size() >= 2) {
                ll x = a[i][j].back();
                a[i][j].pop_back();
                ll y = a[i][j].back();
                a[i][j].pop_back();
                ans.push_back(mp(x, y));
            }
        }
    }

    if (a[0][1].size() > 0) {
        ans.push_back(mp(a[0][1][0], a[0][1][0]));
        ans.push_back(mp(a[0][1][0], a[1][0][0]));
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {cout << ans[i].X << " " << ans[i].Y << "\n";}





    return 0;
}