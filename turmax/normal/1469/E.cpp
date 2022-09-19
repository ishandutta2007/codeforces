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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int sz=0;
        while((1<<sz)<=n)
        {
            ++sz;
        }
        sz=min(sz,k);
        //sz=min(k,(int) 20);
        int ans[k];
        for(int i=0;i<(k-sz);++i)
        {
            ans[i]=0;
        }
        int curr=0;
        for(int i=0;i<(k-sz);++i) curr+=(s[i]-'0');
        set <int> ban;
        for(int i=0;i<=(n-k);++i)
        {
            //cout<<curr<<" curr "<<endl;
            if(curr==(k-sz))
            {
                int mask=0;
                for(int j=(i+k-sz);j<(i+k);++j)
                {
                    mask+=(s[j]-'0')*(1<<(i+k-j-1));
                }
                ban.insert((1<<sz)-1-mask);
            }
            if(i==(n-k)) break;
            curr-=(s[i]-'0');
            curr+=(s[i+k-sz]-'0');
        }
        bool h=false;
        for(int i=0;i<(1<<sz);++i)
        {
            if(!ban.count(i))
            {
                h=true;
                int x=i;
                for(int i=0;i<sz;++i)
                {
                    ans[k-i-1]=(x%2);
                    x/=2;
                }
                break;
            }
        }
        if(!h) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i=0;i<k;++i) cout<<ans[i];
            cout<<endl;
        }
    }
    return 0;
}