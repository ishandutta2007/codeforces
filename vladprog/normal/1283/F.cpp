#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=2e5+100;

int a[N],ft[N],mx[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    set<pair<int,int>> leaves;
    for(int i=1;i<=n;i++)
        mx[i]=i;
    for(int i=1;i<=n;i++)
        leaves.insert({i,i});
    for(int i=1;i<=n-1;i++)
    {
        cin>>a[i];
        if(!ft[a[i]])
            ft[a[i]]=i;
        leaves.erase({a[i],a[i]});
    }
    vector<pair<int,int>> ans;
    for(int i=n-1;i>=1;i--)
    {
        if(leaves.empty())
            cout<<-1,exit(0);
        ans.push_back({a[i],leaves.begin()->second});
        mx[a[i]]=max(mx[a[i]],leaves.begin()->first);
        leaves.erase(leaves.begin());
        if(i==ft[a[i]])
            leaves.insert({mx[a[i]],a[i]});
    }
    cout<<a[1]<<"\n";
    for(auto p:ans)
        cout<<p.first<<" "<<p.second<<"\n";
}