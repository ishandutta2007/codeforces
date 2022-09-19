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
    int m;
    cin>>m;
    vector <int> b(m);
    for(int i=0;i<m;++i) cin>>b[i];
    bool used[m];
    for(int i=0;i<m;++i) used[i]=false;
    int h=0;
    vector <vector <int> > g;
    while(h!=m)
    {
        vector <int> v;
        for(int i=0;i<m;++i)
        {
            if(b[i]==0 && !used[i])
            {
                ++h;
                used[i]=true;
                v.push_back(i);
            }
        }
        g.push_back(v);
        for(int i=0;i<m;++i)
        {
            if(!used[i])
            {
                for(int j=0;j<v.size();++j)
                {
                    b[i]-=abs(v[j]-i);
                }
            }
        }
    }
    int l[26];
    for(int i=0;i<26;++i) l[i]=0;
    for(int i=0;i<s.size();++i) l[s[i]-'a']++;
    int curr=0;
    char ans[m];
    for(int i=25;i>=0;i--)
    {
        if(l[i]>=g[curr].size() && curr<g.size())
        {
            for(int j=0;j<g[curr].size();++j)
            {
                ans[g[curr][j]]='a'+i;
            }
            ++curr;
        }
    }
    for(int i=0;i<m;++i)
    {
        cout<<ans[i];
    }
    cout<<endl;
    }
    return 0;
}