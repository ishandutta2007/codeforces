#include <bits/stdc++.h>

using namespace std;
#define int long long
string h;
vector <int> v[26];
void go(vector <int> z)
{
    int mi=1e18;
    if(z.empty()) return;
    for(auto h:z)
    {
        mi=min(mi,v[h].back());
    }
    for(int i=z.size()-1;i>=0;--i)
    {
        if(v[z[i]][0]<=mi)
        {
            h+=('a'+z[i]);
            int l=v[z[i]][0];
            for(int j=0;j<26;++j)
            {
                v[j].erase(v[j].begin(),upper_bound(v[j].begin(),v[j].end(),l));
            }
            z.erase(z.begin()+i);
            go(z);
            return;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        h="";
        for(int i=0;i<26;++i) v[i].clear();
        for(int i=0;i<s.size();++i)
        {
            v[s[i]-'a'].push_back(i);
        }
        vector <int> z;
        for(int i=0;i<26;++i)
        {
            if(!v[i].empty())
            {
                z.push_back(i);
            }
        }
        go(z);
        cout<<h<<endl;
    }
    return 0;
}