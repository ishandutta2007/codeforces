#include <bits/stdc++.h>
using namespace std;

const int A = 26;

int freq[A];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    string a, b;
    cin >> n >> k >> a >> b;

    fill(freq, freq + A, 0);
    for (auto i : a) {
      ++freq[i - 'a'];
    }
    for (auto i : b) {
      --freq[i - 'a'];
    }

    bool ok = true;
    int balance = 0;
    for (int i = 0; i < A; ++i) {
      ok &= freq[i] % k == 0;
      balance += freq[i];
      ok &= balance >= 0;
    }

    cout << (ok ? "Yes" : "No") << "\n";
  }
}