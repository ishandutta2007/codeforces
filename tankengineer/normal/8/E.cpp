//CF 7E
#include<cstdio>
#include<algorithm>

using namespace std;

int n;
long long cnt, k, pow2[65];
char str[55];
bool flag;

int main() {
  scanf("%d %I64d", &n, &k);
  n--; k++; pow2[0] = 1;
  for (int i = 1; i <= 60; i++) {
    pow2[i] = pow2[i - 1] << 1;
  }
  
  for (int i = 0; i <= n; i++) {
    str[i] = '0';
    cnt = 0;
    
    flag = false;
    for (int j = 0; j <= (n - 1) / 2; j++) {
      if (j && str[j] != '1' && str[n - j] != '0') {
        cnt += pow2[max(0, j - i - 1)] * pow2[min(max(0, n - j - i - 1), n - 2 * j - 1)];
      }
      if (str[j] == '1' && str[n - j] == '0' || str[j] == '0' && str[n - j] == '1') {
        flag = true;
        break;
      }
    }
    if (!flag) {
      cnt += pow2[max(0, n / 2 - i)];
    }
    
    flag = false;
    for (int j = 0; j <= n / 2; j++) {
      if (j && str[j] != '1' && str[n - j] != '1') {
        cnt += pow2[max(0, j - i - 1)] * pow2[min(max(0, n - j - i - 1), max(0, n - 2 * j - 1))];
      }
      if (str[j] == '0' && str[n - j] == '0' || str[j] == '1' && str[n - j] == '1') {
        flag = true;
        break;
      }
    }
    if (!flag && n % 2) {
      cnt += pow2[max(0, n / 2 - i)];
    }
    
//    printf("%d %I64d\n", i, cnt);
    
    if (cnt < k) {
      if (i == 0) {
        puts("-1");
        return 0 ;
      }
      str[i] = '1';
      k -= cnt;
    }
    
  }
  
  printf("%s\n", str);
  
  return 0;
}