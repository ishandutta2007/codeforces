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
int min_val[100005],max_val[100005];
bool is_ok[100005];
void read_val(int x)
{
    int k;
    scanf("%d",&k);
    int i;
    int y;
    int last_num;
    for (i=0;i<k;i++)
    {
        scanf("%d",&y);
        if (i==0)
        {
            max_val[x]=y;
        }
        else if (y>last_num)
        {
            is_ok[x]=true;
        }
        last_num=y;
    }
    min_val[x]=y;
}
long long ans=0;
struct range
{
    int l;
    int r;
    friend bool operator < (const range &a,const range &b)
    {
        if (a.l==b.l)
        {
            return a.r<b.r;
        }
        return a.l<b.l;
    }
    range(int xx=0,int yy=0)
    {
        l=xx;
        r=yy;
    }
};
range a[100005];
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
        read_val(i);
    }
    int cnt=0;
    for (i=0;i<n;i++)
    {
        //printf("%d %d %d\n",min_val[i],max_val[i],is_ok[i]);
        if (is_ok[i])
        {
            ans+=n;
        }
        else
        {
            ans+=n;
            a[cnt++]=range(min_val[i],max_val[i]);
        }
    }
    //cout<<ans<<" "<<cnt<<endl;
    sort(a,a+cnt);
    for (i=0;i<cnt;i++)
    {
        int k=lower_bound(a,a+cnt,range(a[i].r,-1))-a;
        ans-=(cnt-k);
    }
    cout<<ans<<endl;
    return 0;
}