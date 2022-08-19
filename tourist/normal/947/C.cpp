/**
 *    author:  tourist
 *    created: 10.03.2018 19:06:26       
**/
#include <bits/stdc++.h>

using namespace std;

const int BITS = 30;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), p(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<int> stub(2, -1);
  vector< vector<int> > trie(1, stub);
  vector<int> sub(1, 0);
  for (int i = 0; i < n; i++) {
    int t = 0;
    sub[0]++;
    for (int j = BITS - 1; j >= 0; j--) {
      int k = (p[i] >> j) & 1;
      if (trie[t][k] == -1) {
        trie[t][k] = (int) trie.size();
        trie.push_back(stub);
        sub.push_back(0);
      }
      t = trie[t][k];
      sub[t]++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    int ans = 0;
    int t = 0;
    sub[t]--;
    for (int j = BITS - 1; j >= 0; j--) {
      int k = (a[i] >> j) & 1;
      if (trie[t][k] == -1 || sub[trie[t][k]] == 0) {
        k ^= 1;
        ans ^= (1 << j);
      }
      assert(!(trie[t][k] == -1 || sub[trie[t][k]] == 0));
      t = trie[t][k];
      sub[t]--;
    }
    cout << ans;
  }
  cout << '\n';
  return 0;
}