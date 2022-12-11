#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5+10,M=5e3+10;

struct don{
    int l,r;
    double p;
    void read(){
        scanf("%d%d%lf",&l,&r,&p);
    }
}d[M];
int f[N][20],n,m,t[M];
vector <int> b[M];
double g[M][M];
bool comp(don a,don b){
    if (a.l==b.l) return a.r>b.r;
    return a.l<b.l;
}
int RMQ(int x,int y){
    if (x>y) swap(x,y);
    int bar=int(log2(y-x));
    return max(f[x][bar],f[y-(1<<bar)+1][bar]);
}
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&f[i][0]);
    FOR(i,1,m) d[i].read();
    m++;
    d[m].r=n;d[m].l=1;d[m].p=.0;
    sort(d+1,d+m+1,comp);
    FOR(j,1,18){
        int bar=1<<(j-1);
        FOR(i,1,n-bar) f[i][j]=max(f[i][j-1],f[i+bar][j-1]);
    }
    int top=1;
    stack <int> s;
    s.push(1);
    FOR(i,2,m){
        while (d[i].l>d[s.top()].r) s.pop();
        b[s.top()].push_back(i);
        s.push(i);
    }
    FOR(i,1,m) t[i]=RMQ(d[i].l,d[i].r);
}
void DFS(int x){
    int v=t[x];
    for(auto &i:b[x]) DFS(i);
    FOR(j,0,m){
        double fc=d[x].p,fnc=(1-d[x].p);
        if (!j) fc=.0;
        for(auto &i:b[x]){
            int cv=t[i];
            if (v+j-cv-1<0) fc=.0;
            else fc*=g[i][min(v+j-cv-1,m)];
            if (v+j-cv<0) fnc=.0;
            else fnc*=g[i][min(v+j-cv,m)];
        }
        g[x][j]=fnc+fc;
    }
}
void solve(){
    DFS(1);
    double ans=t[1]*g[1][0];
    FOR(i,1,m) ans+=(t[1]+i)*(g[1][i]-g[1][i-1]);
    printf("%.6f",ans);
}
int main(){
    prepare();
    solve();
}