#include <bits/stdc++.h>
using namespace std;

const int N = 50;

string name[N];

string next(string cur) {
  if (cur == "Z") {
    cur = "Aa";
  } else {
    ++cur.back();
  }
  return cur;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  string cur = "A";
  for (int i = 0; i < k - 1; ++i) {
    name[i] = cur;
    cur = next(cur);
  }

  for (int i = 0; i < n - k + 1; ++i) {
    string s;
    cin >> s;

    if (s == "YES") {
      name[i + k - 1] = cur;
      cur = next(cur);
    } else {
      name[i + k - 1] = name[i];
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << name[i] << " ";
  }
  cout << "\n";
}