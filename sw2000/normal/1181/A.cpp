#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;

int main()
{
    ll a,b,c,ans1,ans2=0;
    cin>>a>>b>>c;
    ans1=(a+b)/c;

    a%=c;
    b%=c;

    if(a+b>=c)
    {
        ans2=min(c-a,c-b);
    }

    cout<<ans1<<' '<<ans2;
    return 0;
}