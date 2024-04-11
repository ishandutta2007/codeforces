#include <bits/stdc++.h>

using namespace std;

int a[200005];
bool was[200005];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>a[i], was[a[i]]=true;
    set<int> x;
    for(int i=1;i<=n;i++)
    {
        if(!was[i]&&a[i-1]!=0) x.insert(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(!was[i]&&a[i-1]==0) x.insert(i);
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0 || was[i+1]) continue;
        if(*x.begin()!=i+1)
        {
            a[i]=*x.begin();
            x.erase(x.begin());
        }
        else
        {
            a[i]=*prev(x.end());
            x.erase(prev(x.end()));
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0) continue;
        if(*x.begin()!=i+1)
        {
            a[i]=*x.begin();
            x.erase(x.begin());
        }
        else
        {
            a[i]=*prev(x.end());
            x.erase(prev(x.end()));
        }
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}