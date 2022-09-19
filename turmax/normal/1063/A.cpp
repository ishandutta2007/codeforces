#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <char> t;
    string s;
    cin>>s;
    for(int i=0;i<n;++i)
    {
        t.push_back(s[i]);
    }
    sort(t.begin(),t.end());
    for(int i=0;i<n;++i)
    {
        cout<<t[i];
    }
    return 0;
}