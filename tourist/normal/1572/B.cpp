/**
 *    author:  tourist
 *    created: 18.09.2021 18:43:50       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    if (pref[n] % 2 == 1) {
      cout << "NO" << '\n';
      continue;
    }
    vector<int> seq;
    int pos = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0 && pref[i] % 2 == 0) {
        pos = i;
        break;
      }
    }
    if (pos == -1) {
      int last = -1;
      for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
          if (last != -1 && (i - last) % 2 == 0) {
            for (int j = last; j <= i - 2; j += 2) {
              seq.push_back(j);
            }
            for (int j = i - 4; j >= last; j -= 2) {
              seq.push_back(j);
            }
            a[last] = 0;
            a[i] = 0;
            pos = i;
            break;
          }
          last = i;
        }
      }
      if (pos == -1) {
        cout << "NO" << '\n';
        continue;
      }
    }
    {
      int at = pos + 1;
      while (at < n) {
        if (a[at] == 0) {
          ++at;
        } else {
          assert(at + 1 < n);
          if (a[at + 1] == 1) {
            seq.push_back(at - 1);
            a[at] = a[at + 1] = 0;
            at += 2;
          } else {
            assert(at + 2 < n);
            seq.push_back(at);
            int v = a[at] ^ a[at + 1] ^ a[at + 2];
            a[at] = a[at + 1] = a[at + 2] = v;
          }
        }
      }
    }
    {
      int at = pos - 1;
      while (at >= 0) {
        if (a[at] == 0) {
          --at;
        } else {
          assert(at - 1 >= 0);
          if (a[at - 1] == 1) {
            seq.push_back(at - 1);
            a[at] = a[at - 1] = 0;
            at -= 2;
          } else {
            assert(at - 2 >= 0);
            seq.push_back(at - 2);
            int v = a[at] ^ a[at - 1] ^ a[at - 2];
            a[at] = a[at - 1] = a[at - 2] = v;
          }
        }
      }
    }
    cout << "YES" << '\n';
    cout << seq.size() << '\n';
    for (int i = 0; i < (int) seq.size(); i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << seq[i] + 1;
    }
    cout << '\n';
  }
  return 0;
}