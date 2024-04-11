#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    string s[n];
    vector <pair<vector <int>,int> > z;
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
        vector <int> v;
        for(int j=0;j<m;++j)
        {
            if(j%2==0)
            {
                v.push_back((int) s[i][j]);
            }
            else
            {
                v.push_back(-(int) s[i][j]);
            }
        }
        z.push_back({v,i});
    }
    sort(z.begin(),z.end());
    for(auto h:z) cout<<h.second+1<<' ';
    return 0;
}