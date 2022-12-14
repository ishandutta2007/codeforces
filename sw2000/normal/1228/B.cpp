#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;

int a,b;
int boa[maxn][maxn];

inline ll pm(ll a,ll n)
{
    ll ret=1;
    for(; n; n>>=1,a=a*a%mod)
        if(n&1)
            ret=ret*a%mod;
    return ret;
}

int main()
{
    memset(boa,-1,sizeof(boa));
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        for(int j=0;j<a;j++)
        {
            boa[i][j]=1;
        }
        boa[i][a]=0;
    }
    for(int i=0;i<m;i++)
    {
        cin>>b;
        for(int j=0;j<b;j++)
        {
            if(boa[j][i]==-1)
            {
                boa[j][i]=1;
            }
            else if(boa[j][i]==0)
            {
                cout<<0;
                return 0;
            }
        }
        if(boa[b][i]==1)
        {
            cout<<0;
            return 0;
        }
        boa[b][i]=0;
    }
    ll cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(boa[i][j]==-1)cnt++;
        }
    }
    cout<<pm(2,cnt)<<endl;
    return 0;
}