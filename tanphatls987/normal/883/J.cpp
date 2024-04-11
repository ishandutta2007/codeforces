#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef pair<int,int> ii;
typedef long long ll;

const int N=2e5+10;

int n,m;
int g[N],a[N];

int p[N];
ii w[N];


struct seg{
    ll b[N<<2],laz[N<<2];

    void lazyupdate(int node,int L,int R){
        b[node]+=laz[node];
        if (L<R){
            laz[node*2]+=laz[node];
            laz[node*2+1]+=laz[node];
        }
        laz[node]=0;
    }
    void update(int node,int L,int R,int l,int r,int val){
        lazyupdate(node,L,R);
        if (L>r||R<l) return;
        if (l<=L&&R<=r){
            laz[node]+=val;
            lazyupdate(node,L,R);
            return;
        }
        update(node*2,L,(L+R)/2,l,r,val);
        update(node*2+1,(L+R)/2+1,R,l,r,val);
        b[node]=min(b[node*2],b[node*2+1]);
    }
}mseg;
int solve(){
    for(int i=n;i>=1;i--) g[i]=max(g[i+1],a[i]);
    sort(w+1,w+m+1);
    for(int i=1;i<=m;i++)
        p[i]=upper_bound(g+1,g+n+1,w[i].Y,greater<int>())-g-1;

    for(int i=1;i<=n;i++) mseg.update(1,1,n,i,n,a[i]);
//    for(int i=1;i<=m;i++) cout<<w[i].X<<" "<<w[i].Y<<" "<<p[i]<<'\n';
    int ans=0;
    for(int i=1;i<=m;i++) if (p[i]){
        mseg.update(1,1,n,p[i],n,-w[i].X);
        if (mseg.b[1]<0) mseg.update(1,1,n,p[i],n,w[i].X);
        else ans++;
    }
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=m;i++) scanf("%d",&w[i].Y);
    for(int i=1;i<=m;i++) scanf("%d",&w[i].X);

    cout<<solve();
}