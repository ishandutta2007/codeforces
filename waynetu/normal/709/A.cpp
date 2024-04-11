#include <iostream>
using namespace std;

int main() {
  int n, b, d;
  int a[100000];
  cin >> n >> b >> d;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int t = 0;
  int waste = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > b) continue;
    waste += a[i];
    if (waste > d) {
      t++;
      waste = 0;
    }
  }
  cout << t << endl;
  return 0;
}