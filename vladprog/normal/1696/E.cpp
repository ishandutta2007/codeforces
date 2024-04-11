#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int N=4e5+100,MOD=1e9+7;

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

int a[N];
int fact[N],ifact[N];

int c(int a,int b)
{
    if(a+b>=N||a<0||b<0)
        return 0;
//    cout<<a<<" "<<b<<endl;
    return fact[a+b]*ifact[a]%MOD*ifact[b]%MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0]=1;
    for(int i=1;i<N;i++)
        fact[i]=fact[i-1]*i%MOD;
    ifact[N-1]=ppow(fact[N-1],MOD-2);
    for(int i=N-2;i>=0;i--)
        ifact[i]=ifact[i+1]*(i+1)%MOD;

    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
        cin>>a[i];
    int ans=-1;
    for(int i=0;i<=n;i++)
        ans=(ans+c(i,a[i]-1))%MOD;
    for(int i=0;i<N;i++)
    {
        int x=lower_bound(a,a+n+1,i,greater<>())-a;
        ans=(ans+c(i,x-1))%MOD;
    }
    cout<<max<int>(0,ans);
}