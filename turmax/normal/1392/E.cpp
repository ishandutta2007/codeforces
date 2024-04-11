#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int po[64];
    int u=1;
    for(int i=0;i<64;++i) {po[i]=u;u*=2;}
    int n;
    cin>>n;
    int ans[n][n];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i%2==0) ans[i][j]=(po[(i+j)]);
            else ans[i][j]=(po[(i+j+1)]);
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j) cout<<ans[i][j]<<' ';
        cout<<endl;
    }
    int q;
    cin>>q;
    while(q--)
    {
    int curr;
    cin>>curr;
    curr-=ans[0][0];
    vector <pair<int,int> > z;
    pair <int,int> o={0,0};
    z.push_back(o);
    while((o.first+o.second)<=(2*n-3))
    {
        if(curr & (po[(o.first+o.second+1)]))
        {
            if(o.first%2==0) o.second++;
            else o.first++;
        }
        else
        {
            if(o.first%2==0) o.first++;
            else o.second++;
        }
        curr-=ans[o.first][o.second];
        z.push_back(o);
    }
    for(auto v:z)
    {
        cout<<v.first+1<<' '<<v.second+1<<endl;
    }
    }
    return 0;
}