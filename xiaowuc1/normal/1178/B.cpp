#include <algorithm>
#include <bitset>
#include <cassert>
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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<double, double> pdd;

void solve() {
  ll a = 0;
  ll b = 0;
  ll c = 0;
  string s;
  cin >> s;
  for(int i = 0; i < s.size(); i++) {
    ll na = a;
    ll nb = b;
    ll nc = c;
    if(i > 0 && s[i] == 'v' && s[i-1] == 'v') na++;
    if(s[i] == 'o') nb += a;
    if(i > 0 && s[i] == 'v' && s[i-1] == 'v') nc += b;
    a = na;
    b = nb;
    c = nc;
  }
  cout << c << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << " ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}