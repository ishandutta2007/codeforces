//CF 8B
#include<stdio.h>
#include<cstring>

int x, y, top, tx[105], ty[105];
char rot[105];
bool flag = false;

inline int abs(int a) {return a < -a ? -a : a;}

int main() {
  gets(rot);
  x = 0; y = 0; top = 1; tx[top] = 0; ty[top] = 0;
  for (int i = 0; i < strlen(rot); i++) {
    switch (rot[i]) {
      case 'L' : {
        x--;
        break;
      }
      case 'R' : {
        x++;
        break;
      }
      case 'U' : {
        y++;
        break;
      }
      case 'D' : {
        y--;
        break;
      }
    }
    for (int j = 1 ; j <= top; j++) {
      if (tx[j] == x && ty[j] == y) {
        flag = true;
        break;
      } else if (j != top && abs(tx[j] - x) + abs(ty[j] - y) == 1) {
        flag = true;
        break;
      }
    }
    if (flag) break;
    top++;
    tx[top] = x;
    ty[top] = y;
  }
  if (flag) {
    puts("BUG");
  } else {
    puts("OK");
  }
  return 0;
}