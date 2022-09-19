#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector <pair<int,int> > v;
    int x,y;
    map <pair<int,int>,int> o;
    for(int i=0;i<(k+1);++i)
    {
        cout<<'?'<<" ";
        for(int j=0;j<(k+1);++j)
        {
            if(j!=i)
            {
                cout<<(j+1)<<" ";
            }
        }
        cout<<endl;
        cin>>x>>y;
        if(o.count({y,x})==0)
        {
            o[{y,x}]=1;
            v.push_back({y,x});
        }
        else
        {
            o[{y,x}]++;
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    cout<<'!'<<" ";
    cout<<o[v[0]]<<endl;
    return 0;
}