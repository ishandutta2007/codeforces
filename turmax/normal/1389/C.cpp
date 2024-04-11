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
    int n=s.size();
    int ans=0;
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
        {
            int curr=0;
            int sz=0;
            for(int k=0;k<n;++k)
            {
                if((curr==0 && s[k]==('0'+i)) || (curr==1 && s[k]==('0'+j)))
                {
                    curr^=1;
                    ++sz;
                }
            }
            if(i!=j)
            ans=max(ans,(sz/2)*2);
            else
            ans=max(ans,sz);
        }
    }
    cout<<n-ans<<endl;
    }
    return 0;
}