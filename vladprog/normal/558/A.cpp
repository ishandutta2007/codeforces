#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector< pair<int,int> > l,r;
    for(int i=0;i<n;i++)
    {
        int x,a;
        cin>>x>>a;
        if(x>0)
            r.push_back({x,a});
        else
            l.push_back({-x,a});
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    if(l.size()>r.size()+1)
        l.resize(r.size()+1);
    if(r.size()>l.size()+1)
        r.resize(l.size()+1);
    int ans=0;
    for(auto p:l) ans+=p.second;
    for(auto p:r) ans+=p.second;
    cout<<ans;
}