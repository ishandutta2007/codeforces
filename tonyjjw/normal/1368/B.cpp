#include <stdio.h>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

const int N = 10;

int A[N+1];
char s[] = "codeforces";

int main() {
  ll K;
  scanf("%lld", &K);
  for(int cnt = 0;; cnt++) {
    for(int p = 0; p < N; p++) {
      A[p]++;
      ll mul = 1;
      for(int i = 0; i < N; i++) {
        mul = mul * A[i];
      }
  
      if (mul >= K) {
        for(int i = 0; i < N; i++) {
          for(int j = 0; j < A[i]; j++) {
            printf("%c", s[i]);
          }
        }
        puts("");
        return 0;
      }
    }

  }
  return 0;
}