//19A
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, t1, t2, l1, l2, p1, p2, p[55], in[55], sc[55], srt[55];
char ch, name[55][55], s1[55], s2[55];

bool cmp(int x, int y) {return (p[x] > p[y]) || (p[x] == p[y] && in[x] > in[y]) || (p[x] == p[y] && in[x] == in[y] && sc[x] > sc[y]);}
bool cmp2(int x, int y) {int t1 = strcmp(name[x], name[y]); return t1 <= 0;}

int main() {
  scanf("%d", &n);
  ch = getchar();
  for (int i = 1; i <= n; i++) {
    gets(name[i]);
    srt[i] = i;
  }
  for (int i = 1; i <= n * (n - 1) / 2; i++) {
    memset(s1, 0, sizeof(s1));
    memset(s2, 0, sizeof(s2));
    l1 = 0; l2 = 0;
    while ((ch = getchar()) != '-') {
      s1[l1++] = ch;
    }
    while ((ch = getchar()) != ' ') {
      s2[l2++] = ch;
    }
    for (int j = 1; j <= n; j++) {
      if (!strcmp(s1, name[j])) {
        p1 = j;
        break;
      }
    }
    for (int j = 1; j <= n; j++) {
      if (!strcmp(s2, name[j])) {
        p2 = j;
        break;
      }
    }
    scanf("%d:%d", &t1, &t2);
    ch = getchar();
    if (t1 == t2) {
      p[p1]++;
      p[p2]++;
    } else if (t1 > t2) {
      p[p1] += 3;
    } else {
      p[p2] += 3;
    }
    in[p1] += t1 - t2;
    in[p2] += t2 - t1;
    sc[p1] += t1;
    sc[p2] += t2;
  }
  
  sort(srt + 1, srt + n + 1, cmp);
  sort(srt + 1, srt + 1 + n / 2, cmp2);
  for (int i = 1; i <= n / 2; i++) {
    printf("%s\n", name[srt[i]]);
  }
  return 0;
}