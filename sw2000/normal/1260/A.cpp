#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    while(n--)
    {
        ll a,b,ans=0;
        cin>>a>>b;
        while(a)
        {
            ans+=(b/a)*(b/a);
            b-=b/a;
            a--;
        }
        cout<<ans<<endl;
    }
    return 0;
}