#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    int m;
    cin>>s;
    cin>>m;
    int u=1;
    int n=s.size();
    int curr=0;
    for(int i=0;i<n;++i)
    {
        curr+=(u*(s[n-i-1]-'0'));
        curr%=m;
        if(i!=(n-1)) u*=10;
        u%=m;
    }
    //cout<<curr<<" curr "<<endl;
    int mi=1e18;
    for(int i=0;i<n;++i)
    {
        if(s[i]!='0')
        mi=min(mi,curr);
        curr-=((s[i]-'0')*u);
        curr*=10;
        curr%=m;
        curr+=(s[i]-'0');
        curr%=m;
        curr+=m;
        curr%=m;
    }
    cout<<mi;
    return 0;
}