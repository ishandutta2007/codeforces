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
#include<sstream>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int oper[200005];
int x[200005],xs[200005];
int y[200005],ys[200005];
set<int> s[200005];
int val[1<<19];
void build_tree(int num,int l,int r)
{
    val[num]=-1;
    if (l==r-1)
    {
        return;
    }
    int mid=(l+r)/2;
    build_tree(num*2+1,l,mid);
    build_tree(num*2+2,mid,r);
}
void change(int num,int l,int r,int k,int t)
{
    if (l==r-1)
    {
        val[num]=t;
        return;
    }
    int mid=(l+r)/2;
    if (k<mid)
    {
        change(num*2+1,l,mid,k,t);
    }
    else
    {
        change(num*2+2,mid,r,k,t);
    }
    val[num]=max(val[num*2+1],val[num*2+2]);
}
bool query(int num,int l,int r,int l0,int r0,int y)
{
    if ((l0<=l)&&(r<=r0))
    {
        return val[num]>y;
    }
    int mid=(l+r)/2;
    if ((l0<mid)&&(query(num*2+1,l,mid,l0,r0,y))) return true;
    if ((mid<r0)&&(query(num*2+2,mid,r,l0,r0,y))) return true;
    return false;
}
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
        static char a[15];
        scanf("%s",a);
        if (a[0]=='a')
        {
            oper[i]=0;
        }
        else if (a[0]=='r')
        {
            oper[i]=1;
        }
        else
        {
            oper[i]=2;
        }
        scanf("%d%d",&x[i],&y[i]);
        xs[i]=x[i];
        ys[i]=y[i];
    }
    sort(xs,xs+n);
    sort(ys,ys+n);
    int xn=unique(xs,xs+n)-xs;
    int yn=unique(ys,ys+n)-ys;
    for (i=0;i<n;i++)
    {
        x[i]=lower_bound(xs,xs+xn,x[i])-xs;
        y[i]=lower_bound(ys,ys+yn,y[i])-ys;
    }
    build_tree(0,0,xn);
    for (i=0;i<xn;i++)
    {
        s[i].insert(-1);
    }
    for (i=0;i<n;i++)
    {
        if (oper[i]==0)
        {
            s[x[i]].insert(y[i]);
            set<int>::iterator ii=s[x[i]].end();
            ii--;
            change(0,0,xn,x[i],(*ii));
        }
        else if (oper[i]==1)
        {
            s[x[i]].erase(y[i]);
            set<int>::iterator ii=s[x[i]].end();
            ii--;
            change(0,0,xn,x[i],(*ii));
        }
        else
        {
            int l=x[i]+2;
            int r=xn;
            for (;l<=r;)
            {
                int mid=(l+r)/2;
                if (query(0,0,xn,l-1,mid,y[i])) r=mid-1; else l=mid+1;
            }
            if (r>=xn)
            {
                printf("-1\n");
                continue;
            }
            printf("%d %d\n",xs[r],ys[(*s[r].lower_bound(y[i]+1))]);
        }
    }
    return 0;
}