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
    int a[2*n];
    for(int i=0;i<2*n;++i) {cin>>a[i];a[i]--;}
    int ans[n];
    bool is[n];
    for(int i=0;i<n;++i) is[i]=false;
    int curr=0;
    for(int i=0;i<2*n;++i)
    {
        if(!is[a[i]])
        {
            is[a[i]]=true;
            ans[curr]=a[i];
            ++curr;
        }
    }
    for(int i=0;i<n;++i) cout<<ans[i]+1<<' ';
    cout<<endl;
    }
    return 0;
}