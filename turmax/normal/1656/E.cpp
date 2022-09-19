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
        int n;cin>>n;vector<int> a[n];for(int i=0;i<n-1;++i) {int x,y;cin>>x>>y;--x;--y;a[x].push_back(y);a[y].push_back(x);}
        queue<int> v;int col[n];v.push(0);for(int i=0;i<n;++i) col[i]=(-1); col[0]=0;
        while(!v.empty())
        {
            int h=v.front();v.pop();
            for(auto h1:a[h])
            {
                if(col[h1]==(-1))
                {
                    col[h1]=col[h]^1;
                    v.push(h1);
                }
            }
        }
        for(int i=0;i<n;++i) {cout<<(2*col[i]-1)*((int) a[i].size())<<' ';} cout<<'\n';
    }
    return 0;
}