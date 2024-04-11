#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define rep(i,n) for(int i=1;i<=n;++i)
const int maxn = 1e5+5;
int a[maxn],b[maxn];
bool cmp(int a,int b)
{
    return a>b;
}
int32_t main()
{
    int n,m;
    cin>>n>>m;
    rep(i,n) cin>>a[i];
    rep(i,m) cin>>b[i];
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+m);
    if(a[1]>b[1]) {cout<<-1<<endl;return 0;}
    if(n==1&&a[1]!=b[1]) {cout<<-1<<endl;return 0;}
    int sz = m;
    int ans = 0;
    rep(i,n)
    {
        int pos = lower_bound(b+1, b+1+sz, a[i]) - b;
        if(sz==m&&pos==1&&b[pos]!=a[i]) ++pos;
        for(int i=pos;i<=sz;++i) ans+=b[i];
        ans+=a[i]*(pos-1+m-sz);
        sz=pos-1;
        if(!sz)
        {
            for(int j=i+1;j<=n;++j) ans += a[j]*m;
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}