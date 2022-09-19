#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a[n];
    vector <int> b[n];
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
        b[x].push_back(i);b[y].push_back(i);
    }
    if(n==2)
    {
        cout<<0;
        return 0;
    }
    int res[n-1];
    for(int i=0;i<(n-1);++i)
    {
        res[i]=(-1);
    }
    int cur=0;
    for(int i=0;i<n;++i)
    {
        if(a[i].size()>=3)
        {
            res[b[i][0]]=0;
            res[b[i][1]]=1;
            res[b[i][2]]=2;
            cur=3;
            break;
        }
    }
    for(int i=0;i<(n-1);++i)
    {
        if(res[i]==(-1))
        {
            res[i]=cur;
            ++cur;
        }
    }
    for(int i=0;i<(n-1);++i)
    {
        cout<<res[i]<<endl;
    }
    return 0;
}