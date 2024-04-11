#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        unordered_map<int, int> mp;
        vector<int> v;
        int n;
        cin>>n;
        forii
        {
            int tmp;cin>>tmp;
            mp[tmp]++;
        }
        for(auto p:mp) v.push_back(p.second);
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int m = 1e9;
        ll ans = 0;
        for(int i=0;i<v.size();++i)
        {
            m = min(m, v[i]);
            //cout<<i<<" "<<v[i]<<" "<<m<<endl;
            ans += m;
            --m;
            if(m<=0) break;
        }
        cout<<ans<<endl;
    }
}