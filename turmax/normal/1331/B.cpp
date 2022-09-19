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
    int n;
    cin>>n;
    for(int i=2;i<n;++i)
    {
        if(n%i==0)
        {
            int x=i;
            int y=(n/i);
            cout<<x<<y;
            return 0;
        }
    }
    return 0;
}