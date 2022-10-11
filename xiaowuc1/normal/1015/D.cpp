#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void die() {
  cout << "NO\n";
  exit(0);
}

void solve() {
  ll n, k, s;
  cin >> n >> k >> s;
  if(s < k) die();
  if(k*(n-1) < s) die();
  if(k == 1) {
    cout << "YES\n";
    cout << (1+s) << "\n";
    return;
  }
  ll change = k*(n-1);
  vector<int> v;
  v.push_back(1);
  for(int i = 1; i <= k; i++) {
    v.push_back(i%2 == 1 ? n : 1);
  }
  change -= s;
  if(change%2) {
    if(v[v.size()-1] == 1) v[v.size()-1]++;
    else v[v.size()-1]--;
    change--;
  }
  for(int i = 1; change >= 0 && i <= k; i += 2) {
    ll shift;
    if(i < k) {
      shift = min(n-2, change/2);
      v[i] -= shift;
      change -= 2*shift;
    }
    else {
      shift = change;
      v[i] -= shift;
    }
  }
  cout << "YES\n";
  for(int i = 1; i <= k; i++) cout << v[i] << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}