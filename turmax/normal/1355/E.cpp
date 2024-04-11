#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
int n,a,r,m;
int b[maxn];
int go(int s1,int s2)
{
    int ans=s1*a+s2*r;
    if(s1>=s2)
    {
        ans=min(ans,(s1-s2)*a+s2*m);
    }
    else
    {
        ans=min(ans,(s2-s1)*r+s1*m);
    }
    return ans;
}
int go1(int x)
{
    int s1=0,s2=0;
    for(int i=0;i<n;++i)
    {
        if(b[i]>=x)
        {
            s2+=(b[i]-x);
        }
        else
        {
            s1+=(x-b[i]);
        }
    }
    return go(s1,s2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>a>>r>>m;
    int pr[n+1];
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    sort(b,b+n);
    int s2=0;
    pr[0]=0;
    for(int i=0;i<n;++i)
    {
        s2+=(b[i]-b[0]);
        pr[i+1]=pr[i]+b[i];
    }
    int s1=0;
    int ans=8e18;
    for(int i=0;i<n;++i)
    {
        ans=min(ans,go(s1,s2));
        if(i!=(n-1))
        {
        s1+=(i+1)*(b[i+1]-b[i]);
        s2-=(n-i-1)*(b[i+1]-b[i]);
        }
    }
    int low=0;int up=1e9+2;
    while(true)
    {
        if((up-low)==1)
        {
            //cout<<low<<" "<<up<<" lowup "<<endl;
            ans=min(ans,go1(low));
            ans=min(ans,go1(up));
            break;
        }
        int k=(low+up)/2;
        int pos=lower_bound(b,b+n,k)-b;
        int s2=pr[n]-pr[pos];
        s2-=(n-pos)*k;
        int s1=-pr[pos];
        s1+=(pos*k);
        if(s2>s1)
        {
            low=k;
        }
        else
        {
            up=k;
        }
    }
    cout<<ans<<endl;
    return 0;
}