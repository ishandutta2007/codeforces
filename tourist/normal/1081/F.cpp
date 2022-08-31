/**
 *    author:  tourist
 *    created: 16.12.2018 18:05:23       
**/
#include <bits/stdc++.h>

using namespace std;

int queries_left = 9999;

int ask(int x, int y) {
  queries_left--;
  cout << "? " << x + 1 << " " << y + 1 << endl;
  int z;
  cin >> z;
  return z;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  vector<int> res;
  int last = t;
  int in_first = 0;
  int bits_left = n - 1;
  for (int bit = 0; bit < n - 1; bit++) {
    int can_do = queries_left / bits_left / 2;
    int found = 0;
    for (int it = 0; it < can_do; it++) {
      ask(bit + 1, n - 1);
      int u = ask(bit + 1, n - 1);
      if (u != last) {
        int must_be = last - (in_first) + ((bit + 1) - (in_first)); // - 2 * me
        int diff = must_be - u;
        if (diff != 0 && diff != 2) {
          assert(false);
        }
        int me = diff / 2;
        res.push_back(me);
        in_first = (bit + 1) - (in_first + me);
        assert(0 <= in_first && in_first <= bit + 1);
        last = u;
        found = 1;
        break;
      }
      last = u;
    }
    if (!found) {
      int me = (bit + 1) / 2 - in_first;
      assert(me == 0 || me == 1);
      res.push_back(me);
      in_first += me;
    }
    bits_left--;
  }
  int cur = accumulate(res.begin(), res.end(), 0);
  int last_bit = t - cur;
  assert(last_bit == 0 || last_bit == 1);
  res.push_back(last_bit);
  cout << "! ";
  for (int x : res) {
    cout << x;
  }
  cout << endl;
  return 0;
}