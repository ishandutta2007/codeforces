//CF 7A
#include<cstdio>
#include<cstring>

int ans;
char map[9][9];
bool flag;

int main() {
  for (int i = 1; i <= 8; i++) {
    gets(map[i]);
    for (int j = 0; j < 8; j++) {
      flag = flag || map[i][j] == 'W';
    }
  }
  
  if (!flag) { 
    printf("8\n");
    return 0;
  }

  ans = 0;
  for (int i = 1; i <= 8; i++) {
    flag = false;
    for (int j = 0; j < 8; j++) {
      flag = flag || map[i][j] == 'W';
    }
    ans = ans + (flag ? 0 : 1);
  }
  for (int i = 0; i < 8; i++) {
    flag = false;
    for (int j = 1; j <= 8; j++) {
      flag = flag || map[j][i] == 'W';
    }
    ans = ans + (flag ? 0 : 1);
  }
  
  printf("%d\n", ans);
  
  return 0;
}