#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    int n;
    cin>>n;
    vector <int> a(n);
    vector <int> b(n);
    vector <int> pr1(n+1);
    vector <int> pr2(n+1);
    pr1[0]=0;
    pr2[0]=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]==2)
        {
            a[i]=1;
        }
        else
        {
            a[i]=(-1);
        }
        pr1[i+1]=pr1[i]+a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
        if(b[i]==2)
        {
            b[i]=1;
        }
        else
        {
            b[i]=(-1);
        }
    }
    reverse(b.begin(),b.end());
    for(int i=0;i<n;++i)
    {
        pr2[i+1]=pr2[i]+b[i];
    }
    unordered_map <int,int> o1;
    unordered_map <int,int> o2;
    for(int i=0;i<=n;++i)
    {
        o1[pr1[i]]=i;
        o2[pr2[i]]=i;
    }
    int ans=2*n+1;
    for(int i=0;i<=n;++i)
    {
        if(o2.count(-pr1[i]))
        {
            ans=min(ans,(n-i)+(n-o2[-pr1[i]]));
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}