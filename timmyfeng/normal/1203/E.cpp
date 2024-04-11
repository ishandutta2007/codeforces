#include <bits/stdc++.h>
using namespace std;

const int A = 150'000 + 1;

multiset<int> boxers;

bool remove(int i) {
  auto it = boxers.find(i);
  if (it != boxers.end()) {
    boxers.erase(it);
    return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    boxers.insert(a);
  }

  int ans = 0;
  for (int i = 1; i <= A; ++i) {
    for (auto j : {i - 1, i, i + 1}) {
      if (remove(j)) {
        ++ans;
        break;
      }
    }
  }

  cout << ans << "\n";
}