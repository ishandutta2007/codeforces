#include <bits/stdc++.h>

using namespace std;
#define int long long
string slv(string h,vector<int> cnt)
{
    int mask=0;for(int i=0;i<10;++i) if(cnt[i]) mask+=(1<<i);
    int mask1=0;for(int i=0;i<h.size();++i) mask1^=(1<<(h[i]-'0'));
    for(int i=((int) h.size())-1;i>=0;--i)
    {
        mask1^=(1<<(h[i]-'0'));
        for(int j=h[i]-1;j>='0';--j)
        {
            mask1^=(1<<(j-'0'));
            h[i]=j;
            int mask2=mask^mask1;
            int len=((int) h.size())-i-1;
            if(__builtin_popcount(mask2)<=len)
            {
                vector<char> v;
                for(int i=0;i<10;++i) if(mask2 & (1<<i)) v.push_back('0'+i);
                while(v.size()<len) v.push_back('9');
                sort(v.begin(),v.end());reverse(v.begin(),v.end());
                for(int k=i+1;k<h.size();++k)
                {
                    h[k]=v[k-i-1];
                }
                return h;
            }
            mask1^=(1<<(j-'0'));
        }
    }
    return "?";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        int n=s.size();
        vector<int> cnt(10);for(int i=0;i<10;++i) cnt[i]=0;
        for(int i=0;i<n;++i) cnt[s[i]-'0']^=1;
        for(int i=0;i<=n;++i)
        {
            if(i>20 && s[n-i]=='0') continue;
            if(i!=0)
            {
                cnt[s[n-i]-'0']^=1;
            }
            string h;
            for(int j=n-i;j<n;++j) h.push_back(s[j]);
            string ans=slv(h,cnt);
            if(!ans.empty() && ans[0]=='?')
            {
                continue;
            }
            for(int j=n-i;j<n;++j)
            {
                s[j]=ans[j-(n-i)];
            }
            if(s[0]=='0')
            {
                for(int i=0;i<n-2;++i)
                {
                    cout<<'9';
                }
                cout<<endl;
                break;
            }
            cout<<s<<endl;
            break;
        }
    }
    return 0;
}