#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

#define int ll
ll dp[200005][2];
int l[200005],r[200005];
int a[200005];
int l2[200005][2],r2[200005][2]; // a
int rc[200005],cr[200005],rr[200005];
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    
    int mx=0,vis1=0;
    for(int i=1;i<=k;++i)
    {
        cin>>rc[i]>>cr[i];
        rr[i]=rc[i];
        mx=max(mx,rr[i]);
        if(rr[i]==1) vis1=1;
    }
    
    sort(rr+1,rr+1+k);
    
    int len = unique(rr+1,rr+1+k)-rr-1;
    
    for(int i=1;i<=k;++i)
        rc[i] = lower_bound(rr+1,rr+1+len,rc[i])-rr;
    
    for(int i=1;i<=k;++i)
    {
        if(!l[rc[i]]) l[rc[i]]=cr[i];
        else l[rc[i]]=min(l[rc[i]],cr[i]);
        if(!r[rc[i]]) r[rc[i]]=cr[i];
        else r[rc[i]]=max(r[rc[i]],cr[i]);
    }
    for(int i=1;i<=q;++i) cin>>a[i];
    sort(a+1,a+1+q);
    
    a[q+1] = 1e9;
    for(int i=1;i<=len;++i)
    {
        l2[i][0] = lower_bound(a+1,a+1+q,l[i])-a;
        if(a[l2[i][0]]>l[i] && l2[i][0]>1) l2[i][0]--;
        l2[i][1] = lower_bound(a+1,a+1+q,l[i])-a;
        if(l2[i][1]>q) l2[i][1]--;
        
        r2[i][0] = lower_bound(a+1,a+1+q,r[i])-a;
        if(a[r2[i][0]]>r[i] && r2[i][0]>1) r2[i][0]--;
        r2[i][1] = lower_bound(a+1,a+1+q,r[i])-a;
        if(r2[i][1]>q) r2[i][1]--;
    }
    
//    cout<<endl;
//    for(int i=1;i<=len;++i)
//    {
//        cout<<l[i]<<" "<<r[i]<<endl;
//        cout << l2[i][0] << " " << l2[i][1] << " / " << r2[i][0] << " " << r2[i][1] << endl;
//    }
//    cout<<endl;
    
    memset(dp,0x3f,sizeof(dp));
    dp[1][0] = l[1]-1, dp[1][1] = r[1]-1;
    if(!vis1) dp[1][0]=abs(a[1]-1)+abs(a[1]-l[1]),dp[1][1]=abs(a[1]-1)+abs(a[1]-r[1]);
    for(int i=1;i<len;++i)
    {
        ll tmp=r[i]-l[i];
        int p1=a[r2[i][0]],p2=a[r2[i][1]],p3=a[l2[i][0]],p4=a[l2[i][1]];
        
        dp[i+1][0]=min(dp[i+1][0],dp[i][0]+tmp+abs(p1-l[i+1])+abs(p1-r[i]));
        dp[i+1][0]=min(dp[i+1][0],dp[i][0]+tmp+abs(p2-l[i+1])+abs(p2-r[i]));
        dp[i+1][0]=min(dp[i+1][0],dp[i][1]+tmp+abs(p3-l[i+1])+abs(p3-l[i]));
        dp[i+1][0]=min(dp[i+1][0],dp[i][1]+tmp+abs(p4-l[i+1])+abs(p4-l[i]));
        
        dp[i+1][1]=min(dp[i+1][1],dp[i][0]+tmp+abs(p1-r[i+1])+abs(p1-r[i]));
        dp[i+1][1]=min(dp[i+1][1],dp[i][0]+tmp+abs(p2-r[i+1])+abs(p2-r[i]));
        dp[i+1][1]=min(dp[i+1][1],dp[i][1]+tmp+abs(p3-r[i+1])+abs(p3-l[i]));
        dp[i+1][1]=min(dp[i+1][1],dp[i][1]+tmp+abs(p4-r[i+1])+abs(p4-l[i]));
    }
    ll ans = min(dp[len][0],dp[len][1]) + r[len]-l[len];
    ans += mx-1;
    cout<<ans<<endl;
}