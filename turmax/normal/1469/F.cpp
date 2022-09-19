
#include <bits/stdc++.h>

using namespace std;
#define int long long
int cyc=0;
const int sz=71;
int cnt[sz];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    int low=(-1);int up=1e18;
    while(true)
    {
for(int i=0;i<sz;++i) cnt[i]=0;
        if((up-low)==1)
        {
            break;
        }
    int z=(low+up)/2;
    cyc=1;
    cnt[1]++;
    int pos=1;
    int sum2=1;
    for(int i=0;i<n;++i)
    {
        while(!cnt[pos]) ++pos;
        int o=pos;
        if(o<z)
        {
        cnt[pos]--;
        sum2--;
        sum2+=min((a[i]-1)/2,z-o);
        sum2+=min(a[i]/2,z-o);
        for(int i=(o+1);i<=(o+(a[i]-1)/2) && i<=40;++i)
        {
            cnt[i+1]++;
            ++cyc;
        }
        for(int i=(o+1);i<=(o+a[i]/2) && i<=40;++i)
        {
            cnt[i+1]++;
            ++cyc;
        }
        }
        else
        {
            break;
        }
    }
    if(sum2>=k)
    {
        up=z;
    }
    else
    {
        low=z;
    }
    }
    if(up!=1e18)
    cout<<up;
    else
    cout<<(-1);
    return 0;
}