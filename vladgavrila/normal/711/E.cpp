#include <stdio.h>
#include <iostream>

using namespace std;

#define mod (1000003)

long long n, k;

long long lgput(long long nr, long long exp)
{
    if(exp==0)
        return 1;

    long long aux=lgput(nr, exp/2);
    aux=(aux*aux)%mod;
    if(exp%2)
        aux=(aux*nr)%mod;
    return aux;
}

int main()
{
    cin>>n>>k;
    if(n<63)
    {
        if((1LL<<n)<k)
        {
            printf("1 1\n");
            return 0;
        }
    }


    long long p2n=lgput(2, n);
    long long imod2=lgput(2, mod-2);

    long long imp=lgput(p2n, k-1);

    for(int i=1; i<=62; ++i)
    {
        long long nrdiv2i=((k-1)/(1LL<<i));
        imp=(imp*lgput(imod2, nrdiv2i))%mod;
    }

    long long deimp;
    if(k>mod)
        deimp=0;
    else
    {
        deimp=1;
        for(int i=1; i<k; ++i)
        {
            long long cc=(p2n-i+mod)%mod;
            int x=i;
            while(x%2==0)
            {
                x=x/2;
                cc=(cc*imod2)%mod;
            }
            deimp=(deimp*cc)%mod;
        }
    }

    deimp=(imp-deimp+mod)%mod;

    cout<<deimp<<" "<<imp<<"\n";

    return 0;
}