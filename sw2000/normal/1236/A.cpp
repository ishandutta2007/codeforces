#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int ans=min(c/2,b);
        b-=ans;
        ans+=min(b/2,a);
        ans*=3;
        cout<<ans<<endl;
    }
    return 0;
}