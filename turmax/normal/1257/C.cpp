#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cycle=0;cycle<t;++cycle)
    {
    int n;
    cin>>n;
    int mi=1e18;
    vector <int> a(n);
    vector <int> last(n+1);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        last[i]=(-1);
    }
    last[n]=(-1);
    for(int i=0;i<n;++i)
    {
        if(last[a[i]]!=(-1))
        {
            mi=min(mi,i-last[a[i]]);
        }
        last[a[i]]=i;
    }
    if(mi==1e18)
    {
        cout<<(-1)<<endl;
    }
    else
    {
        cout<<mi+1<<endl;
    }
    }
    return 0;
}