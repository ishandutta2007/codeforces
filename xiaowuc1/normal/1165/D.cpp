#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

bool prime(int n) {
  if(n < 2) return false;
  for(int i = 2; i * i <= n; i++) if(n%i == 0) return false;
  return true;
}

void realsolve() {
  int n;
  cin >> n;
  vector<ll> v;
  for(int i = 0; i < n; i++) {
    ll t;
    cin >> t;
    v.push_back(t);
  }
  sort(v.begin(), v.end());
  if(v.size() == 1) {
    if(!prime(v[0])) cout << "-1\n";
    else cout << v[0] * v[0] << "\n";
    return;
  }
  ll cand = v[0] * v[v.size()-1];
  for(int i = 0; i < v.size(); i++) {
    if(cand != v[i] * v[v.size()-1-i]) {
      cout << "-1\n";
      return;
    }
  }
  int numD = 0;
  for(ll i = 2; i * i <= cand; i++) {
    if(cand%i==0) {
      numD++;
      if(i*i!=cand) numD++;
    }
  }
  if(numD != v.size()) cand = -1;
  cout << cand << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) realsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}