#include <iostream>
#include <string>
using namespace std;

int main() {
  string odd = "I hate";
  string even = "I love";
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
      if (i % 2 == 1) {
          cout << odd;
      } else {
          cout << even;
      }
      if (i != n)
        cout << " that ";
  }
  cout << " it" << endl;
  return 0;
}