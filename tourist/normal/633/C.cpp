#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

#define end END

int a[N][27];
char str[N];
int end[N];
int pr[N], pw[N];
char word[N];
string name[N];

int main() {
  int len;
  scanf("%d", &len);
  scanf("%s", str);
  int cnt;
  scanf("%d", &cnt);
  int nn = 1;
  end[1] = -1;
  memset(a, 0, sizeof(a));
  for (int i = 0; i < cnt; i++) {
    scanf("%s", word);
    name[i] = "";
    for (int j = 0; word[j]; j++) {
      name[i] += word[j];
    }
    int t = 1;
    for (int j = 0; word[j]; j++) {
      if (word[j] >= 'A' && word[j] <= 'Z') {
        word[j] += 32;
      }
      int c = word[j] - 'a';
      if (a[t][c] == 0) {
        nn++;
        end[nn] = -1;
        a[t][c] = nn;
      }
      t = a[t][c];
    }
    end[t] = i;
  }
  for (int i = 0; i <= len; i++) {
    pr[i] = -1;
    pw[i] = -1;
  }
  pr[len] = 0;
  pw[len] = 0;
  for (int i = len; i > 0; i--) {
    if (pr[i] == -1) {
      continue;
    }
    int t = 1;
    for (int j = i - 1; j >= 0; j--) {
      int c = str[j] - 'a';
      if (a[t][c] == 0) {
        break;
      }
      t = a[t][c];
      if (end[t] != -1) {
        pr[j] = i;
        pw[j] = end[t];
      }
    }
  }
  int id = 0;
  while (id < len) {
    if (id > 0) {
      putchar(' ');
    }
    printf("%s", name[pw[id]].c_str());
    id = pr[id];
  }
  printf("\n");
  return 0;
}