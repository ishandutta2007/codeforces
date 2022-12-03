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
char a[500005];
map<int,int> ma;
int ans=0;
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
        scanf("%s",a);
        int m=strlen(a);
        int j;
        int sum=0;
        int min_sum=0;
        int max_sum=0;
        for (j=0;j<m;j++)
        {
            if (a[j]=='(')
            {
                sum++;
            }
            else
            {
                sum--;
            }
            min_sum=min(min_sum,sum);
        }
        sum=0;
        for (j=m-1;j>=0;j--)
        {
            if (a[j]=='(')
            {
                sum++;
            }
            else
            {
                sum--;
            }
            max_sum=max(max_sum,sum);
        }
        if ((min_sum<0)&&(max_sum>0))
        {
            continue;
        }
        if (min_sum<0)
        {
            if (ma[-min_sum]>0)
            {
                ans++;
                ma[-min_sum]--;
            }
            else
            {
                ma[min_sum]++;
            }
        }
        else
        {
            if (ma[-max_sum]>0)
            {
                ans++;
                ma[-max_sum]--;
            }
            else
            {
                ma[max_sum]++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}