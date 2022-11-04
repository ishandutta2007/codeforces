#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int n,ans;
int a[500010],b[500010],used[500010];

int main()
{int i,j,s,k;
 
 scanf("%d",&n);
 
 for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
 
 
 used[1]=1;
 used[n]=1;
 s=0;
 for(i=2;i<n;i++)
 {  if(a[i]!=a[i-1] && a[i]!=a[i+1])
        s++;
    else
    {   s=0;
        used[i]=1;
    }
    ans=max(ans,(s+1)/2);
 }
 
 a[0]=a[1];
 a[n+1]=a[n];
 b[1]=a[1];
 b[n]=a[n];

 for(i=1;i<=n;i++)
    if(used[i])
        b[i]=a[i];
 
 for(i=1;i<=n;i++)
 {  if(a[i]==a[i-1] && a[i]!=a[i+1])
    {   k=1;
        while(used[i+k]==0) k++;
        for(j=1;j<=k/2;j++)
            if(i+j<=n)
                b[i+j]=a[i];
            else
                break;
    }
    if(a[i]==a[i+1] && a[i]!=a[i-1])
    {   k=1;
        while(used[i-k]==0) k++;
        for(j=1;j<=k/2;j++)
            if(i-j>0 && used[i-j]==0)
                b[i-j]=a[i];
            else
                break;
    }
 }
 
 printf("%d\n",ans);
 
 for(i=1;i<=n;i++)
 {  printf("%d",b[i]);
    if(i!=n)
        printf(" ");
    else
        printf("\n");
 }
 
 return 0;
}