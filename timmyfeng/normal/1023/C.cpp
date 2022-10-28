#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  string s, t;
  cin >> n >> k >> s;

  int balance = 0;
  for (auto i : s) {
    if (i == '(') {
      ++balance;
    } else {
      --balance;
    }
    t += i;

    if ((int) t.size() + balance == k) {
      t += string(balance, ')');
      break;
    }
  }

  cout << t << "\n";
}