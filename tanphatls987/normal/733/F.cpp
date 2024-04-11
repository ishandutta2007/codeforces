#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> lli;

#define X first
#define Y second


const int N=2e5+10;
const int M=20;
const ll inf=1e17;
int n,m;
int add;

vector <int> e[N];
int v[N][2];
int w[N],cost[N];
int pa[N][M];
int sma[N][M];
int lv[N];


ll d[N];
int h[N];
set <lli> mse;

void prim(){
    fill(d+1,d+n+1,inf);
    d[1]=0;
    for(int i=1;i<=n;i++) mse.insert(lli(d[i],i));
    while (!mse.empty()){
        lli cur=*mse.begin();
//        cout<<cur.X<<" "<<cur.Y<<'\n';
        mse.erase(cur);
        h[cur.Y]=1;
        for(auto i:e[cur.Y]){
            int y=v[i][0]+v[i][1]-cur.Y;
            if (h[y]) continue;
            ll nwei=w[i];
            if (nwei<d[y]){
                d[y]=nwei;
                pa[y][0]=cur.Y;
                sma[y][0]=i;
                lv[y]=lv[cur.Y]+1;
                mse.erase(lli(d[y],y));
                mse.insert(lli(nwei,y));
            }
        }
    }
//    for(int i=1;i<=n;i++) cout<<d[i]<<" \n"[i==n];
}
bool comp(int x,int y){
    return w[x]<w[y];
}
int get(int x,int y){
    if (lv[x]<lv[y]) swap(x,y);
    int ans=0;
    for(int i=0,val=lv[x]-lv[y];val;i++,val>>=1) if (val&1){
        ans=max(ans,sma[x][i],comp);
        x=pa[x][i];
    }
    if (x==y) return ans;
    for(int i=int(log2(lv[x]));i>=0;i--) if (pa[x][i]!=pa[y][i]){
        ans=max(ans,sma[x][i],comp);
        ans=max(ans,sma[y][i],comp);
        x=pa[x][i];
        y=pa[y][i];
    }
    ans=max(ans,sma[x][0],comp);
    ans=max(ans,sma[y][0],comp);
    return ans;
}

void prepare(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d",w+i);
    for(int i=1;i<=m;i++) scanf("%d",cost+i);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[i][0]=x;v[i][1]=y;
        e[x].push_back(i);
        e[y].push_back(i);
    }
    scanf("%d",&add);
    prim();
    for(int j=1;j<M;j++)
        for(int i=1;i<=n;i++) pa[i][j]=pa[pa[i][j-1]][j-1];
    for(int j=1;j<M;j++)
        for(int i=1;i<=n;i++) sma[i][j]=max(sma[i][j-1],sma[pa[i][j-1]][j-1],comp);
}
void solve(){
    ll ans=inf;
    ii use;
    for(int i=1;i<=m;i++){
        int cur=get(v[i][0],v[i][1]);
        ll change=-1LL*w[cur]+w[i]-(add/cost[i]);
//        cout<<i<<" "<<cur<<" "<<w[i]<<" "<<change<<'\n';
        if (ans>change){
            ans=change;
            use=ii(i,cur);
        }
    }
    ///
    for(int i=2;i<=n;i++) ans+=w[sma[i][0]];
    printf("%lld\n",ans);
    for(int i=2;i<=n;i++) if (sma[i][0]!=use.Y)
        printf("%d %d\n",sma[i][0],w[sma[i][0]]);
    printf("%d %d\n",use.X,w[use.X]-(add/cost[use.X]));
}
int main(){
    prepare();
    solve();
}