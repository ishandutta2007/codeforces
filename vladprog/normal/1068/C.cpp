#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int k=1;
    vector<int> ans[n+1];
    for(int i=1;i<=n;i++)
        ans[i].push_back(k),k++;
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        ans[a].push_back(k);
        ans[b].push_back(k);
        k++;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i].size()<<"\n";
        for(auto x:ans[i])
            cout<<x<<" "<<i<<"\n";
    }
}