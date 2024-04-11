#include <bits/stdc++.h>
using namespace std;

const int N = 5555 * 2;

char s[N];
int n;
double ans;

int num[27][N][27] , All[27];

int pd(int x) {
  int ans = 0;
  for(int i = 1;i <= n;++ i) {
    int now = 0;
    for(int j = 0;j < 26;++ j)
      if(num[x][i][j] == 1) ++ now;
    ans = max(ans , now);
  }
  return ans;
}

int main() {
  scanf("%s" , s + 1);
  n = strlen(s + 1);
  for(int i = 1;i <= n - 1;++ i)
    s[i + n] = s[i];
  for(int i = 1;i <= n;++ i) {
    ++ All[s[i] - 'a'];
    for(int j = i;j <= i + n - 1;++ j) {
      ++ num[s[i] - 'a'][j - i + 1][s[j] - 'a'];
    }
  }
  for(int i = 0;i < 26;++ i) {
    ans += pd(i);
  }
  ans = ans / n;
  printf("%.12lf\n" , ans);
}