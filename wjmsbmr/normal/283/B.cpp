#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 200010
int a[N],n;ll f2[N],f3[N];int g2[N],g3[N];
void ff3(int x);
void ff2(int x)
{
    if(f2[x]!=-2)return;
    if(x==1){f2[x]=0;g2[x]=2;return;}
    f2[x]=-1;
    int x2=x+a[x];
    if(x2<=0||x2>n){f2[x]=a[x];return;}
    ff3(x2);
    if(f3[x2]==-1)return;
    g2[x]=g3[x2];
    f2[x]=a[x]+f3[x2];
}
void ff3(int x)
{
    if(f3[x]!=-2)return;
    if(x==1){f3[x]=0;g3[x]=3;return;}
    f3[x]=-1;
    int x2=x-a[x];
    if(x2<=0||x2>n){f3[x]=a[x];return;}
    ff2(x2);
    if(f2[x2]==-1)return;
    g3[x]=g2[x2];
    f3[x]=a[x]+f2[x2];
}
void ff3_2(int x);
void ff2_2(int x)
{
    if(f2[x]!=-2)return;
    f2[x]=-1;
    int x2=x+a[x];
    if(x2<=0||x2>n){f2[x]=a[x];return;}
    ff3_2(x2);
    if(g3[x2]==2)
    {
        return;
    }else
    if(g3[x2]==3)
    {
        ff3_2(1);
        if(f3[1]==-1)return;
        f2[x]=a[x]+f3[x2]+f3[1];
        return;
    }
    if(f3[x2]==-1)return;
    g2[x]=g3[x2];
    f2[x]=a[x]+f3[x2];
}
void ff3_2(int x)
{
    if(f3[x]!=-2)return;
    f3[x]=-1;
    int x2=x-a[x];
    if(x2<=0||x2>n){f3[x]=a[x];return;}
    ff2_2(x2);
    if(g2[x2]==2)
    {
        return;
    }else
    if(g2[x2]==3)
    {
        return;
    }
    if(f2[x2]==-1)return;
    g3[x]=g2[x2];
    f3[x]=a[x]+f2[x2];
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        f2[i]=f3[i]=-2;
    for(int i=1;i<=n;i++)
        ff2(i),ff3(i);
    for(int i=1;i<=n-1;i++)
    {
        f2[1]=f3[1]=-2;a[1]=i;
        ff2_2(1);
        cout<<f2[1]<<endl;
    }
    return 0;
}