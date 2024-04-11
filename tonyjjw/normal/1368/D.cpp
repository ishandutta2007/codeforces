#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MN = 2e5;
const int MK = 20;
int N;
int cnt[MK];

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    int a;
    scanf("%d", &a);
    for(int k = 0; k < MK; k++) {
      if (a & (1 << k)) cnt[k]++;
    }
  }

  long long ans = 0;
  for(int i = 0; i < N; i++) {
    int a = 0;
    for(int k = 0; k < MK; k++) {
      if(cnt[k] > 0) {
        cnt[k]--;
        a += (1 << k);
      }
    }
    ans += (long long) a * a;
  }
  printf("%lld\n", ans);
  return 0;
}