//CF 3B
#include<cstdio>
#include<algorithm>

using namespace std;

int n, v, t1, t2, p1[100005], p2[100005], l1[100005], l2[100005], srt1[100005], srt2[100005], sum1[100005], sum2[100005], ans, anst, cnt1, cnt2;
bool use[100005], flag;

bool cmp1(int i, int j) {return p1[i] > p1[j];}
bool cmp2(int i, int j) {return p2[i] > p2[j];}

inline int min(int a, int b) {return a < b ? a : b;}

int main() {
  scanf("%d %d", &n, &v);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &t1, &t2);
    if (t1 == 1) {
      p1[++cnt1] = t2;
      l1[cnt1] = i;
      srt1[cnt1] = cnt1;
    } else {
      p2[++cnt2] = t2;
      l2[cnt2] = i;
      srt2[cnt2] = cnt2;
    }
  }
  
  sort(srt1 + 1, srt1 + 1 + cnt1, cmp1);
  sort(srt2 + 1, srt2 + 1 + cnt2, cmp2);
  
  sum1[0] = 0;
  for (int i = 1; i <= cnt1; i++) sum1[i] = sum1[i - 1] + p1[srt1[i]];
  sum2[0] = 0;
  for (int i = 1; i <= cnt2; i++) sum2[i] = sum2[i - 1] + p2[srt2[i]];
  
  ans = 0;
  for (int i = 0; i <= cnt2 && i * 2 <= v; i++) {
    t1 = sum2[i] + sum1[min(v - i * 2, cnt1)];
    if (t1 > ans) {
      ans = t1;
      anst = i;
    }
  }
  
  for (int i = 1; i <= anst; i++) {
    use[l2[srt2[i]]] = true;
  }
  for (int i = 1; i <= min(v - anst * 2, cnt1); i++) {
    use[l1[srt1[i]]] = true;
  }
  
  printf("%d\n", ans);
  flag = false;
  for (int i = 1; i <= n; i++) {
    if (use[i]) {
      if (flag) printf(" ");
      printf("%d", i);
      flag = true;
    }
  }
  
  return 0;
}