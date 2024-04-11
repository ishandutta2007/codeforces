#include <bits/stdc++.h>
using namespace std;

const int N = 100;

bool b[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> vals;
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
      if (!b[i]) {
        vals.push_back(a[i]);
      }
    }
    sort(vals.rbegin(), vals.rend());
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
      if (!b[i]) {
        cout << vals[ptr] << " ";
        ++ptr;
      } else {
        cout << a[i] << " ";
      }
    }
    cout << "\n";
  }
}