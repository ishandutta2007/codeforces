#include <stdio.h>
#include <iostream>

using namespace std;

#define mod 1000000007
#define maxn 200010

int n, q0;
int g[maxn], f[maxn], q[maxn];
int a[maxn];

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        cin>>a[i];
        ++g[a[i]];
    }

    long long sol=1;

    for(int i=1; i<=n; ++i)
        if(!g[i])
            q[++q0]=i;

    for(int i=1; i<=q0; ++i)
    {
        int nod=q[i];
        f[nod]=1;
        --g[a[nod]];
        if(g[a[nod]]==0)
            q[++q0]=a[nod];
        sol=(sol*2)%mod;
    }

    for(int i=1; i<=n; ++i)
    {
        if(f[i])
            continue;

        long long cr=1;
        int x=i;

        do
        {
            f[x]=1;
            x=a[x];
            cr=(cr*2)%mod;
        } while(x!=i);

        cr=(cr-2+mod)%mod;

        sol=(sol*cr)%mod;
    }

    cout<<sol<<"\n";

    return 0;
}