#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define ml map < long , long >
#define mll map < pll , long >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
long h=1000000007,N=1000400;
long q,x,y,i,f[1000400+4],inv[1000400+4];
long po(long a,long b)
{
    if(a==0) return 0;
    if(a==1 || b==0) return 1;
    long ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%h;
        a=(a*a)%h;
        b>>=1;
    }
    return ans;
}
long ncr(long n,long r)
{
    if(n<r || n<0 || r<0) return 0;
    return (((f[n]*inv[r])%h)*inv[n-r])%h;
}
int main()
{
    io
    f[0]=1;
    for(i=1;i<=N;++i)
    f[i]=(i*f[i-1])%h;
    i--;
    inv[i]=po(f[i],h-2);
    i--;
    for(;i>=0;i--)
    inv[i]=((i+1)*inv[i+1])%h;
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        long ans=1;
        for(i=2;i*i<=x;++i)
        if(x%i==0)
        {
            long c=0;
            while(x%i==0)
            c++,x/=i;
            ans=(ans*ncr(c+y-1,c))%h;
        }
        if(x!=1)
        ans=(ans*y)%h;
        ans=(ans*po(2,(y-1)))%h;
        cout<<ans<<"\n";
    }
    return 0;
}