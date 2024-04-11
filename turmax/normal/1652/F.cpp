#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;string s;cin>>s;
    int sz=(1<<n);
    vector<int> ans[sz];
    for(int i=0;i<sz;++i) {ans[i]={s[i]-'a'};}
    for(int i=1;i<=n;++i)
    {
        vector<vector<int> > z;
        for(int cur=0;cur<sz;cur+=(1<<i))
        {
            vector<int> v1=ans[cur];vector<int> v2=ans[cur+(1<<(i-1))];
            for(int j=0;j<v1.size();++j) {z.push_back({v1[j],v2[j],cur,j});z.push_back({v2[j],v1[j],cur,j+v1.size()});}
            ans[cur].resize(1<<i);
        }
        sort(z.begin(),z.end());
        int cur=0;
        for(int i=0;i<z.size();++i)
        {
            if(i==0 || (z[i][0]==z[i-1][0] && z[i][1]==z[i-1][1]))
            {
                ans[z[i][2]][z[i][3]]=cur;
            }
            else
            {
                ++cur;
                ans[z[i][2]][z[i][3]]=cur;
            }
        }
    }
    int pos=min_element(ans[0].begin(),ans[0].end())-ans[0].begin();string res;for(int i=0;i<sz;++i) {res.push_back(s[i^pos]);} cout<<res;
    return 0;
}