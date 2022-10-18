#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> y;
    set<int> xy;
    queue<pair<int,int>> q;
    while(n--)
    {
        int x;
        cin>>x;
        xy.insert(x);
        q.push({x-1,1});
        q.push({x+1,1});
    }
    int res=0;
    while(y.size()<m)
    {
        int p=q.front().first,
            d=q.front().second;
        q.pop();
        if(xy.count(p))
            continue;
        y.push_back(p);
        xy.insert(p);
        res+=d;
        q.push({p-1,d+1});
        q.push({p+1,d+1});
    }
    cout<<res<<"\n";
    for(int p:y)
        cout<<p<<" ";
}