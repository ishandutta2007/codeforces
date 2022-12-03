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
int a[100005];
int b[100005];
bool vis[100005];
map<int,int> ma;
vector<vector<int> > ans;
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
        b[i]=a[i];
    }
    sort(b,b+n);
    for (i=0;i<n;i++)
    {
        ma[b[i]]=i;
    }
    for (i=0;i<n;i++)
    {
        a[i]=ma[a[i]];
    }
    for (i=0;i<n;i++)
    {
        vector<int> t;
        if (vis[i]) continue;
        t.clear();
        int now=i;
        for (;;)
        {
            if (vis[now]) break;
            vis[now]=true;
            t.push_back(now+1);
            now=a[now];
        }
        ans.push_back(t);
    }
    printf("%d\n",ans.size());
    for (i=0;i<ans.size();i++)
    {
        printf("%d ",ans[i].size());
        int j;
        for (j=0;j<ans[i].size();j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}