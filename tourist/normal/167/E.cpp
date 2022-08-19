#include <stdio.h>

const int N = 610;
const int M = 200010;

int n,m,md,i,r,e,j,st,tmp,xx,step,co,ans,z;
int din[N],dout[N],last[N],x[N],pz[N],id[N],f[N];
int ss[M],ff[M],pred[M];
int a[N][N];

int main() {
  scanf("%d %d %d",&n,&m,&md);
  for (i=0;i<n;i++) din[i] = dout[i] = last[i] = 0;
  for (i=1;i<=m;i++) {
    scanf("%d %d",&ss[i],&ff[i]);
    ss[i]--; ff[i]--;
    pred[i] = last[ss[i]];
    last[ss[i]] = i;
    din[ff[i]]++;
    dout[ss[i]]++;
  }
  r = 0;
  for (i=0;i<n;i++)
    if (dout[i] == 0) id[i] = r++;
    else id[i] = -1;
  e = 0;
  for (i=0;i<n;i++)
    if (din[i] == 0) {
      e++;
      x[e] = i;
    }
  i = 1;
  while (i <= e) {
    j = last[x[i]];
    while (j > 0) {
      din[ff[j]]--;
      if (din[ff[j]] == 0) {
        e++;
        x[e] = ff[j];
      }
      j = pred[j];
    }
    i++;
  }
  for (i=0;i<n;i++) x[i] = x[i+1];
  for (i=0;i<n;i++) pz[x[i]] = i;
  for (i=1;i<=m;i++) din[ff[i]]++;
  for (st=0;st<r;st++) {
    for (i=0;i<n;i++) f[i] = 0;
    f[st] = 1;
    for (i=0;i<n;i++) {
      j = last[x[i]];
      while (j > 0) {
        f[pz[ff[j]]] += f[i];
        if (f[pz[ff[j]]] >= md) f[pz[ff[j]]] -= md;
        j = pred[j];
      }
    }
    for (i=0;i<n;i++)
      if (id[i] != -1) a[st][id[i]] = f[pz[i]];
  }
  z = 1;
  for (e=0;e<r;e++) {
    for (i=e;i<r;i++)
      if (a[i][e] != 0) {
        if (i == e) break;
        z = -z;
        for (j=e;j<r;j++) { tmp = a[i][j]; a[i][j] = a[e][j]; a[e][j] = tmp; }
        break;
      }
    if (a[e][e] == 0) {
      puts("0");
      return 0;
    }
    xx = 1; step = 1 << 30;
    while (step > 0) {
      xx = (long long)xx*xx % md;
      if (step & (md-2)) xx = (long long)xx*a[e][e] % md;
      step >>= 1;
    }
    for (i=e+1;i<r;i++) {
      co = md-((long long)a[i][e]*xx % md);
      if (co == md) co = 0;
      for (j=e;j<r;j++) a[i][j] = (a[i][j]+(long long)co*a[e][j]) % md;
    }
  }
  ans = 1;
  for (i=0;i<r;i++) ans = (long long)ans*a[i][i] % md;
  if (z == -1) ans = (md-ans) % md;
  printf("%d\n",ans);
  return 0;
}