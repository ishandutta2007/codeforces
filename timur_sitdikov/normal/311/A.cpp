#include <iostream>
#include <vector>
using namespace std;

const int kCoefficient = 1e4;

void HackBadAlgorithm(int n, int k) {
  if (k >= n * (n - 1) / 2) {
    cout << "no solution" << endl;
    return;
  }
  for(int i = 0; i < n; i++){
    cout << i << " " << i * kCoefficient << endl;
  }
}

// To execute C++, please define "int main()"
int main() {
  int n, k;
  cin >> n >> k;
  HackBadAlgorithm(n, k);
  return 0;
}

/*
Test #1

Answer


Test #2

Answer

*/