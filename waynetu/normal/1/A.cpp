#include <iostream>
using namespace std;

int main() {
  long long int n, m, a;
  cin >> n >> m >> a;
  if (n % a != 0) {
    n = n / a + 1;
  } else {
    n = n / a;
  }
  if (m % a != 0) m = m / a + 1;
  else m = m / a;
  cout << n * m << endl;
  return 0;
}