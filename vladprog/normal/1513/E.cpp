#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,MOD=1e9+7;

int ppow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}

int a[N],f[N],r[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    f[0]=1;
    for(int i=1;i<N;i++)
        f[i]=f[i-1]*i%MOD;
    r[N-1]=ppow(f[N-1],MOD-2);
    for(int i=N-2;i>=0;i--)
        r[i]=r[i+1]*(i+1)%MOD;

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int avg=accumulate(a+1,a+n+1,0ll);
    if(avg%n)
        cout<<0,exit(0);
    avg/=n;
    int pos=0,neg=0,zero=0;
    map<int,int> mpos,mneg;
    for(int i=1;i<=n;i++)
    {
        a[i]-=avg;
        if(a[i]>0)
            pos++,
            mpos[a[i]]++;
        else if(a[i]<0)
            neg++,
            mneg[a[i]]++;
        else
            zero++;
    }
    if(pos<=1||neg<=1)
    {
        int ans=f[n];
        for(auto[_,x]:mpos)
            ans=ans*r[x]%MOD;
        for(auto[_,x]:mneg)
            ans=ans*r[x]%MOD;
        ans=ans*r[zero]%MOD;
        cout<<ans;
    }
    else
    {
        int ans=2;
        ans=ans*f[pos]%MOD;
        for(auto[_,x]:mpos)
            ans=ans*r[x]%MOD;
        ans=ans*f[neg]%MOD;
        for(auto[_,x]:mneg)
            ans=ans*r[x]%MOD;
        ans=ans*f[n]%MOD;
        ans=ans*r[zero]%MOD;
        ans=ans*r[n-zero]%MOD;
        cout<<ans;
    }
}