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
int ans[50005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    if (n<=100)
    {
        int i,j,k,l;
        for (i=0;i<=n;i++)
        {
            for (j=0;i+j<=n;j++)
            {
                for (k=0;i+j+k<=n;k++)
                {
                    l=n-i-j-k;
                    ans[i+j*5+k*10+l*50]=true;
                }
            }
        }
        int cnt=0;
        for (i=0;i<=50000;i++)
        {
            if (ans[i]) cnt++;
        }
        printf("%d\n",cnt);
        return 0;
    }
    int i;
    long long min_val=n+24;
    long long max_val=(long long)n*50-1960;
    for (i=0;i<=49;i++)
    {
        int j,k;
        for (j=0;i+j<=49;j++)
        {
            for (k=0;i+j+k<=49;k++)
            {
                ans[i*40+j*45+k*49]=true;
            }
        }
    }
    long long f_ans=max_val-min_val+1;
    for (i=0;i<1960;i++)
    {
        if (ans[i]) f_ans++;
    }
    f_ans+=12;
    cout<<f_ans<<endl;
    return 0;
}