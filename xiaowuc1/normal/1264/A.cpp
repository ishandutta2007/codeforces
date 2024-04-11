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
typedef pair<ll, ll> pll;

void rsolve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  int g = 0;
  int s = 0;
  int b = 0;
  // gold
  int i = 0;
  {
    int j = i+1;
    while(j < n && v[i] == v[j]) j++;
    g = j-i;
    i = j;
  }
  while(s <= g) {
    int j = i+1;
    while(j < n && v[i] == v[j]) j++;
    s += j-i;
    i = j;
  }
  while(true) {
    int j = i+1;
    while(j < n && v[i] == v[j]) j++;
    int add = j-i;
    if(b <= g) b += add;
    else if((g+s+b+add)*2 <= n) b += add;
    else break;
    i = j;
  }
  if((g+s+b)*2 > n) {
    g=0;
    s=0;
    b=0;
  }
  cout << g << " " << s << " " << b << "\n";
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