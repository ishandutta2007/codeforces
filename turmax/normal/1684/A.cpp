#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        if(s.size()==2) {cout<<s[1]<<'\n';continue;}
        cout<<*min_element(s.begin(),s.end())<<'\n';
    }
    return 0;
}