#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e6+5;
int cnt[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,c;cin>>n>>c;
    int a[n][3];for(int i=0;i<n;++i) {cin>>a[i][0]>>a[i][1]>>a[i][2];cnt[a[i][0]]=max(cnt[a[i][0]],a[i][1]*a[i][2]);}
    for(int i=1;i<maxn;++i)
    {
        for(int j=1;i*j<maxn;++j)
        {
            cnt[i*j]=max(cnt[i*j],cnt[i]*j);
        }
    }
    for(int i=0;i<maxn-1;++i)
    {
        cnt[i+1]=max(cnt[i],cnt[i+1]);
    }
    int m;cin>>m;
    for(int i=0;i<m;++i)
    {
        int d,h;cin>>d>>h;
        int val=d*h;
        int pos=upper_bound(cnt,cnt+maxn,val)-cnt;
        if(pos>c) cout<<(-1)<<' ';
        else cout<<pos<<' ';
    }
    return 0;
}