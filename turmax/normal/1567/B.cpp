#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+5;
int pref[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<maxn;++i) pref[i]=pref[i-1]^i;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(pref[a-1]==b) cout<<a<<'\n';
        else if(pref[a-1]!=(b^a)) cout<<a+1<<'\n';
        else cout<<a+2<<'\n';
    }
    return 0;
}