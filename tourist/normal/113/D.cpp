#include <iostream>
#include <iomanip>
#include <mem.h>

using namespace std;

int cnt,it,k,n,m,s1,s2,ss,ff,i,j,ii,jj,ns,ni,nj,tmp;
double s,w,pp;
int num[24][24],g[24][24];
double pr[24][24],a[256][256],b[256][256];

int main() {
//  freopen("in","r",stdin);
//  freopen("out","w",stdout);
  cin >> n >> m >> s1 >> s2;
  memset(g,0,sizeof(g));
  for (i=0;i<m;i++) {
    cin >> ss >> ff;
    ss--; ff--;
    g[ss][ff] = g[ff][ss] = 1;
  }
  memset(pr,0,sizeof(pr));
  for (i=0;i<n;i++) {
    cin >> pr[i][i];
    cnt = 0;
    for (j=0;j<n;j++) cnt += g[i][j];
    if (!cnt) continue;
    pp = (1.0-pr[i][i])/cnt;
    for (j=0;j<n;j++)
      if (g[i][j]) pr[i][j] = pp;
  }
  memset(a,0,sizeof(a));
  ns = 0;
  for (i=0;i<n;i++)
    for (j=i;j<n;j++) {
      num[i][j] = ns;
      if (i == j) a[ns][ns] = 1;
      ns++;
    }
  for (i=0;i<n-1;i++)
    for (j=i+1;j<n;j++)
      for (ii=0;ii<n;ii++)
        for (jj=0;jj<n;jj++) {
          w = pr[i][ii]*pr[j][jj];
          ni = ii; nj = jj;
          if (ni > nj) { tmp = ni; ni = nj; nj = tmp; }
          a[num[i][j]][num[ni][nj]] += w;
        }
  for (it=0;it<50;it++) {
    for (i=0;i<ns;i++)
      for (j=0;j<ns;j++) {
        b[i][j] = 0;
        for (k=0;k<ns;k++) b[i][j] += a[i][k]*a[k][j];
      }
    for (i=0;i<ns;i++) {
      s = 0;
      for (j=0;j<ns;j++) {
        a[i][j] = b[i][j];
        if (a[i][j] < 1e-20) a[i][j] = 0;
        s += a[i][j];
      }
      for (j=0;j<ns;j++) a[i][j] /= s;
    }
  }
  if (s1 > s2) { tmp = s1; s1 = s2; s2 = tmp; }
  s1--; s2--;
  cout << fixed << setprecision(17);
  for (i=0;i<n;i++) {
    cout << a[num[s1][s2]][num[i][i]];
    if (i < n-1) cout << " ";
  }
  cout << endl;
  return 0;
}