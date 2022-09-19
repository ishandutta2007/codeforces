#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector <int> v;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='?')
        {
            v.push_back(9);
        }
        else
        {
            v.push_back(2*(s[i]-'0'));
        }
    }
    int sum1=0;
    int sum2=0;
    for(int i=0;i<n/2;++i)
    {
        sum1+=v[i];
    }
    for(int i=n/2;i<n;++i)
    {
        sum2+=v[i];
    }
    if(sum1==sum2)
    {
        cout<<"Bicarp";
        return 0;
    }
    else
    {
        cout<<"Monocarp";
        return 0;
    }
    return 0;
}