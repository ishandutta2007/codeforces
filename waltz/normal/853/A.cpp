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
bool val[300005];
pair<int,int> p[300005];
//int a[300005];
int ans[300005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&p[i].first);
        p[i].second=i+1;
    }
    sort(p,p+n);
    int now=0;
    long long sum=0;
    for (i=n+k;i>k;i--)
    {
        if (i<=n)
        {
            if (!val[i])
            {
                ans[i]=i;
                val[i]=true;
                continue;
            }
        }
        for (;val[p[now].second];)
        {
            now++;
            if (now>=n) break;
        }
        val[p[now].second]=true;
        ans[p[now].second]=i;
        sum+=((long long)p[now].first*(i-p[now].second));
        now++;
    }
    cout<<sum<<endl;
    for (i=1;i<=n;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}