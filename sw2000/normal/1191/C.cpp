#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;

int main()
{
    ll n,m,k,p[maxn],ans=0,sub=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&p[i]);
        p[i]--;
    }

    for(int i=1;i<=m;i++)
    {
        ll now=(p[i]-sub)/k;
        for(int j=1;;j++)
        {
            ll a=(p[i+j]-sub)/k;
            if(i+j>m||a!=now)
            {
                sub+=j;
                i+=j-1;
                ans++;
                break;
            }
        }
    }

    cout<<ans;
    return 0;
}