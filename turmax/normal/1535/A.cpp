#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(max(a,b)>=min(c,d) && max(c,d)>=min(a,b)) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}