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
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
long long mul(long long x,long long y)
{
    if (y==0) return 0;
    long long ans=mul(x,y/2);
    if (ans==-1) return -1; else ans=ans+ans;
    if (ans<0) return -1;
    if (y%2==1) ans+=x;
    if (ans<0) return -1;
    return ans;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    long long p,q;
    cin>>p>>q;
    int n;
    cin>>n;
    int i;
    for (i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        long long t=mul(q,x);
        if (t==-1)
        {
            printf("NO\n");
            return 0;
        }
        if (p<t)
        {
            printf("NO\n");
            return 0;
        }
        p-=t;
        swap(p,q);
    }
    if (q!=0)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}