#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int a[510],f[510][510],next[510][510],pre[510][510];

void calc(int l,int r)
{int i,j,k,x,y,flag=1;
 
 for(i=l;i<=(l+r)/2;i++)
    if(a[i]!=a[l+r-i])
    {   flag=0;
        break;
    }
 if(flag)
 {  f[l][r]=1;
    return;
 }
 
 f[l][r]=n;
 for(i=l+1;i<=r;i++)
    f[l][r]=min(f[l][r],f[l][i-1]+f[i][r]);
 /*
 for(i=l;i<=r;i++)
    for(j=r;j>=i;j--)
        if(a[i]==a[j])
            f[l][r]=min(f[l][r],f[l][i-1]+f[j+1][r]+f[i+1][j-1]+(i+1<j?0:1));
 */
 for(i=1;i<=n;i++)
 {  x=next[l][i];
    y=pre[r][i];
    if(x>=l && x<=y && y<=r)
    {   //if(l==1 && r==3)
            //cout<<"## "<<x<<" "<<y<<endl;
        if(x+1>=y)
        {   f[l][r]=min(f[l][r],f[l][x-1]+f[y+1][r]+1);
            //cout<<f[l][r]<<endl;
        }
        else
        {   f[l][r]=min(f[l][r],f[l][x-1]+f[y+1][r]+f[x+1][y-1]);
            //cout<<"&&"<<endl;
        }
    }
 }
}
                
int main()
{int i,j,l;
 
 scanf("%d",&n);
 
 
 for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
 for(i=1;i<=n;i++)
 {  for(j=1;j<=n;j++)
        pre[i][j]=pre[i-1][j];
    pre[i][a[i]]=i;
 }
 for(i=n;i>=1;i--)
 {  for(j=1;j<=n;j++)
        next[i][j]=next[i+1][j];
    next[i][a[i]]=i;
 }
 for(i=1;i<=n;i++)
    f[i][i]=1;
 for(l=2;l<=n;l++)
    for(i=1;i<=n-l+1;i++)
    {   calc(i,i+l-1);
        //cout<<i<<" "<<i+l-1<<" "<<f[i][i+l-1]<<endl;
    }
 printf("%d\n",f[1][n]);        
 return 0;
}