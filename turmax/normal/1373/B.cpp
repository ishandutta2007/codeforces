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
        int s0=0,s1=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='0')
            {
                s0++;
            }
            else
            {
                s1++;
            }
        }
        if(min(s0,s1)%2==1)
        {
            cout<<"DA"<<endl;
        }
        else
        {
            cout<<"NET"<<endl;
        }
    }
    return 0;
}