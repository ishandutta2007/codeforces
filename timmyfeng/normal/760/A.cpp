#include <bits/stdc++.h>
using namespace std;

const int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, d;
  cin >> m >> d;
  cout << (d - 1 + M[m - 1] + 7 - 1) / 7 << "\n";
}