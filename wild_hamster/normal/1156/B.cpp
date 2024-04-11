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
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[100500], b[100500];
ll dp[505][505];
bool fuck(string s) {
    for (int i = 0; i + 1 < s.size(); i++) {
        ll x = s[i] - s[i+1];
        if (x == 1 || x == -1) {
            return true;
        }
    }
    return false;
}
int main() {
    //freopen("input.txt", "r", stdin);
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        for (int i = 0; i < 26; i++) {
            a[i] = 0;
        }
        for (int i = 0; i < s.size(); i++) {
            a[s[i]-'a']++;
        }
        string ans;
        for (int i = 1; i < 26; i+=2) {
            for (int j = 0; j < a[i]; j++) {
                ans.push_back(i + 'a');
            }
        }
        for (int i = 0; i < 26; i+=2) {
            for (int j = 0; j < a[i]; j++) {
                ans.push_back(i + 'a');
            }
        }
        if (!fuck(ans)) {
            cout << ans << endl;
            continue;
        }
        ans.clear();
        for (int i = 25; i >= 1; i-=2) {
            for (int j = 0; j < a[i]; j++) {
                ans.push_back(i + 'a');
            }
        }
        for (int i = 0; i < 26; i+=2) {
            for (int j = 0; j < a[i]; j++) {
                ans.push_back(i + 'a');
            }
        }
        if (!fuck(ans)) {
            cout << ans << endl;
            continue;
        }

        ans.clear();
        for (int i = 25; i >= 1; i-=2) {
            for (int j = 0; j < a[i]; j++) {
                ans.push_back(i + 'a');
            }
        }
        for (int i = 24; i >= 0; i-=2) {
            for (int j = 0; j < a[i]; j++) {
                ans.push_back(i + 'a');
            }
        }
        if (!fuck(ans)) {
            cout << ans << endl;
            continue;
        }

        ans.clear();
        for (int i = 1; i <= 25; i+=2) {
            for (int j = 0; j < a[i]; j++) {
                ans.push_back(i + 'a');
            }
        }
        for (int i = 24; i >= 0; i-=2) {
            for (int j = 0; j < a[i]; j++) {
                ans.push_back(i + 'a');
            }
        }
        if (!fuck(ans)) {
            cout << ans << endl;
            continue;
        }
        cout << "No answer" << endl;
    }
    return 0;
}