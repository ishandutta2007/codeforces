#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  int x[300000];
  cin >> n;
  int dis = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  sort(x, x + n);
  if (n % 2 == 1) {
    int op = x[n / 2];
    cout << op << endl;
    // return 0;
  } else {
    int dis1 = 0;
    int dis2 = 0;
    int op1 = x[n / 2];
    int op2 = x[n / 2 - 1];
    for (int i = 0; i < n; ++i) {
      dis1 += abs(op1 - x[i]);
      dis2 += abs(op2 - x[i]);
    }
    int op = dis1 > dis2 ? op1 : op2;
    cout << op << endl;

  }
  return 0;
}