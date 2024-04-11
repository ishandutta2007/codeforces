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

void rsolve() {
  int n;
  cin >> n;
  vector<int> v;
  for(int i = 1; i * i <= n; i++) {
    if(n%i) continue;
    v.push_back(i);
    if(i*i != n) v.push_back(n/i);
  }
  sort(all(v));
  v.erase(v.begin());
  for(int i = 0; i < sz(v); i++) {
    int want = n / v[i];
    for(int j = 0; j < i && v[j] * v[j] < want; j++) {
      if(want%v[j]) continue;
      int a = want / v[j];
      if(a == v[i] || a == v[j]) continue;
      cout << "YES\n";
      cout << v[i] << " " << v[j] << " " << want / v[j] << "\n";
      return;
    }
  }
  cout << "NO\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) rsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}