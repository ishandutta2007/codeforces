#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a, b;
  
  int m = 0;
  int c = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    if (a > b) {
      m++;
    } else if (b > a) {
      c++;
    }
   }
   
  if (m > c) cout << "Mishka\n";
  else if (c > m) cout << "Chris\n";
  else cout << "Friendship is magic!^^\n";
  return 0;
}