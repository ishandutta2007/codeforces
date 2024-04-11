#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    int x[n];
    for(int i=0;i<n;++i) cin>>x[i];
    set<pair<int,int>> s;
    map<int,int> bio;
    for(int i=0;i<n;++i) 
    {
        bio[x[i]]=1;
        s.insert({1,x[i]-1});
        s.insert({1,x[i]+1});    
    }
    long long sum=0;
    vector<int> y;
    while(!s.empty() && (int)y.size()<m)
    {
        auto it=s.begin();
        int d=(*it).first;
        int p=(*it).second;
        s.erase(it);
        if(bio[p]) continue;
        bio[p]=1;
        sum+=d;
        y.push_back(p);
        if(!bio[p-1]) s.insert({d+1,p-1});
        if(!bio[p+1]) s.insert({d+1,p+1});
    }
    cout<<sum<<"\n";
    for(int c: y) cout<<c<<" ";
}