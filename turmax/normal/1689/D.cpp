#include <bits/stdc++.h>

using namespace std;
#define int long long
bool cmp1(pair<int,int> a,pair<int,int> b) {return a.first-a.second<b.first-b.second;}
bool cmp2(pair<int,int> a,pair<int,int> b) {return a.first+a.second<b.first+b.second;}
bool cmp3(pair<int,int> a,pair<int,int> b) {return a.first-a.second>b.first-b.second;}
bool cmp4(pair<int,int> a,pair<int,int> b) {return a.first+a.second>b.first+b.second;}
int dist(pair<int,int> a,pair<int,int> b) {return abs(a.first-b.first)+abs(a.second-b.second);}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t1;cin>>t1;
    while(t1--)
    {
        int n,m;cin>>n>>m;string s[n];for(int i=0;i<n;++i) cin>>s[i];
        vector<pair<int,int> > v;for(int i=0;i<n;++i) for(int j=0;j<m;++j) if(s[i][j]=='B') v.push_back({i,j});
        vector<pair<int,int> > g;sort(v.begin(),v.end(),cmp1);g.push_back(v[0]);sort(v.begin(),v.end(),cmp2);g.push_back(v[0]);sort(v.begin(),v.end(),cmp3);g.push_back(v[0]);sort(v.begin(),v.end(),cmp4);g.push_back(v[0]);
        int res=1e9;pair<int,int> u;for(int i=0;i<n;++i) for(int j=0;j<m;++j) {int ans=(-1);for(auto h:g) ans=max(ans,dist({i,j},h));if(ans<res) {res=ans;u={i,j};}}
        cout<<u.first+1<<' '<<u.second+1<<'\n';
    }
    return 0;
}