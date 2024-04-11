#include <bits/stdc++.h>

using namespace std;
#define int long long
int cou(string s,char x)
{
    int ans=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]==x)
        {
            ++ans;
        }
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    char t=s[s.size()-1];
    if(t>='0' && t<='9')
    {
        cout<<(t-'0')%2;
    }
    else
    {
        cout<<(t-'A')%2;
    }
    return 0;
}