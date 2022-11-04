#include<cstdio>
#include<iostream>
using namespace std;

int n;
int a[500100],b[500100];
long long sum,sum1,s1=0,ans=0,s[500100];

int main()
{int i,j;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {scanf("%d",&a[i]);
  s[i]=s[i-1];
  s[i]+=(long long)a[i];
 }

 if(s[n]%3!=0)
 {cout<<0<<endl;
  return 0;
 }

 sum=s[n];
 sum/=3;
 sum1=sum;
 sum1*=2;

 for(i=1;i<=n;i++)
   if(s[i]==sum) b[i]=1;

 for(i=1;i<=n;i++) 
 {if(i>1 && i<n && s[i]==sum1) ans+=(long long)s1;
  s1+=(long long)b[i];
 }
 
 cout<<ans<<endl;
 
 return 0;
}