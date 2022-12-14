#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const ll mod=998244353;

int v[maxn];

ll jie(int a)
{
    ll res=1;
    for(int i=2;i<=a;i++)
    {
        res=(res*i)%mod;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    ll ans=n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a]++;
        v[b]++;
    }

    for(int i=1;i<=n;i++)
    {
        ans=(ans*jie(v[i]))%mod;
    }
    cout<<ans;

    return 0;
}