#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  priority_queue<int> function;
  long long x = 0;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    a += n - i;

    function.push(a);
    function.push(a);
    function.pop();

    x += a;
  }

  while (!function.empty()) {
    x -= function.top();
    function.pop();
  }

  cout << x << "\n";
}