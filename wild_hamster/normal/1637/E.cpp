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
#define mp make_pair
#define X first
#define Y second
 
typedef long long ll;
using namespace std;
 
ll n, t, k, x, y, m;
ll a[100500], b[100500];
ll dp[105][20050];
map<ll, ll> freq;
string s;
vector<ll> g[300500];
set<ll> shits;
vector<ll> real_shits;
vector<pii> forbidden;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> t;
  for (int ii = 0; ii < t; ii++){
    freq.clear();
    forbidden.clear();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> x;
      freq[x]++;
    }
    for (int i = 0; i < m; i++) {
      cin >> x >> y;
      forbidden.push_back(mp(x, y));
    }
    sort(forbidden.begin(), forbidden.end());
    shits.clear();
    for (auto x : freq) {
      shits.insert(x.Y);
      g[x.Y].push_back(x.X);
    }
    real_shits.clear();
    for (auto x : shits) {
      real_shits.push_back(x);
      sort(g[x].begin(), g[x].end());
      reverse(g[x].begin(), g[x].end());
    }
 
    ll ans = 0;
    for (int i = 0; i < real_shits.size(); i++) {
      for (int j = i; j < real_shits.size(); j++) {
        ll l = real_shits[i];
        ll r = real_shits[j];
        ll mi = 0;
        ll szl = g[l].size();
        ll szr = g[r].size();
        bool good = false;
        ll last_index = szl - 1;
        for (int i = 0; i < szl; i++) {
          pii cur_pair = mp(g[l][i], g[r][0]);
          if (cur_pair.X > cur_pair.Y) {
            std::swap(cur_pair.X, cur_pair.Y);
          }
          if (cur_pair.X != cur_pair.Y && !binary_search(forbidden.begin(), forbidden.end(), cur_pair)) {
            ans = max(ans, (cur_pair.X + cur_pair.Y) * (l + r));
            last_index = i - 1;
            break;
          }
        }
        for (int i = 0; i <= last_index; i++) {
          for (int j = 1; j < szr; j++) {
            pii cur_pair = mp(g[l][i], g[r][j]);
            if (cur_pair.X > cur_pair.Y) {
              std::swap(cur_pair.X, cur_pair.Y);
            }
            if (cur_pair.X != cur_pair.Y && !binary_search(forbidden.begin(), forbidden.end(), cur_pair)) {
              ans = max(ans, (cur_pair.X + cur_pair.Y) * (l + r));
              break;
            }
          }
        }
      }
    }
    cout << ans << "\n";
 
 
 
    for (auto x : real_shits) {
      g[x].clear();
    }
    real_shits.clear();
  }
  return 0;
}