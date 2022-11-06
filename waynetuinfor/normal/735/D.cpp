#include <iostream>
#include <cmath>
using namespace std;

int n;
bool prime(int);

int main() {
  cin >> n;
  if (prime(n)) cout << "1\n";
  else if (prime(n - 2) || n % 2 == 0) cout << "2\n";
  else cout << "3\n";
  return 0;
}

bool prime(int n) {
  for (int i = 2; i <= sqrt(n); ++i) if (n % i == 0) return false;
  return true;
}