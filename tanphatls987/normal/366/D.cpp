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
const int N=1e3+10;

struct edge{
    int x,y,L,R;
    void read(){
        scanf("%d%d%d%d",&x,&y,&L,&R);
    }
}e[N<<2];
int n,m,f[N];
vector <int> a[N];
priority_queue <ii> q;
bool comp(edge a,edge b){
    return a.L<b.L;
}
bool maximize(int &x,int y){
    if (x<y) x=y;else return false;
    return true;
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m) e[i].read();
    sort(e+1,e+m+1,comp);
    FOR(i,1,m){
        a[e[i].x].push_back(i);
        a[e[i].y].push_back(i);
    }
    int ans=0;
    FOR(j,1,m){
        while (j<m&&e[j+1].L==e[j].L) j++;
        q.push(ii(inf,1));
        memset(f,-1,sizeof(f));
        f[1]=inf;
        while (!q.empty()){
            int cR=q.top().X,cx=q.top().Y;
            q.pop();
            if (cR<f[cx]) continue;
            for(auto i:a[cx]) if (i<=j){
                int nx=e[i].x+e[i].y-cx,nR=min(cR,e[i].R);
                if (maximize(f[nx],nR)) q.push(ii(nR,nx));
            }
        }
        //cout<<e[j].L<<" "<<f[n]-e[j].L;
        ans=max(ans,f[n]-e[j].L+1);
    }
    if (ans==0) printf("Nice work, Dima!");
    else printf("%d",ans);
}