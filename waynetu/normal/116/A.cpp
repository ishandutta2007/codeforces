#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int stop;
  cin >> stop;
  int a, b;
  int ans = 0;
  int cap = 0;
  for (int i = 0; i < stop; ++i) {
    cin >> a >> b;
    cap += b;
    cap -= a;
    ans = max(ans, cap);
  }
  cout << ans << endl;
  return 0;
}