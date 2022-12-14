#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,k;
        cin>>a>>b>>k;
        if(a+k<=b)cout<<0<<endl;
        else if(a>b+k)cout<<k+1<<endl;
        else
        {
            a+=k;
            ll c=a-b;
            ll ans=c>>1;
            if(c&1)ans++;
            cout<<ans<<endl;
        }
    }
    return 0;
}