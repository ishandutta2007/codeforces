#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

struct unit
{int x,y;
};
struct unit a[100010];

int n,ans;
int f[100010];

bool cmp(struct unit A,struct unit B)
{return A.x<B.x;
}

int main()
{int i,j,k,l,r,mid;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++)
    scanf("%d%d",&a[i].x,&a[i].y);
 sort(a+1,a+n+1,cmp);   
 ans=n;
 for(i=1;i<=n;i++)
 {  l=1;
    r=i-1;
    k=0;
    while(l<=r)
    {   mid=(l+r)/2;
        if(a[i].x-a[mid].x>a[i].y)
        {   k=max(k,mid);
            l=mid+1;
        }   
        else
            r=mid-1;
    }   
    f[i]=f[k]+i-k-1;
    ans=min(ans,f[i]+n-i);
 }
 printf("%d\n",ans);
 return 0;
}