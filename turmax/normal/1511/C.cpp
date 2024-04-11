#include <bits/stdc++.h>

using namespace std;
#define int long long
int mi[51];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<=50;++i) mi[i]=1e18;
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;++i) {cin>>a[i];mi[a[i]]=min(mi[a[i]],i);}
    for(int i=0;i<q;++i)
    {
        int x;
        cin>>x;
        int pos=mi[x];
        cout<<pos+1<<' ';
        mi[x]=0;
        for(int i=0;i<=50;++i)
        {
            if(i!=x && mi[i]<pos)
            {
                ++mi[i];
            }
        }
    }
    return 0;
}