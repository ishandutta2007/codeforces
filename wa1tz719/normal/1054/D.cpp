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
int a[200005];
int b[200005];
map<int,int> ma;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int k;
    scanf("%d",&k);
    int i;
    b[0]=0;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]^=a[i];
        b[i+1]=b[i];
    }
    long long ans=(long long)n*(n+1)/2;
    for (i=0;i<n;i++)
    {
        if (b[i]&(1<<(k-1)))
        {
            ma[b[i]^((1<<k)-1)]++;
        }
        else
        {
            ma[b[i]]++;
        }
    }
    map<int,int>::iterator ii;
    for (ii=ma.begin();ii!=ma.end();ii++)
    {
        if ((*ii).first==0)
        {
            int j;
            long long min_ans=(long long)n*(n-1);
            for (j=0;j<=(*ii).second;j++)
            {
                min_ans=min(min_ans,(long long)j*(j+1)/2+(long long)((*ii).second-j)*((*ii).second-j-1)/2);
            }
            ans-=min_ans;
        }
        else
        {
            int k=(*ii).second/2;
            ans-=(long long)k*(k-1)/2;
            ans-=(long long)((*ii).second-k)*((*ii).second-k-1)/2;
        }
    }
    cout<<ans<<endl;
    return 0;
}