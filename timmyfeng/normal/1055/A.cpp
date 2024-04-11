#include <bits/stdc++.h>
using namespace std;

const int N = 1'000;

bool a[N];
bool b[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;
  --s;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  if (!a[0]) {
    cout << "No\n";
    exit(0);
  }

  if (a[s]) {
    cout << "Yes\n";
    exit(0);
  }

  if (!b[s]) {
    cout << "No\n";
    exit(0);
  }

  for (int i = s + 1; i < n; ++i) {
    if (a[i] && b[i]) {
      cout << "Yes\n";
      exit(0);
    }
  }

  cout << "No\n";
}