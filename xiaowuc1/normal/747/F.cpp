#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;

map<ll, ll> dp[20];
ll count(int left, vector<int>& freq) {
  if(left == 0) return 1;
  ll mask = 0;
  {
    vector<int> v = freq;
    sort(all(v));
    for(int out: v) {
      mask <<= 4;
      mask |= out;
    }
    if(dp[left].count(mask)) return dp[left][mask];
  }
  ll ret = 0;
  for(int i = 0; i < 16; i++) {
    if(freq[i]) {
      freq[i]--;
      ret += count(left-1, freq);
      freq[i]++;
    }
  }
  dp[left][mask] = ret;
  return ret;
}

void solve() {
  int k, maxallow;
  cin >> k >> maxallow;
  int wantlen = -1;
  vector<int> pref;
  vector<int> v(16, maxallow);
  for(int len = 1; wantlen < 0; len++) {
    for(int i = 1; i < 16; i++) {
      v[i]--;
      if(count(len-1, v) >= k) {
        wantlen = len-1;
        pref.push_back(i);
        break;
      }
      k -= count(len-1, v);
      v[i]++;
    }
  }
  while(wantlen) {
    bool found = false;
    for(int a = 0; a < 16; a++) {
      if(v[a]) {
        v[a]--;
        if(count(wantlen-1, v) >= k) {
          found = true;
          wantlen--;
          pref.push_back(a);
          break;
        }
        k -= count(wantlen-1, v);
        v[a]++;
      }
    }
    assert(found);
  }
  for(int out: pref) {
    cout << "0123456789abcdef"[out];
  } cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}