//CF 10B
#include<cstdio>
#include<algorithm>

using namespace std;

int n, k, t1, l[100], r[100], x, y, t2, t3, t4;

int inline abss(int a) {return a < -a ? -a : a;} 

int cal(const int &i) {
  if (l[i] == 0) {
    return abss(i - (k + 1) / 2) * t1 + (t1 - 1) / 2 * ((t1 + 1) / 2) + ((t1 - 1) % 2 ? (t1 + 1) / 2 : 0);
  } else {
    int b = l[i] <= r[i] ? l[i] : r[i]; 
    return abss(i - (k + 1) / 2) * t1 + (2 * b + t1 - 1) * t1 / 2;
  }
}

bool avb(const int &i) {
  if (l[i] == 0) return true;
  if (l[i] + t1 <= (k + 1) / 2 || r[i] + t1 <= (k + 1) / 2) return true;
  return false;
}

void reg(const int &i) {
  x = i; 
  if (l[x] == 0) {
    l[x] = (t1 - 1) / 2 + 1 + (t1 - 1) % 2;
    r[x] = (t1 - 1) / 2 + 1;
    y = (k + 1) / 2 - l[x] + 1;
  } else {
    if (l[x] <= r[x]) {
      l[x] += t1;
      y = (k + 1) / 2 - l[x] + 1;
    } else {
      y = (k + 1) / 2 + r[x];           
      r[x] += t1;
    }
  }
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t1);
    t2 = 0;
    t3 = 2000000000;
    for (int i = 1; i <= k; i++) {
      if (avb(i) && (t4 = cal(i)) < t3) {
        t3 = t4;
        t2 = i;
      }
    }
    if (t3 == 2000000000) {
      puts("-1");
    } else {
      reg(t2);
      printf("%d %d %d\n", x, y, y + t1 - 1);
    }
  }
  return 0;
}