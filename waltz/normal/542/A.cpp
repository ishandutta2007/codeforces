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
struct node
{
    int l;
    int r;
    int id;
    node (int ll=0,int rr=0)
    {
        l=ll;
        r=rr;
    }
    void read()
    {
        scanf("%d%d",&l,&r);
    }
    friend bool operator < (const node &a,const node &b)
    {
        if (a.l==b.l) return a.r>b.r;
        return a.l<b.l;
    }
    int cross(node b)
    {
        int ll=max(l,b.l);
        int rr=min(r,b.r);
        return rr-ll;
    }
};
node a[200005];
int n;
const int inf=1999999999;
int val[1<<19];
int max_val[1<<19];
int now_val;
int the_max_val;
void build_tree(int num,int l,int r)
{
    if (l==r-1)
    {
        val[num]=a[l].r-a[l].l;
        max_val[num]=a[l].id;
        return;
    }
    int mid=(l+r)/2;
    build_tree(num*2+1,l,mid);
    build_tree(num*2+2,mid,r);
    if (val[num*2+1]>val[num*2+2])
    {
        max_val[num]=max_val[num*2+1];
        val[num]=val[num*2+1];
    }
    else
    {
        max_val[num]=max_val[num*2+2];
        val[num]=val[num*2+2];
    }
}
void query(int num,int l,int r,int l0,int r0)
{
    if ((l0<=l)&&(r<=r0))
    {
        if (val[num]>the_max_val)
        {
            the_max_val=val[num];
            now_val=max_val[num];
        }
        return;
    }
    int mid=(l+r)/2;
    if (l0<mid) query(num*2+1,l,mid,l0,r0);
    if (mid<r0) query(num*2+2,mid,r,l0,r0);
}
int get_left(node x)
{
    int l=0,r=n-1;
    for (;l<=r;)
    {
        int mid=(l+r)/2;
        if (x.l>=a[mid].l) l=mid+1; else r=mid-1;
    }
    if (l!=0) l--;
    return l;
}
int get_right(node x)
{
    int l=0,r=n-1;
    for (;l<=r;)
    {
        int mid=(l+r)/2;
        if (x.r>a[mid].r) l=mid+1; else r=mid-1;
    }
    return l;
}
int ansi,ansj;
int check_max(node x)
{
    int l=get_left(x);
    int r=get_right(x);
    the_max_val=0;
    now_val=0;
    if (l+1<r) query(0,0,n,l+1,r);
    if (x.cross(a[l])>the_max_val)
    {
        the_max_val=x.cross(a[l]);
        now_val=a[l].id;
    }
    if (x.cross(a[r])>the_max_val)
    {
        the_max_val=x.cross(a[r]);
        now_val=a[r].id;
    }
    return the_max_val;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int m;
    scanf("%d%d",&n,&m);
    int i;
    for (i=0;i<n;i++)
    {
        a[i].read();
        a[i].id=i;
    }
    sort(a,a+n);
    int sum=0;
    for (i=0;i<n;i++)
    {
        if ((i!=0)&&(a[i].r<a[sum-1].r)) continue;
        a[sum++]=a[i];
    }
    n=sum;
    node b;
    long long max_ans=0;
    build_tree(0,0,n);
    for (i=0;i<m;i++)
    {
        b.read();
        int z;
        scanf("%d",&z);
        int val=check_max(b);
        if (max_ans<(long long)val*z)
        {
            max_ans=(long long)val*z;
            ansi=now_val;
            ansj=i;
        }
    }
    cout<<max_ans<<endl;
    if (max_ans>0)
    {
        cout<<ansi+1<<" "<<ansj+1<<endl;
    }
    return 0;
}