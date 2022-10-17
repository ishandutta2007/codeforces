#include <iostream>
#include <cstring>
using namespace std;

int p[1000];
int main() {
  memset(p, 0, sizeof(p));
  int n;
  cin >> n;
  int x;
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < 3; ++i) {
      cin >> x;
      if (x) p[j]++;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (p[i] >= 2) cnt++;
  }
  cout << cnt << endl;
  return 0;
}