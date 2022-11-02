//77A
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, l[105];
char t, sw[105], s[105], name[105][105], t1, t2;

bool strcmps(const int i, const int j) {
  for (int k = 0; k < strlen(name[j]); k++) {
    if (s[i + k] != name[j][k]) return false;
  }
  return true;
}

int main() {
  scanf("%d", &n);
  getchar();
  for (int i = 1; i <= n; i++) {
    gets(name[i]);
    name[i][strlen(name[i])] = 0;
    for (int j = 0; j < strlen(name[i]); j++) {
      if (name[i][j] >= 'A' && name[i][j] <= 'Z') name[i][j] = 'a' + name[i][j] - 'A';
    }
  }
  gets(s);
  s[strlen(s)] = 0;
  for (int i = 0; i < strlen(s); i++) {sw[i] = s[i]; if (s[i] >= 'A' && s[i] <= 'Z') s[i] = 'a' + s[i] - 'A';}
  for (int i = 0; i < strlen(s); i++) {
    l[i] = i;
    for (int j = 1; j <= n; j++) {
      if (strcmps(i, j)) l[i] = max(l[i], (int) (i + strlen(name[j])));
    }
  }
  scanf("%c", &t);
  if (t >= 'A' && t <= 'Z') {t1 = t; t2 = 'a' + t - 'A';} else {t1 = 'A' + t - 'a'; t2 = t;}
  for (int i = 0 ; i < strlen(s); i++) {
    for (int j = i; j < l[i]; j++) {
      if (s[j] == t2) {
        if (sw[j] >= 'A' && sw[j] <= 'Z') sw[j] = (t1 == 'A' ? 'B' : 'A'); else sw[j] = (t1 == 'A' ? 'b' : 'a');
        continue;
      }
      if (sw[j] >= 'A' && sw[j] <= 'Z') sw[j] = t1; else sw[j] = t2;
    }
  }
  puts(sw);
  return 0;
}