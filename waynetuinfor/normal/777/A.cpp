#include <bits/stdc++.h>
using namespace std;

int osas[6][3] = {
  { 0, 1, 2 },
  { 1, 0, 2 },
  { 1, 2, 0 },
  { 2, 1, 0 },
  { 2, 0, 1 },
  { 0, 2, 1 }
};

int n, x;

int main() {
  cin >> n >> x;
  cout << osas[n % 6][x] << '\n';
  return 0;
}