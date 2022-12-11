#include <bits/stdc++.h>
using namespace std;
#define Maxn 2007
int T,n;
bool flag[Maxn];
map<pair<pair<int,int>,pair<int,int> >,int>mp;
int calc(int l,int r,int lx,int rx)
{
    if (mp.find(make_pair(make_pair(l,r),make_pair(lx,rx)))!=mp.end()) return mp[make_pair(make_pair(l,r),make_pair(lx,rx))];
    printf("? %d %d\n",r-l+1,rx-lx+1);
    for (int i=l;i<=r;i++)
        printf("%d ",i);
    printf("\n");
    for (int i=lx;i<=rx;i++)
        printf("%d ",i);
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d",&x);
    mp[make_pair(make_pair(l,r),make_pair(lx,rx))]=x;
    return x;
}
void print()
{
    printf("! ");
    int res=0;
    for (int i=1;i<=n;i++)
        if (flag[i]) ++res;
    printf("%d ",res);
    for (int i=1;i<=n;i++)
        if (flag[i]) printf("%d ",i);
    printf("\n");
    fflush(stdout);
}
void solve()
{
    mp.clear();
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        flag[i]=false;
    if (calc(1,1,2,n)!=0)
    {
        for (int i=2;i<=n;i++)
            if (calc(1,1,i,i)==0) flag[i]=true;
        print();
    }
    else
    {
        int x=2;
        while (calc(x,x,x+1,n)==0) ++x;
        int sum=1;
        int now=calc(x,x,x+1,n);
        for (int i=x+1;i<n;i++)
        {
            int tmp=calc(x,x,i,i);
            if (tmp==0) flag[i]=true;
            else if (tmp>0) ++sum;
            else --sum;
            now-=tmp;
        }
        if (now==0) flag[n]=true;
        else if(now>0) ++sum;
        else --sum;
        if (sum!=0)
        {
            for (int i=1;i<x;i++)
                flag[i]=true;
        }
        else
        {
            int lx=1,rx=x-1;
            while (rx-lx>1)
            {
                int mid=(lx+rx)/2;
                if (calc(mid,x-1,x,x)!=0) lx=mid; else rx=mid;
            }
            int res=0;
            if (calc(rx,x-1,x,x)!=0) res=rx; 
            else if (calc(lx,x-1,x,x)!=0) res=lx;
            for (int i=1;i<x;i++)
                if (i!=res) flag[i]=true;
        }
        print();
    }
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}