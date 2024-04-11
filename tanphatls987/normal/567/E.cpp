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
typedef pair<ll,int> lli;

const ll inf=1e15;
const int MOD=1e9+7;
const int N=1e5+10;

int n,m,v[N][2],w[N],t[2][N],g[N],h[N],s[N],key[N],st,en,mark[N];
ll d[2][N],ans[N];
priority_queue <lli> pq;
queue <int> q;
vector <int> e[2][N];
template <class T>
bool minimize(T& x,T y){
    if (x>y) x=y;else return 0;
    return 1;
}
void dijstra(int st,int type){
    FOR(i,1,n) d[type][i]=inf;
    d[type][st]=0;
    t[type][st]=-1;
    pq.push(lli(0,st));
    while (!pq.empty()){
        ll cw=-pq.top().X;
        int cx=pq.top().Y;
        pq.pop();
        if (cw>d[type][cx]) continue;
        for(auto i:e[type][cx]){
            int nx=v[i][0]+v[i][1]-cx;
            if (minimize(d[type][nx],w[i]+cw)){
                t[type][nx]=i;
                pq.push(lli(-d[type][nx],nx));
            }
        }
    }
}
void BFS(int st){
    h[st]=1;
    q.push(st);
//    printf("%d\n",st);
    while (!q.empty()){
        int x=q.front();q.pop();
//        printf("%d ",x);
        for(auto idx:e[0][x]){
            int y=v[idx][0]+v[idx][1]-x;
            if (d[0][x]+d[1][y]+w[idx]>d[0][en]) continue;
            if (key[y]){
                if (mark[idx]) continue;
//                printf("%d %d\n",st,y);
                g[key[y]]--;
                g[key[st]]++;
                continue;
            }
            if (h[y]) continue;
            h[y]=1;
            q.push(y);
        }
    }
//    ENDL;
}
void solve(){
    int top=1;
    s[1]=st;
    key[st]=1;
    while (s[top]!=en){
        int x=s[top],idx=t[1][x];
        int nx=v[idx][0]+v[idx][1]-x;
        s[++top]=nx;
        key[nx]=top;
        mark[idx]=1;
    }
//    FOR(i,1,top) cout<<s[i]<<" \n"[i==top];
//    FOR(i,1,n) cout<<key[i]<<" ";ENDL;
    FOR(i,1,top) h[s[i]]=1;
    FOR(i,1,top) BFS(s[i]);
    FOR(i,1,top) {
        g[i]+=g[i-1];
        if (!g[i]) ans[t[1][s[i]]]=-1;
    }
    FOR(i,1,m) if (!ans[i]){
        int x=v[i][0],y=v[i][1];
        ll rem=d[0][en]-(d[0][x]+d[1][y]+1);
        if (rem>0) ans[i]=w[i]-rem;
    }
    FOR(i,1,m){
        if (ans[i]==-1) printf("YES\n");
        else if (ans[i]) printf("CAN %I64d\n",ans[i]);
        else printf("NO\n");
    }
}
int main(){
    scanf("%d%d%d%d",&n,&m,&st,&en);
    FOR(i,1,m){
        int x,y;
        scanf("%d%d%d",&x,&y,w+i);
        v[i][0]=x;v[i][1]=y;
        e[0][x].push_back(i);
        e[1][y].push_back(i);
    }
    dijstra(st,0);
    dijstra(en,1);
    solve();
}