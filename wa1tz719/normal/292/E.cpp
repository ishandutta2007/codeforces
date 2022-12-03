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
int a[200005];
int val[1<<18];
void push_down(int num,int l,int r)
{
    if (val[num]==-1)
    {
        return;
    }
    int mid=(l+r)/2;
    val[num*2+1]=val[num];
    val[num*2+2]=val[num]+mid-l;
    val[num]=-1;
}
void change(int num,int l,int r,int l0,int r0,int k)
{
    if ((l0<=l)&&(r<=r0))
    {
        val[num]=k+(l-l0);
        return;
    }
    push_down(num,l,r);
    int mid=(l+r)/2;
    if (l0<mid)
    {
        change(num*2+1,l,mid,l0,r0,k);
        if (mid<r0)
        {
            change(num*2+2,mid,r,l0,r0,k);
        }
    }
    else if (mid<r0)
    {
        change(num*2+2,mid,r,l0,r0,k);
    }
}
int query(int num,int l,int r,int t)
{
    if (l==r-1)
    {
        return val[num];
    }
    push_down(num,l,r);
    int mid=(l+r)/2;
    if (t<mid)
    {
        return query(num*2+1,l,mid,t);
    }
    else
    {
        return query(num*2+2,mid,r,t);
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for (i=0;i<n+n;i++)
    {
        scanf("%d",&a[i]);
    }
    memset(val,-1,sizeof(val));
    change(0,0,n,0,n,n);
    for (i=0;i<m;i++)
    {
        int oper;
        scanf("%d",&oper);
        if (oper==1)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x--;
            y--;
            change(0,0,n,y,y+z,x);
        }
        else
        {
            int x;
            scanf("%d",&x);
            x--;
            printf("%d\n",a[query(0,0,n,x)]);
        }
    }
    return 0;
}