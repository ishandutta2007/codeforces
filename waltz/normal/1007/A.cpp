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
    }
    sort(a,a+n);
    int cnt=0;
    a[n]=-1;
    int ans=0;
    for (i=0;i<n;)
    {
        int j;
        for (j=i;a[j]==a[i];j++)
        {
            if (cnt>0)
            {
                cnt--;
                ans++;
            }
        }
        cnt+=(j-i);
        i=j;
    }
    printf("%d\n",ans);
    return 0;
}