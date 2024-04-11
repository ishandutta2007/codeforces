#include <bits/stdc++.h>

using namespace std;

const int N = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  int a = t1 * 2 + v1 * s, b = t2 * 2 + v2 * s;
  if (a == b) {
    cout << "Friendship";
  } else {
    if (a < b) {
      cout << "First";
    } else {
      cout << "Second";
    }
  }
  return 0;
}