//CodeForces 164C
#include<stdio.h>
#include<cstring>
#include<algorithm>

using namespace std;

int n, k, times[2005], event[2005], srt[2005], s[1005], t[1005], p[1005], cn[1005], head[2005], top, v[16005], next[16005], rev[16005], l[16005], c[16005], 
  qhead, qtail, q[2005], ans, cnt, cnt1, fa[2005], dis[2005], t1, t2, t3;
bool inq[2005];

bool cmp(int x, int y) {return times[x] < times[y];}

bool getpath() {
  memset(fa, 0, sizeof(fa));
  for (int i = 1; i <= cnt + 1; i++) {
    dis[i] = -100000000;
  }
  dis[cnt + 1] = 0;
  
  qhead = 0; qtail = 1; q[1] = cnt + 1;
  
  while (qhead != qtail) {        
    qhead = (qhead + 1) % (cnt + 1);
    t1 = q[qhead];
    
//    printf("Viewing %d\n", t1);    
    
    inq[t1] = false;
    for (int j = head[t1]; j; j = next[j]) {
      if (c[rev[j]] > 0 && dis[v[j]] < dis[t1] + l[rev[j]]) {
        dis[v[j]] = dis[t1] + l[rev[j]];
        fa[v[j]] = rev[j];
        if (!inq[v[j]]) {
          inq[v[j]] = true;
          qtail = (qtail + 1) % (cnt + 1); q[qtail] = v[j];
        }
      }
    }
  }
  
  return fa[1];
}

void flow() {
  while (getpath()) {
    
//    puts("I got flowed!");
        
    t1 = fa[1];
    while (t1 != 0) {
      c[t1]--; c[rev[t1]]++;
      ans = ans + l[t1];
      t1 = fa[v[t1]];
    }
  }
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &s[i], &t[i], &p[i]);
    t[i] = t[i] + s[i];
    cnt1++; times[cnt1] = s[i]; event[cnt1] = i; srt[cnt1] = cnt1;
    cnt1++; times[cnt1] = t[i]; event[cnt1] = -i; srt[cnt1] = cnt1;
  }
  
  sort(srt + 1, srt + 1 + cnt1, cmp);
  
  cnt = 1;
  for (int i = 1; i <= cnt1; i++) {
    if (times[srt[i]] != times[srt[i - 1]]) cnt++;
    if (event[srt[i]] > 0) {
      s[event[srt[i]]] = cnt;
    } else {
      t[-event[srt[i]]] = cnt;
    }
  }
  
  top = 0;
  for (int i = 1; i <= n; i++) {
    top++; v[top] = t[i]; next[top] = head[s[i]]; head[s[i]] = top; c[top] = 1; l[top] = p[i]; rev[top] = top + 1; cn[i] = top;
    top++; v[top] = s[i]; next[top] = head[t[i]]; head[t[i]] = top; c[top] = 0; l[top] = -p[i]; rev[top] = top - 1;
  }
  for (int i = 1; i <= cnt; i++) {
    top++; v[top] = i + 1; next[top] = head[i]; head[i] = top; c[top] = k; l[top] = 0; rev[top] = top + 1;
    top++; v[top] = i; next[top] = head[i + 1]; head[i + 1] = top; c[top] = 0; l[top] = 0; rev[top] = top - 1;
  }
  
  ans = 0;
  
  flow();
  
//  printf("%d\n", ans);
  
  for (int i = 1; i < n; i++) {
    printf("%d ", c[rev[cn[i]]]);
  }
  printf("%d\n", c[rev[cn[n]]]);
  
  return 0;
}