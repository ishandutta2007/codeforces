#include<cstdio>
#include<iostream>
using namespace std;

int n,h,mod=1000000007,a[2010];
long long ans=1;

int main()
{int i,j,f;
 
 scanf("%d%d",&n,&h);
 
 for(i=1;i<=n;i++)
 {scanf("%d",&a[i]);
  a[i]=h-a[i];
 }
 
 
 f=1;
 
 if(a[1]>1 || a[n]>1) f=0;
 
 
 for(i=1;i<=n;i++)
 {if(a[i]-a[i-1]>1 || a[i-1]-a[i]>1)
  {f=0;
   break;
  }
  if(a[i]<0)
  {f=0;
   break;
  }
  if(a[i]!=a[i-1]+1)
  {ans*=(a[i]+1);
   ans%=mod;
  }
 }
 
 if(f==0)
   cout<<0<<endl;
 else
   cout<<ans<<endl;
 
 return 0;
}