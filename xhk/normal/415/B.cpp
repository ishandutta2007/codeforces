#include<cstdio>
#include<iostream>
using namespace std;

int n,a,b;
long long c[100010];

int main()
{int i,j;
 long long s;
 
 scanf("%d%d%d",&n,&a,&b);
 
 for(i=1;i<=n;i++) scanf("%d",&c[i]);
 
 for(i=1;i<=n;i++)
 {s=c[i];
  s*=(long long)a;
  s/=(long long)b;
  s*=(long long)b;
  if(s%a!=0)
  {s/=(long long)a;
   s++;
  }
  else
   s/=(long long)a;
  c[i]-=(long long)s;
 }
 
 for(i=1;i<=n;i++) printf("%d ",c[i]);
 
 return 0;
}