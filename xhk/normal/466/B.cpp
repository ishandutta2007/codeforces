#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

long long n,mi,mj;
long long a,b,ans=-1;

int main()
{long long i,j,f=0;
 
 cin>>n>>a>>b;
 
 n*=(long long)6;
 
 if(n<=(long long)(a*b))
 {cout<<(long long)(a*b)<<endl;
  cout<<a<<" "<<b<<endl;
  return 0;
 }
 
 for(i=a;i<=(sqrt(n))*2;i++)
 {j=n/i;
  if(i*j<n) j++;
  if((i>=a && j>=b) && (i*j<ans || ans==-1))
  {ans=i;
   ans*=(long long)j;
   mi=i;
   mj=j;
  }
 }
 
 for(i=b;i<=(sqrt(n)*2);i++)
 {j=n/i;
  if(i*j<n) j++;
  if((i>=b && j>=a) && (i*j<ans || ans==-1))
  {ans=i;
   ans*=(long long)j;
   mj=i;
   mi=j;
  }
 }
 
 cout<<ans<<endl<<mi<<" "<<mj<<endl;
 
 return 0;
}