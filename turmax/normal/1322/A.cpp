#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector <int> v;
    v.push_back(0);
    for(int i=0;i<n;++i)
    {
        if(s[i]=='(')
        v.push_back(v[i]+1);
        else
        v.push_back(v[i]-1);
    }
    if(v[n])
    {
        cout<<(-1);
        return 0;
    }
    int l=0;
    int ans=0;
    bool h=false;
    for(int i=0;i<=n;++i)
    {
        if(v[i]<0)
        {
            ++ans;
        }
        if(v[i]==0 && (i!=0) && v[i-1]<0)
        {
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}