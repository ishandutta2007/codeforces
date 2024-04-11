#include <bits/stdc++.h>
using namespace std;

long long read() {
  int n, b;
  cin >> n >> b;

  long long x = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    x = x * b + a;
  }

  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long a = read();
  long long b = read();

  if (a < b) {
    cout << "<\n";
  } else if (a == b) {
    cout << "=\n";
  } else {
    cout << ">\n";
  }
}