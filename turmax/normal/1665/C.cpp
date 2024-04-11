#include <bits/stdc++.h>

using namespace std;
#define int long long
int f(int x,int y)
{
    if(x<=0) return 0;
    if(x<=y) return 1;
    return f(x-y,2*y)+1;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> ch[n];for(int i=1;i<n;++i) {int x;cin>>x;--x;ch[x].push_back(i);}
        vector<int> v;for(int i=0;i<n;++i) if(!ch[i].empty()) v.push_back(ch[i].size());
        sort(v.begin(),v.end());reverse(v.begin(),v.end());int ans=0;
        int low=(-1);int up=1e18;
        while(up-low>1) {int mid=(low+up)/2;if(mid<v.size()) {low=mid;continue;} int cur=0;for(int i=0;i<v.size();++i) {cur+=max(0LL,v[i]+i-mid-1);if(cur>2e18) break;} if(cur>mid-((int) v.size())) low=mid; else up=mid;}
        cout<<up+1<<'\n';
    }
    return 0;
}
/*
1
5
1 2 1 2
*/