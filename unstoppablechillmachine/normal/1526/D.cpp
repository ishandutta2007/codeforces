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

map<char, int> nxt;

int calculate(const string& s, vector<char>& order, map<char, int>& cnt) {
  int already = 0;
  for (auto it : order) {
    nxt[it] = already;
    already += cnt[it];
  }
  int sum = 0;
  for (int i = 0; i < SZ(s); i++) {
    sum += nxt[s[i]] - i;
    for (auto it : order) {
      nxt[it]++;
      if (it == s[i]) {
        break;
      }
    }
  }
  return sum;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    map<char, int> cnt;
    for (auto it : s) {
      cnt[it]++;
    }
    vector<char> kek = {'A', 'N', 'T', 'O'};
    sort(all(kek));
    pair<int, vector<char>> best;
    do {
      best = max(best, make_pair(calculate(s, kek, cnt), kek));
    } while (next_permutation(all(kek)));
    //cout << best.second << '\n';
    for (auto it : best.second) {
      cout << string(cnt[it], it);
    }
    cout << '\n';
  }
}