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
long long val[1<<19];
long long tag[1<<19];
int a[1<<18];
const long long inf=999999999999999999ll;
void build_tree(int num,int l,int r)
{
    if (l==r-1)
    {
        val[num]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build_tree(num*2+1,l,mid);
    build_tree(num*2+2,mid,r);
    val[num]=min(val[num*2+1],val[num*2+2]);
}
void change(int num,int l,int r,int l0,int r0,int k)
{
    if ((l0<=l)&&(r<=r0))
    {
        tag[num]+=k;
        return;
    }
    int mid=(l+r)/2;
    if (l0<mid) change(num*2+1,l,mid,l0,r0,k);
    if (mid<r0) change(num*2+2,mid,r,l0,r0,k);
    val[num]=min(val[num*2+1]+tag[num*2+1],val[num*2+2]+tag[num*2+2]);
}
long long query(int num,int l,int r,int l0,int r0)
{
    if ((l0<=l)&&(r<=r0))
    {
        return val[num]+tag[num];
    }
    int mid=(l+r)/2;
    long long ans=inf;
    if (l0<mid) ans=min(ans,query(num*2+1,l,mid,l0,r0));
    if (mid<r0) ans=min(ans,query(num*2+2,mid,r,l0,r0));
    return ans+tag[num];
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    build_tree(0,0,n);
    int q;
    scanf("%d",&q);
    for (i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        y++;
        char t=getchar();
        if (t==' ')
        {
            int z;
            scanf("%d",&z);
            if (x>=y)
            {
                change(0,0,n,x,n,z);
                change(0,0,n,0,y,z);
            }
            else
            {
                change(0,0,n,x,y,z);
            }
        }
        else
        {
            if (x>=y)
            {
                cout<<min(query(0,0,n,x,n),query(0,0,n,0,y))<<'\n';
            }
            else
            {
                cout<<query(0,0,n,x,y)<<'\n';
            }
        }
    }
    return 0;
}