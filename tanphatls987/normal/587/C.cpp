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
const int N=1e5+10;

int b[N],lv[N],ans[N],a[N],p[N][20],in[N],out[N],n,m,k;
int c[N][4],need[N],L[N],R[N],s[N];
vector <int> g[N],v[N];
queue <int> q[N];
int get(int x){
    int ans=0;
    while (x){
        ans+=b[x];
        x-=x&-x;
    }
    return ans;
}
void add(int x,int v){
    while (x<=n){
        b[x]+=v;
        x+=x&-x;
    }
}
void DFS(int x){
    static int top=0;
    in[x]=++top;
    lv[x]=lv[p[x][0]]+1;
    for(auto y:v[x]) if (y!=p[x][0]){
        p[y][0]=x;
        DFS(y);
    }
    out[x]=top;
}
int LCA(int x,int y){
    if (lv[x]<lv[y]) swap(x,y);
    for(int i=0,v=lv[x]-lv[y];v;i++,v>>=1) if (v&1)
        x=p[x][i];
    if (x==y) return x;
    for(int i=int(log2(lv[x]));i>=0;i--) if (p[x][i]!=p[y][i])
        x=p[x][i],y=p[y][i];
    return p[x][0];
}
void prepare(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n-1){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(1);
    FOR(lv,1,18)
        FOR(i,1,n) p[i][lv]=p[p[i][lv-1]][lv-1];
    FOR(i,1,m) scanf("%d",a+i);
    FOR(i,1,k) {
        scanf("%d%d%d",c[i],c[i]+1,need+i);
        c[i][2]=LCA(c[i][0],c[i][1]);
        c[i][3]=p[c[i][2]][0];
    }
}
void sweep(int phase){
    memset(b,0,sizeof(b));
    FOR(i,1,m){
        add(in[a[i]],1);
        add(out[a[i]]+1,-1);
        while (!q[i].empty()){
            int idx=q[i].front();q[i].pop();
            int tmp[4];
            FOR(i,0,3) tmp[i]=get(in[c[idx][i]]);
            if (tmp[0]+tmp[1]-tmp[2]-tmp[3]>=phase) R[idx]=i-1;
            else L[idx]=i+1;
        }
    }
}
void solve(){
    FOR(phase,1,10){
        int top=0;
        FOR(i,1,k) if (!ans[i]){
            s[++top]=i;
            L[i]=1,R[i]=m;
        }
        while (top){
            FORD(j,top,1) {
                int i=s[j];
                if (L[i]<=R[i]){
                    int mid=(L[i]+R[i])>>1;
                    q[mid].push(i);
                }else{
                    if (L[i]<=m) g[i].push_back(L[i]);
                    if (L[i]>m||need[i]==phase) ans[i]=1;
                    swap(s[j],s[top--]);
                }
            }
            sweep(phase);
        }
    }
    FOR(i,1,k){
        printf("%d ",int(g[i].size()));
        for(auto x:g[i]) printf("%d ",x);ENDL;
    }
}
int main(){
    prepare();
    solve();
}