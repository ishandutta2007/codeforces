//18D
#include<cstdio>
#include<algorithm>
using namespace std;

struct gjd {
  int l, q[605];
} ans, ex2[2001];

int n, t1, near[2005], top, fow[5005], bck[5005], p[5005], srt[5005], jw;
char s[8];
bool flag;

bool cmp(int i, int j) {return p[i] > p[j];}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s %d", &s, &t1);
    if (s[0] == 'w') {
      near[t1] = i;
    } else {
      if (near[t1]) {
        top++;
        fow[top] = near[t1];
        bck[top] = i;
        p[top] = t1;
        srt[top] = top;
      }
    }
  }
  
  ex2[0].l = 1; ex2[0].q[1] = 1;
  for (int i = 1; i <= 2000; i++) {
    jw = 0;
    for (int j = 1; j <= ex2[i - 1].l; j++) {
      ex2[i].q[j] = ex2[i - 1].q[j] * 2 + jw;
      jw = ex2[i].q[j] / 10;
      ex2[i].q[j] %= 10;
    }
    ex2[i].l = ex2[i - 1].l;
    if (jw) {
      ex2[i].q[++ex2[i].l] = jw;
    }
  }
  
  sort(srt + 1, srt + top + 1, cmp);
  
  ans.l = 1;
  for (int i = 1; i <= top; i++) {
    flag = false;
    for (int j = 1; j < i; j++) {
      if (p[srt[j]] == -1 && min(bck[srt[j]], bck[srt[i]]) > max(fow[srt[j]], fow[srt[i]])) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      jw = 0;
      ans.l = max(ans.l, ex2[p[srt[i]]].l);
      for (int j = 1; j <= ans.l; j++) {
        ans.q[j] += ex2[p[srt[i]]].q[j] + jw;
        jw = ans.q[j] / 10;
        ans.q[j] %= 10;
      }
      if (jw) {
        ans.q[++ans.l] = jw;
      }
      p[srt[i]] = -1;
    }
  }
  
  for (int i = ans.l; i >= 1; i--) {
    printf("%d", ans.q[i]);
  }
  printf("\n");
  
  return 0;
}