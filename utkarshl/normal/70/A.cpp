#include"stdio.h"
#include"set"
#include"vector"
#include"map"
using namespace std;
long long ans(int n)
{
  long long res;
  if(n<=1)res=1;
  else res=(3*ans(n-1))%1000003;
  return res;
}
int main()
{
  int n;
  scanf("%d",&n);
  printf("%Ld",ans(n));
}