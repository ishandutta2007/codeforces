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
#define f first
#define s second
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

void usacoio(string s) {
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout);
}

ll amt[10];
ll n;
bool bad() {
  ll curr = 1;
  for(int i = 0; i < 10; i++) curr *= amt[i];
  return curr < n;
}
void solve() {
  cin >> n;
  for(int i = 0; i < 10; i++) amt[i] = 1;
  int i = 0;
  while(bad()) {
    amt[i++]++;
    i %= 10;
  }
  string src = "codeforces";
  for(i = 0; i < 10; i++) {
    for(int j = 0; j < amt[i]; j++) cout << src[i];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}