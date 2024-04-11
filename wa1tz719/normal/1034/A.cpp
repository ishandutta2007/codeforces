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
int p[4005];
bool is_prime(int x)
{
    int i;
    for (i=2;i*i<=x;i++)
    {
        if (x%i==0) return false;
    }
    return true;
}
int gcd(int x,int y)
{
    if (y==0) return x;
    return gcd(y,x%y);
}
int cnt[15000005];
int a[300005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    int cnts=0;
    for (i=2;i<=4000;i++)
    {
        if (is_prime(i)) p[cnts++]=i;
    }
    int gcd_val=0;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        gcd_val=gcd(gcd_val,a[i]);
    }
    for (i=0;i<n;i++)
    {
        a[i]/=gcd_val;
    }
    for (i=0;i<n;i++)
    {
        if (a[i]!=1) break;
    }
    if (i==n)
    {
        puts("-1");
        return 0;
    }
    int max_ans=0;
    for (i=0;i<n;i++)
    {
        int j;
        for (j=0;j<cnts;j++)
        {
            if (a[i]%p[j]==0)
            {
                cnt[p[j]]++;
                max_ans=max(max_ans,cnt[p[j]]);
                for (;;)
                {
                    a[i]/=p[j];
                    if (a[i]%p[j]!=0) break;
                }
            }
        }
        if (a[i]!=1)
        {
            cnt[a[i]]++;
            max_ans=max(max_ans,cnt[a[i]]);
        }
    }
    cout<<n-max_ans<<endl;
    return 0;
}