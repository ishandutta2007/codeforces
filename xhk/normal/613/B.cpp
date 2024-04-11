#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

struct unit
{int x,num;
};
struct unit a[100010];

int n,top,k1,k2;
int b[100010];
long long m,cf,cm,ans;
long long c[100010];

bool cmp(struct unit A,struct unit B)
{return A.x<B.x;
}

int check(long long k,long long s,int n1)
{int l,r,mid,p=0;
 l=1;
 r=n1;
 if(n1==0) return 1;
 while(l<=r)
 {  mid=(l+r)/2;
    if(a[mid].x<=k)
    {   p=max(p,mid);
        l=mid+1;
    }
    else
        r=mid-1;
 }
 if(p*k-c[p]<=s)
    return 1;
 else
    return 0;
}

int main()
{int i,j,x,l,r,mid;
 long long s,s1;
 
 //cin>>n>>top>>cf>>cm>>m;
 scanf("%d%d%I64d%I64d%I64d",&n,&top,&cf,&cm,&m);
 for(i=1;i<=n;i++)
 {  scanf("%d",&a[i].x);
    a[i].num=i;
 }
 sort(a+1,a+n+1,cmp);
 for(i=1;i<=n;i++)
    c[i]=c[i-1]+a[i].x;
 for(i=n;i>=1;i--)
    if(a[i].x==top) ans+=cf;
 ans+=a[1].x*cm;        
 k1=n+1;
 k2=0;  
 s=0;
 for(i=n+1;i>=1;i--)
 {  if(i<=n) s+=top-a[i].x;
    if(s>m) break;  
    s1=(n-i+1)*cf;
    l=0;
    r=top;
    x=0;
    while(l<=r)
    {   mid=(l+r)/2;
        if(check(mid,m-s,i-1))
        {   x=max(x,mid);
            l=mid+1;
        }
        else
            r=mid-1;
    }
    s1+=x*cm;
    if(s1>=ans)
    {   ans=s1;
        k1=i;
        k2=x;
    }
 }
 printf("%I64d\n",ans);
 for(j=n;j>=k1;j--)
 {  m-=top-a[j].x;
    a[j].x=top;
 }
 for(i=1;i<=n;i++)
    if(a[i].x<k2)
        a[i].x=k2;
 for(i=1;i<=n;i++)
    b[a[i].num]=a[i].x;
 for(i=1;i<=n;i++)
 {  printf("%d",b[i]);
    if(i!=n)
        printf(" ");
    else
        printf("\n");
 }
 return 0;
}