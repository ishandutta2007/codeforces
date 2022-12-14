#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=3e5+10;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;

ll jie[maxn],m,n;

int main()
{
//    freopen("in.txt","r",stdin);
    cin>>n>>m;
    ll ans=0;
    jie[0]=1;
    for(int i=1;i<maxn;i++)
    {
        jie[i]=jie[i-1]*i%m;
    }
    for(int i=1;i<=n;i++)
    {
        ll a=jie[i]*jie[n-i]%m;
        a*=(n-i+1)*(n-i+1)%m;
        ans+=a;
        ans%=m;
    }
    cout<<ans;
    return 0;
}