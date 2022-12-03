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
int a[1005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n+n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=0;
    for (i=0;i<n+n;i+=2)
    {
        int j;
        for (j=i+1;j<n+n;j++)
        {
            if (a[i]==a[j])
            {
                int k;
                for (k=j;k>i+1;k--)
                {
                    swap(a[k],a[k-1]);
                    ans++;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}