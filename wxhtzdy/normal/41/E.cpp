#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  scanf("%i", &N);
  int E=N/2;
  printf("%i\n", E*(N-E));
  for (int i=1;i<=E;i++) {
    for (int j=E+1;j<=N;j++) {
      printf("%i %i\n", i, j);
    }
  }
}