#include <cstdio>
using namespace std;
long long a[2][5];
const int f = 1000000007;
int n,now,last;
int main()
{
  scanf("%d", &n);
  a[1][1]=1;
  for (int i=0;i!=n;i++)
  {
    now=i%2;
    last=(i+1)%2;
    long long sum=0;
    for (int j=1;j<=4;j++) sum=(sum+a[last][j])%f;
    for (int j=1;j<=4;j++)
    {
      a[now][j] =(sum-a[last][j]+f)%f;    
    } 
  }
  int now=(n-1)%2;
  printf("%d",a[now][1]);
}