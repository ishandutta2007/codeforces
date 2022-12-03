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
int ma[5005];
int ans[5005];
int a[5005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i,j;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        a[i]--;
    }
    int max_val=0;
    for (i=0;i<n;i++)
    {
        for (j=i;j<n;j++)
        {
            ma[a[j]]++;
            if (ma[a[j]]>ma[max_val])
            {
                max_val=a[j];
            }
            else if (ma[a[j]]==ma[max_val])
            {
                max_val=min(max_val,a[j]);
            }
            ans[max_val]++;
        }
        for (j=0;j<n;j++)
        {
            ma[j]=0;
        }
    }
    for (i=0;i<n;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}