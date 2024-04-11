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
int a[25],b[25],c[25],d[25],e[25];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    if (n>15)
    {
        puts("0");
        return 0;
    }
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d%d%d%d%d",&a[i],&b[i],&c[i],&d[i],&e[i]);
    }
    vector<int> ans;
    for (i=0;i<n;i++)
    {
        int j;
        int k;
        for (j=0;j<n;j++)
        {
            for (k=0;k<n;k++)
            {
                if ((i==j)||(j==k)||(k==i)) continue;
                int sum=0;
                sum=(a[j]-a[i])*(a[k]-a[i])+(b[j]-b[i])*(b[k]-b[i])+(c[j]-c[i])*(c[k]-c[i])+(d[j]-d[i])*(d[k]-d[i])+(e[j]-e[i])*(e[k]-e[i]);
                if (sum>0) break;
            }
            if (k!=n) break;
        }
        if (j==n) ans.push_back(i);
    }
    printf("%d\n",ans.size());
    for (i=0;i<ans.size();i++)
    {
        printf("%d\n",ans[i]+1);
    }
    return 0;
}