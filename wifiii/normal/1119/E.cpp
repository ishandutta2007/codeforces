#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int main()
{
    int n;
    cin>>n;
    ll ans=0;
    ll cnt=0;
    forii
    {
        ll tmp;
        cin>>tmp;
        ll m = min(cnt, tmp/2);
        ans+=m,cnt-=m,tmp-=2*m;
        ans+=tmp/3;
        tmp%=3;
        cnt+=tmp;
    }
    cout<<ans<<endl;
}