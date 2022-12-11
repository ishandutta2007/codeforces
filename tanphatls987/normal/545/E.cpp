#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> lli;
const ll inf=1e16;
const int MOD=1e9+7;
const int N=3e5+10;

int n,m,x,y,st,w[N],v[N][2],t[N];
ll dist[N];
vector <int> e[N];
priority_queue <lli> q;
bool minimize(ll &x,ll y){
    if (x>y) x=y;else return false;
    return true;
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        scanf("%d%d%d",&x,&y,w+i);
        e[x].push_back(i);
        e[y].push_back(i);
        v[i][0]=x;v[i][1]=y;
    }
    FOR(i,1,n) dist[i]=inf;
    scanf("%d",&st);
    dist[st]=0;
    q.push(lli(0,st));
    vector <int> DAG;
    while (!q.empty()){
        int cx=q.top().Y;
        ll cw=-q.top().X;
        q.pop();
        if (cw>dist[cx]) continue;
        DAG.push_back(cx);
        for(auto i:e[cx]){
            int ny=v[i][0]+v[i][1]-cx;
            ll nw=cw+w[i];
            if (minimize(dist[ny],nw)) q.push(lli(-nw,ny));
        }
    }
    ll ansW=0;
    vector <int> ansE;
    FOR(i,1,n) t[i]=m+1;
    w[m+1]=int(2e9);
    t[st]=0;
    for(auto x:DAG){
        ansW+=w[t[x]];
        if (x!=st) ansE.push_back(t[x]);
        for(auto i:e[x]){
            int y=v[i][0]+v[i][1]-x;
            ll nw=dist[x]+w[i];
            if (nw>dist[y]) continue;
            if (w[t[y]]>w[i]) t[y]=i;
        }
    }
    printf("%lld\n",ansW);
    for(auto i:ansE) printf("%d ",i);
}