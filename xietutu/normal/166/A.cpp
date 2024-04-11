#include <cstdio>
#include <algorithm>
struct point
{
  int p, t;       
}a[100];
using namespace std;
bool sml(point a, point b) { return a.p > b.p || (a.p == b.p && a.t < b.t);}
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  m--;
  for (int i=0;i!=n;i++)
  {
    scanf("%d%d", &a[i].p, &a[i].t);    
  }
  sort(a, a+n, sml);
  int p=a[m].p;
  int t=a[m].t;
  int ans = 0;
  for (int i = 0; i != n; i++)if (a[i].p == p && a[i].t == t) ans++;
  printf("%d", ans);
}