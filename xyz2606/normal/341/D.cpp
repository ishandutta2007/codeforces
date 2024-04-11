#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int x, y, x1, y1, n, m, oper, x2, y2;
long long dlt, delta, ans;
char ch1;
struct sgt
{
    long long a[1002][1002];
    sgt()
    {
        memset(a, 0, sizeof(a));
    }
    void pls()
    {
        for(int i = x + 1; i <= n + 1; i += i & -i)
            for(int j = y + 1; j <= n + 1; j += j & -j)
                a[i][j] ^= delta;
    }
    long long gets()
    {
        long long rtn = 0;
        for(int i = x + 1; i != 0; i -= i & -i)
            for(int j = y + 1; j != 0; j -= j & -j)
                rtn ^= a[i][j];
        return rtn;
    }
};
//sgt::recSgt* roota, rootb, rootc, rootd;

sgt a, b, c, d;
  
int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= m; i++)
  {
    scanf("%d", &oper);
    //printf("%c\n", ch1);
    if(oper == 2)
    {
      scanf("%d%d%d%d%I64d", &x1, &y1, &x2, &y2, &dlt);
      
      x = x1-1;
      y = y1-1;
      delta = ((x*y) & 1) * dlt;
      a.pls();

      delta = +dlt;
      b.pls();
      delta = (x & 1) * dlt;
      c.pls();
      delta = (y & 1) * dlt;
      d.pls();
    
     
      x = x1-1;
      y = y2;
      delta = ((x * y) & 1) * dlt;
      a.pls();
      delta = dlt;
      b.pls();
      delta = (x & 1) *dlt;
      c.pls();
      delta = (y & 1) * dlt;
      d.pls();
      
      x = x2;
      y = y1-1;
      delta = ((x*y) & 1) * dlt;
      a.pls();
      delta = dlt;
      b.pls();
      delta = (x & 1) *dlt;
      c.pls();
      delta = (y & 1) *dlt;
      d.pls();
      
      x = x2;
      y = y2;
      delta = ((x*y) & 1) * dlt;
      a.pls();
      delta = dlt;
      b.pls();
      delta = (x & 1) *dlt;
      c.pls();
      delta = (y & 1) *dlt;
      d.pls();

    }else
    {
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      //printf("%d %d %d %d\n", x1, y1, x2, y2);
      ans = 0;
      x = x1-1;
      y = y1-1;
      ans ^= a.gets();
      ans ^= b.gets()*((x*y) & 1);
      ans ^= c.gets()*(y & 1);
      ans ^= d.gets()*(x & 1);

      x = x1-1;
      y = y2;
      ans ^= a.gets();
      ans ^= b.gets()*((x*y) & 1);
      ans ^= c.gets()*(y & 1);
      ans ^= d.gets()*(x & 1);
      
      x = x2;
      y = y1-1;
      ans ^= a.gets();
      ans ^= b.gets()*((x*y) & 1);
      ans ^= c.gets()*(y & 1);
      ans ^= d.gets()*(x & 1);

      x = x2;
      y = y2;
      ans ^= a.gets();
      ans ^= b.gets()*((x*y) & 1);
      ans ^= c.gets()*(y & 1);
      ans ^= d.gets()*(x & 1);
      
      printf("%I64d\n", ans);
    }
    
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}