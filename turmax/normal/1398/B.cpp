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
        vector <int> v;
        int curr=0;
        bool h=false;
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            if(s[i]=='1')
            {
                ++curr;
                h=true;
            }
            if(s[i]=='0')
            {
                if(h)
                {
                    v.push_back(curr);
                    h=false;
                }
                curr=0;
            }
        }
        if(h) v.push_back(curr);
        sort(v.begin(),v.end());reverse(v.begin(),v.end());
        int sum=0;
        for(int i=0;i<v.size();i+=2)
        {
            sum+=v[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}