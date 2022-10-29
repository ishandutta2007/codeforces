#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
bool a[10000000];
int b[1000000];
int m;
void check(int now)
{
  int k=0;
  int i=now;
  while (i!=0)
  {
    k=k*10+i%10;
    i/=10;      
  }     
  if (k<now&&!a[k])
  {
    b[m++]=now;    
  }
}
int main()
{
  int n;
  cin>>n;
  m=0;
  for (int i=2;i<=10000000;i++)
  if (!a[i])
  {
    check(i);
    int j = i;
    while (j+i<=10000000)
    {
      j+=i;
      a[j]=true;      
    }
  }
  for (int i=0;i!=m;i++)
  {
    int k=0;
    int j=b[i];
    while (j!=0)
    {
      k=k*10+j%10;
      j/=10;      
    }     
    b[i+m]=k;    
  }
  m*=2;
  sort(b,b+m);
  cout<<b[n-1];  
}