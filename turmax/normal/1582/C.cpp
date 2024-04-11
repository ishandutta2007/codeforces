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
        int ans1=1e18;
        for(int j=0;j<26;++j)
        {
            string t;
            vector <int> z;
            for(int i=0;i<s.size();++i)
            {
                char h=s[i];
                if(h!=(j+'a'))
                {
                    t.push_back(h);
                    z.push_back(i);
                }
            }
            string t1=t;
            reverse(t1.begin(),t1.end());
            if(t!=t1) continue;
            vector <int> u;
            for(int i=0;i<s.size();++i)
            {
                if(s[i]==('a'+j))
                {
                    u.push_back(lower_bound(z.begin(),z.end(),i)-z.begin());
                }
            }
            int ans=0;
            for(int i=0;2*i<=z.size();++i)
            {
                 int cnt=upper_bound(u.begin(),u.end(),i)-lower_bound(u.begin(),u.end(),i);
                 int cnt2=upper_bound(u.begin(),u.end(),z.size()-i)-lower_bound(u.begin(),u.end(),z.size()-i);
                 ans+=max(cnt,cnt2)-min(cnt,cnt2);
            }
            ans1=min(ans1,ans);
        }
        if(ans1!=1e18) cout<<ans1<<'\n';
        else cout<<(-1)<<'\n';
    }
    return 0;
}