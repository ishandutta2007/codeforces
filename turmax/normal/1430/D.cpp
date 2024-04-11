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
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector <int> v;
        int curr=1;
        char l=s[0];
        for(int i=1;i<n;++i)
        {
            if(s[i]==l)
            {
                ++curr;
            }
            else
            {
                v.push_back(curr);
                l=s[i];
                curr=1;
            }
        }
        v.push_back(curr);
        int delay=0;
        int ans=0;
        int sum=n;
        int res=(-1);
        bool h=true;
        for(int i=0;i<v.size();++i)
        {
            //cout<<sum<<" sum "<<delay<<" delay "<<endl;
            //cout<<ans<<" ans "<<endl;
            res=max(res,ans+1);
            if(v[i]>=2)
            {
                delay=max(delay-v[i]+2,0LL);
            }
            else
            {
                ++delay;
            }
            sum-=v[i];
            if(sum>delay)
            {
                ++ans;
            }
            else
            {
                res=max(ans,res);
                h=false;
                break;
            }
        }
        if(!h)
        cout<<res<<endl;
        else
        cout<<v.size()<<endl;
    }
    return 0;
}