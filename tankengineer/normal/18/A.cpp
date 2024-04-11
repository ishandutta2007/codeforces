//18A
#include<cstdio>
#include<algorithm>

int x[4], y[4];
bool flag;

bool right() {
  int s = x[1] * (y[2] - y[3]) + x[2] * (y[3] - y[1]) + x[3] * (y[1] - y[2]);
  if (!s) return false;
  for (int i = 0; i < 3; i++) {
    int x1 = x[i + 1] - x[(i + 1) % 3 + 1], y1 = y[i + 1] - y[(i + 1) % 3 + 1];
    int x2 = x[i + 1] - x[(i + 2) % 3 + 1], y2 = y[i + 1] - y[(i + 2) % 3 + 1];
    if (x1 * x2 + y1 * y2 == 0) {
      return true;
    }
  }
  return false;
}

int main() {
  for (int i = 1; i <= 3; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
  if (right()) {
    puts("RIGHT");
    return 0;
  }
  flag = false;
  for (int i = 1; i <= 3; i++) {
    x[i]++;
    flag = flag || right();
    x[i] -= 2;
    flag = flag || right();
    x[i]++; y[i]++;
    flag = flag || right();
    y[i] -= 2;
    flag = flag || right();
    y[i]++; 
  }
  if (flag) {
    puts("ALMOST");
  } else {
    puts("NEITHER");
  }
  return 0;
}