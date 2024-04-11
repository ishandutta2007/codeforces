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
    string s;
    cin>>s;
    for(int i=0;i<(s.size()/2);++i)
    {
        cout<<s[2*i];
    }
    cout<<s[s.size()-1];
    cout<<endl;
    }
    return 0;
}