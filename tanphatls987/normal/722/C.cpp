#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e5+10;
int n,a[N],p[N],h[N];
ll ans[N];

struct DSU{
    ll w[N];
    int t[N];
    int root(int x){
        if (t[x]<0) return x;
        return (t[x]=root(t[x]));
    }
    ll merge(int x,int y){
        int rx=root(x),ry=root(y);
        if (x==y) return 0;
        if (t[rx]>t[ry]) swap(rx,ry);
        t[rx]+=t[ry];
        t[ry]=rx;
        w[rx]+=w[ry];
        return w[rx];
    }
    void build(){
        memset(t,-1,sizeof(t));
        for(int i=1;i<=n;i++) w[i]=a[i];
    }
}mdsu;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++) scanf("%d",p+i);
    mdsu.build();
    for(int i=n;i>=1;i--){
        ans[i]=max(ans[i+1],ll(a[p[i]]));
        for(int j=-1;j<=1;j++) if (h[p[i]+j]) ans[i]=max(ans[i],mdsu.merge(p[i],p[i]+j));
        h[p[i]]=1;
    }
    for(int i=1;i<=n;i++) printf("%lld\n",ans[i+1]);
}