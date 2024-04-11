#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char s[205];
bool flag;

int main() {
  gets(s);
  int l = strlen(s);
  flag = false;
  for (int i = 0; i < l; ++i) {
    if (flag) {
      if (s[i] == '.') {
        printf("1");
      } else {
        printf("2");
      }
      flag = false;
    } else {
      if (s[i] == '.') {
        printf("0");
      } else flag = true;
    }
  }
  printf("\n");
  return 0;
}