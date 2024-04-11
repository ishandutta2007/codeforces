#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  cin >> n;
  int sum = 0, i;
  for (i = 1; ; ++i) {
    sum += i;
    if (n < sum) break;
    n -= sum;
  }
  cout << i - 1 << '\n';
}