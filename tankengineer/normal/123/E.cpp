//CodeForces 123E
#include<stdio.h>

double st[100005], ed[100005], ans, s[100005], e[100005], tmp, subs;
int l[100005], r[100005], ch[100005], asd[100005], fa[100005], head[100005], v[200010], next[2000010], n, top, s1, s2, cnt;
bool vis[100005];

void dp1(const int &i) {
  vis[i] = true;
  st[i] = s[i]; ed[i] = e[i]; asd[i] = 1; ch[i] = 0;
  int t = 0;
  for (int j = head[i]; j; j = next[j]) {
    if (!vis[v[j]])
    {
      ch[i]++;
      fa[v[j]] = i;
      dp1(v[j]);
      st[i] += st[v[j]];
      ed[i] += ed[v[j]];
      asd[i] += asd[v[j]];
    } else if (j == head[i]) {
      head[i] = next[j];
    } else {
      next[t] = next[j];
    }
    t = j;
  }
  ans += st[i] * (1 - ed[i]) + (1 - st[i]) * ed[i];
}

void dp2(const int &i) {
  double tmp3 = 0, cnt3 = 0;
  if (fa[i] != 0) {
    
    cnt = (n - asd[i]);
    tmp = 0;
    
    //Condition 1
    tmp += s[i] * (ed[i] - e[i]);
    
    //Condition 2
    for (int j = head[i]; j; j = next[j]) {
      tmp += st[v[j]] * (ed[i] - e[i] - ed[v[j]]);
    }
    
    ans += tmp * cnt;
    
  }

  for (int j = head[i]; j; j = next[j]) {
    tmp3 += (1 - ed[v[j]] - e[i]) * asd[v[j]];
  }
  
  for (int j = head[i]; j; j = next[j]) {
    subs += asd[v[j]] * s[i] * (1 - ed[v[j]] - e[i]);
    subs += (st[v[j]] * (tmp3 - ed[v[j]] * (asd[i] - 1) - (1 - ed[v[j]] - e[i] - ed[v[j]]) * (asd[v[j]])));
    if (fa[i] != 0) {subs += asd[v[j]] * ((1 - st[i]) * (ed[i] - e[i] - ed[v[j]]));}

    dp2(v[j]);
  }
}

int main() {
  scanf("%d", &n);
  top = 0;
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d %d", &s1, &s2);
    top++; next[top] = head[s1]; head[s1] = top; v[top] = s2;
    top++; next[top] = head[s2]; head[s2] = top; v[top] = s1;
  }
  s1 = s2 = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &l[i], &r[i]);
    s1 = s1 + l[i];
    s2 = s2 + r[i];
  }
  for (int i = 1; i <= n; i++) {
    s[i] = (double) l[i] / s1;
    e[i] = (double) r[i] / s2;
  }
  
  subs = 0;
  ans = 0;
  dp1(1);
  dp2(1);
  
  printf("%.12lf\n", subs+ans);
  
  return 0;
}