
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)
#define debug(i) cout<<#i<<":"<<i<<endl;

int a[300005],b[300005],vis[300005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    rep(i,m) cin>>a[i]>>b[i];
    int x,y;
    x=a[1];
    rep(i,m) if(a[i]==x || b[i]==x) vis[i]=1;
    int ok = 1;
    rep(i,m)
    {
        if(!vis[i])
        {
            ok = 0;
            int tp = 1;
            y = a[i];
            rep(i,m) if(a[i]!=y && b[i]!=y && !vis[i]) tp=0;
            if(tp) {cout<<"yes"<<endl;return 0;}
            tp = 1;
            y = b[i];
            rep(i,m) if(a[i]!=y && b[i]!=y && !vis[i]) tp=0;
            if(tp) {cout<<"yes"<<endl;return 0;}
            tp = 1;
            break;
        }
    }
    if(ok) {cout<<"yes"<<endl;return 0;}
    memset(vis,0,sizeof(vis));
    ok = 1;
    x=b[1];
    rep(i,m) if(a[i]==x || b[i]==x) vis[i]=1;
    rep(i,m)
    {
        if(!vis[i])
        {
            ok = 0;
            int tp = 1;
            y = a[i];
            rep(i,m) if(a[i]!=y && b[i]!=y && !vis[i]) tp=0;
            if(tp) {cout<<"yes"<<endl;return 0;}
            tp = 1;
            y = b[i];
            rep(i,m) if(a[i]!=y && b[i]!=y && !vis[i]) tp=0;
            if(tp) {cout<<"yes"<<endl;return 0;}
            tp = 1;
            break;
        }
    }
    if(ok) {cout<<"yes"<<endl;return 0;}
    cout<<"no"<<endl;
}