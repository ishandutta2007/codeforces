#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<pair<pair<int,pair<int,int>>,int>> ans;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(v[i]>v[j]) ans.push_back({{i,{-v[j],-j}},j});
        }
    }   
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++)
    {
        cout<<(ans[i].first.first)+1<<" "<<ans[i].second+1<<'\n';
    }
}