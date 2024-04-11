#include<bits/stdc++.h>
#define N 100000010
#define ui unsigned int
#define ull unsigned long long
using namespace std;
int n;ui A,B,C,D,ans,num;
bitset<N>check;
ui cal(ui x){return A*x*x*x+B*x*x+C*x+D;}
int main()
{
  scanf("%d%u%u%u%u",&n,&A,&B,&C,&D);
  num=cal(2);
  for(int i=2;i<=n;i*=2)ans+=n/i*num;
  num=cal(3);
  for(int i=3;i<=n;i*=3)ans+=n/i*num;
  for(int i=4;i<=n;i++)
  {
    if(check[i/3]||i%2==0||i%3==0)continue;
    num=cal(i);
    for(ui j=i;j<=n;j+=i)
	  if(j%2&&j%3)check[j/3]=1;
    for(ull j=i;j<=n;j*=i)ans+=n/j*num;
  }
  printf("%u\n",ans);
  return 0;
}