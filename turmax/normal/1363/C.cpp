#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n,x;
    cin>>n>>x;
    x--;
    vector <int> a[n];
    for(int i=0;i<(n-1);++i)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        a[u].push_back(v);a[v].push_back(u);
    }
    if(a[x].size()<=1)
    {
        cout<<"Ayush"<<endl;
        continue;
    }
    if(n%2==1)
    {
        cout<<"Ashish"<<endl;
        continue;
    }
    cout<<"Ayush"<<endl;
    }
    return 0;
}