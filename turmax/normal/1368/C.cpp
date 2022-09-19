#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <pair<int,int> > ans;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int x=0;
    int y=0;
    {
    vector <pair<int,int> > ans;
    int x=0;
    int y=0;
    ans.push_back({0,-1});
    ans.push_back({0,-2});
    ans.push_back({-1,-2});
    ans.push_back({-2,-2});
    ans.push_back({-2,-1});
    ans.push_back({-2,0});
    ans.push_back({-1,0});
    for(int i=0;i<n;++i)
    {
        ans.push_back({x+0,y+0});
        ans.push_back({x+1,y+0});
        ans.push_back({x+2,y+0});
        ans.push_back({x+2,y+1});
        ans.push_back({x+0,y+1});
        ans.push_back({x+0,y+2});
        ans.push_back({x+1,y+2});
        x+=2;
        y+=2;
    }
    x-=2;y-=2;
    ans.push_back({x+2,y+2});
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    }
    return 0;
}