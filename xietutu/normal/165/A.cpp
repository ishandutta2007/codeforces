#include <cstdio>
using namespace std;
int a[1000][2];
int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i][0], &a[i][1]);
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    bool l = false;
    bool r = false;
    bool u = false;
    bool d = false;
    for (int j = 1; j <= n; j++) 
    if (i != j)
    {
      if (a[i][0] == a[j][0])
      {
        if (a[i][1] > a[j][1]) d = true;
        if (a[i][1] < a[j][1]) u = true;            
      }      
      if (a[i][1] == a[j][1])
      {
        if (a[i][0] > a[j][0]) l = true;
        if (a[i][0] < a[j][0]) r = true;            
      }
    }    
    if (l && r && u && d) ans++;
  }
  printf("%d", ans);
}