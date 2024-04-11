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
    int n;
    cin>>n;
    vector <int> a(n);
    set <int> d;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        d.insert(a[i]);
    }
    int color[n];
    color[0]=1;
    int ma=1;
    for(int i=0;i<(n-1);++i)
    {
        if(a[i]==a[i+1])
        {
            if((color[i]-color[0]-n+i+2*n)%2==1)
            color[i+1]=color[i];
            else
            color[i+1]=color[i]%2+1;
        }
        else
        {
            color[i+1]=color[i]%2+1;
        }
        ma=max(ma,color[i]);
        ma=max(ma,color[i+1]);
    }
    if(a[n-1]!=a[0] && color[n-1]==color[0])
    {
        color[n-1]=3;
        ma=max(ma,color[n-1]);
    }
    if(d.size()==1)
    {
        ma=1;
    }
    cout<<ma<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<min(ma,color[i])<<" ";
    }
    cout<<endl;
    }
    return 0;
}