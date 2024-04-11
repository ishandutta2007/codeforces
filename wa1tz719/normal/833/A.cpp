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
int p[305];
int a[1005];
int sqrt_3(long long t)
{
    int l=1,r=1000000;
    for (;l<=r;)
    {
        int mid=(l+r)/2;
        if ((long long)mid*mid*mid==t) return mid;
        if ((long long)mid*mid*mid<t) l=mid+1; else r=mid-1;
    }
    return -1;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    memset(a,-1,sizeof(a));
    int sum=0;
    for (i=2;i<=1000;i++)
    {
        if (a[i]==-1)
        {
            p[sum++]=i;
            int j;
            for (j=i;j<=1000;j+=i)
            {
                a[j]=0;
            }
        }
    }
    //printf("%d\n",sum);
    for (i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        long long t=(long long)x*y;
        int z=sqrt_3(t);
        if (z==-1)
        {
            puts("No");
            continue;
        }
        int i;
        for (i=0;i<sum;i++)
        {
            int a,b,c;
            a=0;
            b=0;
            c=0;
            for (;z%p[i]==0;)
            {
                z/=p[i];
                c++;
            }
            for (;x%p[i]==0;)
            {
                x/=p[i];
                a++;
            }
            for (;y%p[i]==0;)
            {
                y/=p[i];
                b++;
            }
            if (abs(b-a)>c)
            {
                puts("No");
                break;
            }
        }
        if (i!=sum) continue;
        if (z!=1)
        {
            if ((x==1)||(y==1))
            {
                puts("No");
                continue;
            }
        }
        puts("Yes");
    }
    return 0;
}