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
int last_prime[500005];
bool ok[200005];
int val[500005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,q;
    scanf("%d%d",&n,&q);
    int i;
    for (i=2;i<=500000;i++)
    {
        if (last_prime[i]==0)
        {
            int j;
            for (j=i;j<=500000;j+=i)
            {
                last_prime[j]=i;
            }
        }
    }
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        int p=1;
        int t;
        for (;a[i]!=1;)
        {
            t=last_prime[a[i]];
            p*=t;
            for (;a[i]%t==0;)
            {
                a[i]/=t;
            }
        }
        a[i]=p;
        ok[i]=0;
    }
    long long ans=0;
    for (i=0;i<q;i++)
    {
        int x;
        scanf("%d",&x);
        x--;
        int m=0;
        static int primes[25];
        int t=a[x];
        for (;t!=1;)
        {
            primes[m++]=last_prime[t];
            t/=last_prime[t];
        }
        int j;
        int flag;
        if (ok[x])
        {
            flag=-1;
        }
        else
        {
            flag=1;
        }
        ok[x]^=1;
        for (j=0;j<(1<<m);j++)
        {
            int p=1;
            int k;
            int tempflag=flag;
            //if (m&1) tempflag=-tempflag;
            for (k=0;k<m;k++)
            {
                if ((1<<k)&j)
                {
                    p*=primes[k];
                    tempflag=-tempflag;
                }
            }
            if (ok[x])
            {
                ans+=tempflag*val[p];
            }
            val[p]+=flag;
            if (!ok[x])
            {
                ans+=tempflag*val[p];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}