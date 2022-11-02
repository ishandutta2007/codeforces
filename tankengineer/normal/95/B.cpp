//77B
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int f[100005], n, cnt4, cnt7;
char s[100005];
bool verse;

void printans(const int l) {
  for (int i = 1; i <= l / 2; i++) printf("4");
  for (int i = 1; i <= l / 2; i++) printf("7");
  puts("");
}

int main() {
  gets(s);
  n = strlen(s);
  if (n % 2 == 1) {
    printans(n + 1);
    return 0;
  }
  for (int i = 0; i < n; i++) s[i] = s[i] - '0';
  cnt4 = cnt7 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 4) cnt4++; else if (s[i] == 7) cnt7++;
  }
  if (cnt4 + cnt7 == n && cnt4 == cnt7) {
    for (int i = 0; i < n; i++) s[i] = s[i] + '0';
    printf("%s\n", s);
    return 0;
  }
  f[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] < 4) f[i] = 0;
    if (s[i] == 4) f[i] = min(1, f[i + 1]);
    if (s[i] > 4 && s[i] < 7) f[i] = 1;
    if (s[i] == 7) f[i] = f[i + 1] + 1;
    if (s[i] > 7) f[i] = 2000000000;
  }
  if (f[0] > n / 2) {
    printans(n + 2);
    return 0;
  }
  cnt4 = cnt7 = n / 2; verse = false;
  for (int i = 0; i < n; i++) {
    if (!cnt7) {
      s[i] = '4';
      cnt4--;
      continue;
    }
    if (!cnt4) {
      s[i] = '7';
      cnt7--;
      continue;
    }
    if (verse) {
      s[i] = '4';
      cnt4--;
      continue;
    }
    if (s[i] <= 4) {
      if (s[i] < 4) {
        s[i] = '4';
        verse = true;
        cnt4--;
        continue;
      } else {
        if (cnt7 >= f[i + 1]) {
          s[i] = '4';
          cnt4--;
          continue;
        }
      }
    }
    if (s[i] < 7) verse = true;
    s[i] = '7';
    cnt7--;
  }
  printf("%s", s);
  return 0;
}