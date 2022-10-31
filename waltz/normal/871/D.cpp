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
bool prime[10000005];
int last_prime[10000005];
int miu[10000005];
int sums[10000005];
int tot[10000005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    prime[1]=false;
    memset(prime,true,sizeof(prime));
    for (i=2;i<=10000000;i++)
    {
        int j;
        if (prime[i])
        {
            last_prime[i]=i;
            if (i>10000) continue;
            for (j=i*i;j<=10000000;j+=i)
            {
                prime[j]=false;
                if (last_prime[j]==0) last_prime[j]=i;
            }
        }
    }
    miu[1]=1;
    for (i=2;i<=10000000;i++)
    {
        if ((i/last_prime[i])%last_prime[i]==0)
        {
            miu[i]=0;
        }
        else
        {
            miu[i]=-miu[i/last_prime[i]];
        }
    }
    long long ans=0;
    for (i=2;i<=n;i++)
    {
        if (miu[i]==0) continue;
        long long sum=0;
        int t=n/i;
        if (prime[i])
        {
            sum=sum+((long long)(t-1)*(t-2))/2;
        }
        else
        {
            sum=sum+((long long)(t-1)*t)/2;
        }
        ans+=miu[i]*sum;
    }
    int cnt=0;
    for (i=2;i<=n;i++)
    {
        if (prime[i]) continue;
        cnt++;
        tot[last_prime[i]]++;
    }
    for (i=2;i<n;i++)
    {
        tot[i+1]+=tot[i];
    }
    ans+=(long long)cnt*(cnt-1);
    int cnt2=0;
    for (i=2;i<=n/2;i++)
    {
        sums[i]=sums[i-1];
        if (prime[i])
        {
            cnt2++;
            sums[i]++;
        }
    }
    for (i=2;i<=n/2;i++)
    {
        if (prime[i])
        {
            ans-=(n/i)-1;
            ans-=tot[n/i];
            cnt2--;
            if (cnt2<0) cnt2=0;
            ans+=cnt2*3;
            if (n/i>=i) ans-=(sums[n/i]-sums[i]);
            ans+=cnt*3;
        }
    }
    cout<<ans<<endl;
    return 0;
}