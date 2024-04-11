#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define mp make_pair
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front

using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define x first
#define y second

const int N=2e5+100,MOD=998244353;

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

int f[N],r[N];

int c(int n,int k)
{
    return f[n]*r[k]%MOD*r[n-k]%MOD;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    f[0]=1;
    for(int i=1;i<N;i++)
        f[i]=f[i-1]*i%MOD;
    r[N-1]=ppow(f[N-1],MOD-2);
    for(int i=N-2;i>=0;i--)
        r[i]=r[i+1]*(i+1)%MOD;
    int rev2=ppow(2,MOD-2);
    int n,k;
    cin>>n>>k;
    int s;
    cin>>s;
    int p=s,m=0;
    for(int i=2;i<=n;i++)
    {
        int h;
        cin>>h;
        if(h!=p)
            m++;
        p=h;
    }
    if(p!=s)
        m++;
    if(!m)
        cout<<0,exit(0);
    int ans=0;
    for(int i=0;i<=m;i++)
    {
        int res=ppow(2,i);
        if(i%2==0)
            res-=c(i,i/2),
            res=(res+MOD)%MOD;
        res=res*rev2%MOD*ppow(k-2,m-i)%MOD*c(m,i)%MOD;
        ans+=res;
    }
    ans=ans%MOD*ppow(k,n-m)%MOD;
    cout<<ans;
}