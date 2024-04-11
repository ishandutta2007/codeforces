#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int sum[1<<20];
int mi[1<<20];
int a[100005];
void build_tree(int num,int l,int r)
{
    if (l==r-1)
    {
        sum[num]=1;
        mi[num]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build_tree(num*2+1,l,mid);
    build_tree(num*2+2,mid,r);
    mi[num]=min(mi[num*2+1],mi[num*2+2]);
    sum[num]=sum[num*2+1]+sum[num*2+2];
}
int query(int num,int l,int r,int l0,int r0)
{
    if ((l0<=l)&&(r<=r0))
    {
        return sum[num];
    }
    int mid=(l+r)/2;
    int ans=0;
    if (l0<mid) ans+=query(num*2+1,l,mid,l0,r0);
    if (mid<r0) ans+=query(num*2+2,mid,r,l0,r0);
    return ans;
}
void change(int num,int l,int r,int x)
{
    sum[num]--;
    if (l==r-1)
    {
        mi[num]=100005;
        return;
    }
    int mid=(l+r)/2;
    if (x<mid)
    {
        change(num*2+1,l,mid,x);
    }
    else
    {
        change(num*2+2,mid,r,x);
    }
    mi[num]=min(mi[num*2+1],mi[num*2+2]);
}
vector<int> b[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]].push_back(i);
    }
    build_tree(0,0,n);
    int now=-1;
    long long ans=0;
    for (i=1;i<=100000;i++)
    {
        for (;mi[0]==i;)
        {
            vector<int>::iterator t=lower_bound(b[i].begin(),b[i].end(),now+1);
            if (t==b[i].end())
            {
                if (now!=n-1) ans+=query(0,0,n,now+1,n);
                now=-1;
                t=b[i].begin();
            }
            ans+=query(0,0,n,now+1,(*t));
            ans++;
            now=(*t);
            change(0,0,n,(*t));
        }
    }
    cout<<ans<<endl;
    return 0;
}