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
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> pipii;


int freq[256];
bool can(string s) {
  for(int i = 0; i < s.size(); i++) {
    if(freq[s[i]] == 0) return false;
  }
  for(int i = 0; i < s.size(); i++) {
    --freq[s[i]];
  }
  return true;
}
void solve() {
  string s;
  cin >> s >> s;
  for(int i = 0; i < s.size(); i++) {
    freq[s[i]]++;
  }
  vector<int> ret;
  while(can("one")) {
    ret.push_back(1);
  }
  while(can("zero")) {
    ret.push_back(0);
  }
  for(int i = 0; i < ret.size(); i++) {
    if(i) cout << " ";
    cout << ret[i];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}