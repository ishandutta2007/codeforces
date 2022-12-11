#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=5e5+10;

int b[N<<2],a[N],n,m,d[N][2],f[N],g[N],t[N],p[N],last[N];
vector <int> pos[N];
bool maximize(int &x,int y){
    if (x<y) x=y;else return 0;
    return 1;
}
void lazyupdate(int node,int L,int R){
    if (L<R){
        b[2*node]=max(b[2*node],b[node]);
        b[node*2+1]=max(b[node*2+1],b[node]);
    }
}
void update(int node,int L,int R,int l,int r,int v){
    lazyupdate(node,L,R);
    if (L>r||R<l) return;
    if (v<b[node]) return;
    if (l<=L&&R<=r){
        b[node]=max(b[node],v);
        lazyupdate(node,L,R);
        return;
    }
    update(node*2,L,(L+R)/2,l,r,v);
    update(node*2+1,(L+R)/2+1,R,l,r,v);
}
int get(int node,int L,int R,int x){
    lazyupdate(node,L,R);
    if (L>x||R<x) return 0;
//    printf("%d %d %d %d\n",node,L,R,x);
    if (L==R) return b[node];
    return max(get(node*2,L,(L+R)/2,x),get(node*2+1,(L+R)/2+1,R,x));
}
void solve(){
//    FOR(i,1,n) cout<<a[i]<<" \n"[i==n];
    FOR(i,1,n){
//        cout<<i<<'\n';
        a[i]=lower_bound(p+1,p+m+1,a[i])-p;
        int m1=pos[a[i]].size();
        if (m1) g[a[i]]=max(g[a[i]],get(1,1,n,pos[a[i]][m1-1]));
        ///copy element
        f[i]=f[i-1];
        t[i]=t[i-1];
        d[i][0]=d[i-1][0];d[i][1]=d[i-1][1];
        //
//        printf("%d %d %d %d\n",i,g[a[i]],m1,f[i]);
        if (g[a[i]]) {
            if (maximize(f[i],f[g[a[i]]-1]+1)){
                t[i]=g[a[i]]-1;
                d[i][0]=p[a[g[a[i]]]];
                d[i][1]=p[a[i]];
            }
        }
        if (m1) {
            update(1,1,n,pos[a[i]][m1-1]+1,i-1,pos[a[i]][m1-1]);
            if (m1>1) g[a[i]]=max(g[a[i]],pos[a[i]][m1-2]);
        }
        pos[a[i]].push_back(i);
    }
//    FOR(i,1,n) cout<<a[i]<<" \n"[i==n];
    printf("%d\n",4*f[n]);
    for(int x=n,i=1;i<=f[n];i++){
        FOR(i,0,1) printf("%d %d ",d[x][1],d[x][0]);
        x=t[x];
    }
}
int main(){
    scanf("%d",&n);
    FORD(i,n,1) scanf("%d",a+i);
    FOR(i,1,n) p[i]=a[i];
    sort(p+1,p+n+1);
    m=unique(p+1,p+n+1)-p-1;
    solve();
}