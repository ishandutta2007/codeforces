#include <bits/stdc++.h>

using namespace std;
#define int long long
string s;
int slv(int l,int r)
{
    //cout<<l<<" "<<r<<endl;
    if((r-l)<=1)
    {
        return 0;
    }
    if(s[l]!=s[r-1])
    {
        return 0;
    }
    int g=r;
    for(int i=l;i<r;++i)
    {
        if(s[i]!=s[l])
        {
            g=i;
            break;
        }
    }
    if(g==r)
    {
        return (r-l+1);
    }
    int d=l;
    for(int i=(r-1);i>=l;i--)
    {
        if(s[i]!=s[r-1])
        {
            d=i+1;
            break;
        }
    }
    if(d==l)
    {
        return (r-l+1);
    }
    if(((g-l)+(r-d))<=2)
    {
        return 0;
    }
    return slv(g,d);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>s;
    cout<<slv(0,s.size());
    return 0;
}