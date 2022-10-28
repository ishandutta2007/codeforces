#include <bits/stdc++.h>
using namespace std;

const int A = 26;

int freq[A];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  long long t;
  cin >> n >> t >> s;

  for (auto &i : s) {
    i -= 'a';
  }

  t -= 1 << s.back();
  s.pop_back();
  t += 1 << s.back();
  s.pop_back();

  for (auto i : s) {
    ++freq[(int) i];
  }

  for (int i = A - 1; i >= 0; --i) {
    for (int j = 0; j < freq[i]; ++j) {
      if (t > 0) {
        t -= 1 << i;
      } else {
        t += 1 << i;
      }
    }
  }

  cout << (t == 0 ? "Yes" : "No") << "\n";
}