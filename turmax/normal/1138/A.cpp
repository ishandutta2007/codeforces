#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n;
    vector <int> a;
    int l=1;
    int u;
    cin>>k;
    u=k;
    for(int i=1;i<n;++i)
    {
        cin>>k;
        if(u==k)
        {
            ++l;
        }
        else
        {
            a.push_back(l);
            l=1;
            u=k;
        }
    }
    a.push_back(l);
    int y=-1e9;
    for(int i=0;i+1<a.size();++i)
    {
        y=max(y,min(a[i],a[i+1]));
    }
    cout<<2*y;
    return 0;
}