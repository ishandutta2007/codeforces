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
        vector <pair<int,int> > num;
        for(int i=0;i<n;++i) {if(s[i]!='?') num.push_back({i,s[i]-'0'});}
        vector <pair<int,int> > v;
        for(int i=0;i<((int) num.size())-1;++i)
        {
            if(((num[i].first%2)^num[i].second)!=((num[i+1].first%2)^num[i+1].second))
            {
                v.push_back({num[i].first,num[i+1].first});
            }
        }
        v.push_back({-1,-1});v.push_back({n,n});
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<v.size();++i) ans-=((v[i].second-v[i].first-1)*(v[i].second-v[i].first)/2);
        for(int i=0;i<v.size()-1;++i)
        {
            ans+=((v[i+1].second-v[i].first-1)*(v[i+1].second-v[i].first)/2);
        }
        cout<<ans<<'\n';
    }
    return 0;
}