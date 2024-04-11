#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
 
bool can(string &s, __int128 need) {
  if (s.empty()) {
    return (need == 0);
  }
  vector<int> cnt(1010, 0);
  for (auto it : s) {
    cnt[it - 'a' + 1]++;
    need += (1 << (it - 'a'));
  }
  if (need < 0) {
    return false;
  }
  for (int i = 0; i < 1000; i++) {
    if (need & 1 != cnt[i] & 1) {
      cnt[i]--;
    }
    if (cnt[i] < 0) {
      return false;
    }
    cnt[i + 1] += cnt[i] / 2;
    need /= 2;
  }
  return true;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, need;
  cin >> n >> need;
  string s;
  cin >> s;
  need -= 1 << (s.back() - 'a');
  s.pop_back(); 
  need += 1 << (s.back() - 'a');
  s.pop_back();
  cout << (can(s, need) ? "Yes" : "No") << '\n'; 
}