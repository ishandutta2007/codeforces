#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    string s;
    cin>>s;
    if(s.size()==1)
    {
        for(int i=0;i<(n-1);++i)
        {
             cout<<a[i]<<s[0];
        }
        cout<<a[n-1];
        return 0;
    }
    if(s.size()==3)
    {
        for(int i=0;i<3;++i)
        {
            if(s[i]=='-')
            {
                s.erase(s.begin()+i);
                break;
            }
        }
    }
    if(s.size()==2)
    {
        if((s[0]=='-' && s[1]=='*') || (s[0]=='*' && s[1]=='-'))
        {
             int pos=(-1);
             for(int i=0;i<n;++i)
             {
                 if(a[i]==0)
                 {
                     pos=i;
                     break;
                 }
             }
             if(pos==(-1))
             {
                 for(int i=0;i<(n-1);++i)
        {
             cout<<a[i]<<'*';
        }
        cout<<a[n-1];
        return 0;
             }
             else
             {
                 for(int i=0;i<(n-1);++i)
        {
            if(i!=(pos-1))
             cout<<a[i]<<'*';
             else
             cout<<a[i]<<'-';
        }
        cout<<a[n-1];
        return 0;
             }
        }
        else if((s[0]=='+' && s[1]=='-') || (s[0]=='-' && s[1]=='+'))
        {
            for(int i=0;i<(n-1);++i)
        {
             cout<<a[i]<<'+';
        }
        cout<<a[n-1];
        return 0;
        }
        else
        {
            string ans;
            for(int i=0;i<n;++i) ans+=' ';
            bool used[n];
            for(int i=0;i<n;++i) used[i]=false;
            for(int i=0;i<n;++i)
            {
                if(a[i]==0)
                {
                    ans[i]='+';
                    ans[max(i-1,0LL)]='+';
                    used[i]=true;
                }
            }
            for(int i=0;i<n;++i)
            {
                if((i==0 || used[i-1]) && a[i]==1)
                {
                    ans[i]='+';
                    ans[max(i-1,0LL)]='+';
                    used[i]=true;
                }
            }
            for(int i=(n-1);i>=0;--i)
            {
                if((i==(n-1) || used[i+1]) && a[i]==1)
                {
                    ans[i]='+';
                    ans[max(i-1,0LL)]='+';
                    used[i]=true;
                }
            }
            vector <pair<int,int> > v;
            int l=(-1);
            bool h=false;
            for(int i=0;i<n;++i)
            {
                 if(!used[i])
                 {
                     if(!h)
                     {
                         h=true;
                         l=i;
                     }
                 }
                 else
                 {
                     if(h)
                     {
                         h=false;
                         v.push_back({l,i-1});
                     }
                 }
            }
            if(h)
            {
                v.push_back({l,n-1});
            }
            for(auto h:v)
            {
                int l=h.first;
                int r=h.second;
                int pr1=1;
                for(int i=l;i<=r;++i)
                {
                    pr1*=a[i];
                    if(pr1>=1e6) pr1=1e6;
                }
                if(pr1>=1e6)
                {
                    for(int i=l;i<r;++i)
                    {
                        ans[i]='*';
                    }
                    continue;
                }
                vector <pair<int,int> > z;
                for(int i=l;i<=r;++i)
                {
                    if(a[i]!=1)
                    {
                        z.push_back({i,a[i]});
                    }
                }
                int dp[z.size()+1];
                dp[z.size()]=0;
                int pr[z.size()+1];
                for(int i=((int) z.size())-1;i>=0;i--)
                {
                    dp[i]=(-1e18);
                    pr1=1;
                    for(int j=(i+1);j<=z.size();++j)
                    {
                        pr1*=z[j-1].second;
                        int o=(z[j].first-z[j-1].first-1)+pr1+dp[j];
                        if(o>dp[i])
                        {
                            dp[i]=o;
                            pr[i]=j;
                        }
                    }
                }
                int curr=0;
                while(true)
                {
                    int u=pr[curr];
                    int h=z[u-1].first;
                    for(int i=z[curr].first;i<h;++i)
                    {
                        ans[i]='*';
                    }
                    if(u==z.size()) break;
                    for(int i=h;i<z[u].first;++i)
                    {
                        ans[i]='+';
                    }
                    curr=u;
                }
            }
            for(int i=0;i<(n-1);++i)
            {
                cout<<a[i]<<ans[i];
            }
            cout<<a[n-1];
            return 0;
        }
    }
    return 0;
}