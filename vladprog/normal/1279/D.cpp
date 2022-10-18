#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int MOD=998244353,N=1e6+100;

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

int rev(int x)
{
    return ppow(x,MOD-2);
}

int k[N];
vector<int> a[N];
int cnt[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k[i];
        a[i].resize(k[i]);
        for(int j=0;j<k[i];j++)
            cin>>a[i][j],
            cnt[a[i][j]]++;
    }
    int ans=0;
    int rn=rev(n);
    int rn2=rn*rn%MOD;
    for(int i=0;i<n;i++)
    {
        int rk=rev(k[i]);
        int p=rn2*rk%MOD;
        for(int j=0;j<k[i];j++)
            ans=(ans+p*cnt[a[i][j]])%MOD;
    }
    cout<<ans;
}