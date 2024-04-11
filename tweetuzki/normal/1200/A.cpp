#include <bits/stdc++.h>
using namespace std;

int N;
string S;
int B[10];

int main() {
  cin >> N;
  cin >> S;
  for (int i = 0; i < N; ++i) {
    if (S[i] == 'L') {
      for (int j = 0; j < 10; ++j)
        if (B[j] == 0) {
          B[j] = 1;
          break;
        }
    } else if (S[i] == 'R') {
      for (int j = 9; j >= 0; --j)
        if (B[j] == 0) {
          B[j] = 1;
          break;
        }
    } else B[S[i] - '0'] = 0;
  }
  for (int i = 0; i < 10; ++i) printf("%d", B[i]);
  putchar('\n');
  return 0;
}