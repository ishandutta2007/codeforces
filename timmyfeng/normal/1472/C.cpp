#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }

    vector<long long> score(n);
    for (int i = n - 1; i >= 0; --i) {
      score[i] = (i + a[i] >= n) ? a[i] : score[i + a[i]] + a[i];
    }

    cout << *max_element(score.begin(), score.end()) << "\n";
  }
}