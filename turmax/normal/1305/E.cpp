#include <bits/stdc++.h>

using namespace std;
#define int long long
int n;
void go(vector <int> ans)
{
    int x=1e9;
    while(ans.size()<n)
    {
        x-=(7*n);
        ans.push_back(x);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i]<<" ";
    }
    exit(0);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m;
    cin>>n>>m;
    int h=0;
    int x=0;
    vector <int> ans;
    if(n==1)
    {
        if(m==0)
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<(-1);
            return 0;
        }
    }
    while(true)
    {
        if(x>n)
        {
            cout<<(-1);
            return 0;
        }
        if((h+x/2)<=m)
        {
            h+=(x/2);
            ++x;
            ans.push_back(x);
        }
        else
        {
            break;
        }
    }
    int u=m-h;
    int r=ans.size();
    if(r>n)
    {
        cout<<(-1);
        return 0;
    }
    if(u==0)
    {
        go(ans);
    }
    if(r==n)
    {
        cout<<(-1);
        return 0;
    }
    ans.push_back(r+(r-2*u+1));
    go(ans);
    return 0;
}