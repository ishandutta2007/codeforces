//177B
#include<cstdio>
#include<algorithm>
using namespace std;

int top, cnt;
long long n, p[500000], ans;
bool flag;

void play(long long &n) {
  while (cnt <= top && n % p[cnt] != 0) cnt++;
  if (cnt > top || p[cnt] == n) {
    n = 1;
    return;
  }
  n = n / p[cnt];
}

int main() {
  top = 0;
  for (int i = 2; i <= 100000; i++) {
    flag = false;
    for (int j = 1; j <= top; j++) {
      if (i % p[j] == 0) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      top++;
      p[top] = i;
    } 
  }
  scanf("%I64d", &n);
  if (n == 0) {
    printf("0\n");
    return 0;
  }
  ans += n;
  cnt = 1;
  while (n != 1) {
    play(n);
    ans += n;
  }
  printf("%I64d\n", ans);
  return 0;
}