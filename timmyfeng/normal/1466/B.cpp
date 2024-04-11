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
    set<int> song;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (song.count(a) == 0) {
        song.insert(a);
      } else {
        song.insert(a + 1);
      }
    }

    cout << song.size() << "\n";
  }
}