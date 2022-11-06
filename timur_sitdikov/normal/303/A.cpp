#include <iostream>
#include <vector>
using namespace std;



// To execute C++, please define "int main()"
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << -1 << endl;
    return 0;
  }
  for(int j = 0; j < 2; j++) {
    for(int i = 0; i < n; i++) {
      cout << i << " ";
    }
    cout << endl;
  }
  for(int i = 0; i < n; i++) {
    cout << (2 * i) % n << " ";
  }
  return 0;
}