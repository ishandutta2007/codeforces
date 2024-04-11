#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n,ans;
int a[100010],b[100010];

int main()
{int i,j;
 
 scanf("%d",&n);
 
 for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
 b[1]=1;
 b[n]=1;
 for(i=2;i<n;i++)
    b[i]=min(a[i],min(a[i-1]+1,a[i+1]+1));
 
 for(i=2;i<=n;i++)
    b[i]=min(b[i],b[i-1]+1);
 
 for(i=n-1;i>=1;i--)
    b[i]=min(b[i],b[i+1]+1);
 
 ans=0;
 for(i=1;i<=n;i++)
    ans=max(ans,b[i]);
 
 cout<<ans<<endl;
 
 return 0;
}