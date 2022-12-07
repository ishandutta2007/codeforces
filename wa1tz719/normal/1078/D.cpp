#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int vall[20][1<<20],valr[20][1<<20];
void change(int num,int l,int r,int x,int l0,int r0,int id)
{
    if (l==r-1)
    {
        vall[id][num]=l0;
        valr[id][num]=r0;
        return;
    }
    int mid=(l+r)/2;
    if (x<mid)
    {
        change(num*2+1,l,mid,x,l0,r0,id);
    }
    else
    {
        change(num*2+2,mid,r,x,l0,r0,id);
    }
    vall[id][num]=min(vall[id][num*2+1],vall[id][num*2+2]);
    valr[id][num]=max(valr[id][num*2+1],valr[id][num*2+2]);
}
int ansl,ansr;
void query_lr(int num,int l,int r,int l0,int r0,int id)
{
    if ((l0<=l)&&(r<=r0))
    {
        ansl=min(ansl,vall[id][num]);
        ansr=max(ansr,valr[id][num]);
        return ;
    }
    int mid=(l+r)/2;
    if (l0<mid)
    {
        query_lr(num*2+1,l,mid,l0,r0,id);
    }
    if (mid<r0)
    {
        query_lr(num*2+2,mid,r,l0,r0,id);
    }
}
int l[25][300005];
int r[25][300005];
int a[300005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=n;i<n+n;i++)
    {
        scanf("%d",&a[i]);
        l[0][i]=max(i-a[i],0);
        r[0][i]=min(i+a[i]+1,n*3);
        change(0,0,3*n,i,l[0][i],r[0][i],0);
    }
    for (i=0;i<n;i++)
    {
        a[i]=a[i+n];
        l[0][i]=max(i-a[i],0);
        r[0][i]=min(i+a[i]+1,n*3);
        change(0,0,3*n,i,l[0][i],r[0][i],0);
    }
    for (i=n+n;i<n+n+n;i++)
    {
        a[i]=a[i-n];
        l[0][i]=max(i-a[i],0);
        r[0][i]=min(i+a[i]+1,n*3);
        change(0,0,3*n,i,l[0][i],r[0][i],0);
    }
    for (i=1;i<=16;i++)
    {
        int j;
        for (j=0;j<n*3;j++)
        {
            ansl=19999999;
            ansr=-1;
            query_lr(0,0,3*n,l[i-1][j],r[i-1][j],i-1);
            int the_l=ansl;
            int the_r=ansr;
            l[i][j]=the_l;
            r[i][j]=the_r;
            change(0,0,3*n,j,the_l,the_r,i);
        }
    }
    if (n==1)
    {
        printf("0\n");
        return 0;
    }
    for (i=0;i<n;i++)
    {
        int j;
        int now_l=n+i,now_r=n+i+1;
        int ans=0;
        for (j=16;j>=0;j--)
        {
            ansl=19999999;
            ansr=-1;
            query_lr(0,0,3*n,now_l,now_r,j);
            int the_l=ansl;
            int the_r=ansr;
            if (the_r-the_l>=n)
            {
                continue;
            }
            ans+=(1<<j);
            now_l=the_l;
            now_r=the_r;
        }
        ans++;
        printf("%d ",ans);
    }
    return 0;
}