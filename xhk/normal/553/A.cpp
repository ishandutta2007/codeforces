#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int a[1010];
long long mod=1000000007,ans=0;
long long c[1010][1010];

int main()
{int i,j,s=0;
 
 c[0][0]=1;
 for(i=1;i<=1000;i++)
 {  c[i][0]=1;
    for(j=1;j<=1000;j++)
    {   c[i][j]=c[i-1][j-1]+c[i-1][j];
        c[i][j]%=mod;
    }
 }
 
 scanf("%d",&n);
 
 s=0;
 for(i=1;i<=n;i++)
 {  scanf("%d",&a[i]);
    s+=a[i];
 }
 
 ans=1;
 for(i=n;i>=1;i--)
 {  ans*=c[s-1][a[i]-1];
    ans%=mod;
    s-=a[i];
 }
 
 cout<<ans<<endl;
 
 return 0;
}