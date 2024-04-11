#include <bits/stdc++.h>

using namespace std;
#define int long long
int f(int l,int r,int len)
{
    //cout<<l<<' '<<r<<' '<<len<<endl;
    //int ans=0;for(int i=0;i<=l;++i) for(int j=0;j<=r;++j) ans+=(i+j<=len); //return ans;
    if(len<0) return 0;
    if(len>l+r) {return (l+1)*(r+1);}
    if(l>r) swap(l,r);
    if(len<=l) {return (len+1)*(len+2)/2;}
    if(len<=r) {return (len+1)*(l+1)-l*(l+1)/2;}
    return (len-r+1)*(r+1)+r*(r+1)/2-(len-l+1)*(len-l)/2;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n];for(int i=0;i<n;++i) cin>>a[i];
        int pos[n+1];for(int i=0;i<n;++i) pos[a[i]]=i; pos[n]=(-1);
        int l=1e18;int r=(-1e18);
        int ans=0;
        for(int i=0;i<n;++i)
        {
            l=min(l,pos[i]);r=max(r,pos[i]);
            int u=pos[i+1];
            if(u>l && u<r) continue;
            int len=r-l+1;
            int len1;
            if(u<l) len1=(l-u-1); else len1=l;
            int len2;
            if(u>r) len2=u-r-1; else len2=n-r-1;
            ans+=f(len1,len2,2*i+2-len);
        }
        cout<<ans<<'\n';
    }
    return 0;
}