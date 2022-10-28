#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int where[N];
char type[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int balance = 0;
  set<int> open;

  for (int i = 0; i < 2 * n; ++i) {
    cin >> type[i];
    if (type[i] == '-') {
      --balance;
      cin >> a[i];
      where[--a[i]] = i;
    } else {
      ++balance;
      open.insert(i);
    }

    if (balance < 0) {
      cout << "NO\n";
      exit(0);
    }
  }

  for (int i = 0; i < n; ++i) {
    auto it = --open.upper_bound(where[i]);
    a[*it] = i;
    open.erase(it);
  }

  set<int> check;
  for (int i = 0; i < 2 * n; ++i) {
    if (type[i] == '+') {
      check.insert(a[i]);
    } else {
      if (*check.begin() != a[i]) {
        cout << "NO\n";
        exit(0);
      }
      check.erase(check.begin());
    }
  }

  cout << "YES\n";
  for (int i = 0; i < 2 * n; ++i) {
    if (type[i] == '+') {
      cout << a[i] + 1 << " ";
    }
  }
  cout << "\n";
}