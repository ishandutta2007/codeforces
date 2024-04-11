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
int ans[200005];
struct node
{
    int x;
    int y;
    friend bool operator < (const node &a,const node &b)
    {
        if (a.x<b.x) return true;
        if (a.x>b.x) return false;
        return false;
    }
    void read()
    {
        scanf("%d%d",&x,&y);
    }
};
node c[200005];
int a[200005],w[200005];
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
        c[i].read();
    }
    sort(c,c+n);
    for (i=0;i<n;i++)
    {
        a[i]=c[i].x;
        w[i]=c[i].y;
    }
    int maxans=0;
    for (i=0;i<n;i++)
    {
        if (maxans==0)
        {
            ans[0]=a[i]+w[i];
            maxans++;
        }
        else
        {
            int t=upper_bound(ans,ans+maxans,a[i]-w[i])-ans;
            ans[t]=min(ans[t],a[i]+w[i]);
            if (t>=maxans)
            {
                ans[t]=a[i]+w[i];
                maxans++;
            }
        }
    }
    printf("%d\n",maxans);
    return 0;
}