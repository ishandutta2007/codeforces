#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  multiset<long long> alice;
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    alice.insert(a);
  }

  multiset<long long> borys;
  while (true) {
    long long k = 1;
    while (alice.count(k) > 0) {
      alice.erase(alice.find(k));
      k *= 2;
    }

    if (k == 1) {
      break;
    }
    borys.insert(k);
  }

  int max_m = borys.size();
  while (!alice.empty()) {
    if (borys.empty() || *(--borys.end()) < *(--alice.end())) {
      cout << -1 << "\n";
      exit(0);
    }
    alice.erase(--alice.end());
    borys.erase(--borys.end());
  }

  int min_m = max_m;
  while (!borys.empty()) {
    long long k = *borys.begin();
    borys.erase(borys.begin());
    int log_k = 0;
    while (k > 1) {
      ++log_k;
      k /= 2;
    }

    if ((int) borys.size() < log_k) {
      break;
    }

    --min_m;
    while (log_k--) {
      borys.erase(--borys.end());
    }
  }

  for (int i = min_m; i <= max_m; ++i) {
    cout << i << " ";
  }
  cout << "\n";
}