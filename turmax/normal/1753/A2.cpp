#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n];vector<int> pos;for(int i=0;i<n;++i) {cin>>a[i];if(a[i]) pos.push_back(i);}
        if(pos.size()%2==1) {cout<<(-1)<<'\n';continue;}
        pos.push_back(n);
        vector<pair<int,int> > v;
        for(int i=0;i<pos.size()-1;i+=2)
        {
            if(a[pos[i]]==a[pos[i+1]])
            {
                if((pos[i+1]-pos[i]-1)%2==0) v.push_back({pos[i],pos[i+2]-1});
                else {v.push_back({pos[i],pos[i+1]-2});v.push_back({pos[i+1]-1,pos[i+2]-1});}
            }
            else
            {
                v.push_back({pos[i],pos[i+1]-1});
                v.push_back({pos[i+1],pos[i+2]-1});
            }
        }
        bool used[n]={0};
        for(auto [x,y]:v)
        {
            for(int i=x;i<=y;++i) used[i]=true;
        }
        for(int i=0;i<n;++i) if(!used[i]) v.push_back({i,i});
        sort(v.begin(),v.end());
        cout<<v.size()<<'\n';
        for(auto [x,y]:v) cout<<x+1<<' '<<y+1<<'\n';
    }
    return 0;
}