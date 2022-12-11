#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+9;
const int N=1e5+10;

int n,h[N]={0},g[N]={0},und[N]={0};
ii a[N];
vector <int> b[N],c[N];
map <ii,int> ma;
int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%d",&a[i].X,&a[i].Y);
        ma[a[i]]=i;
    }
    FOR(i,1,n)
        FOR(j,-1,1){
            int idx=ma[ii(a[i].X+j,a[i].Y-1)];
            if (idx) {
                und[i-1]++;
                b[i-1].push_back(idx-1);
                c[idx-1].push_back(i-1);
            }
        }
    //REP(i,0,n) cout<<h[i]<<" \n"[i==n-1];
    priority_queue <int> q[2];
    REP(i,0,n) {
        bool ok=true;
        for(auto x:c[i]) if (und[x]==1) ok=false;
        if (ok) q[0].push(i),q[1].push(-i);
    }
    ll ans=0;
    REP(i,0,n){
        int cur=i%2;
        //printf("%d\n",i);
        while (1){
            int x=abs(q[cur].top());
            q[cur].pop();
            if (g[x]) continue;
            bool ok=true;
            for(auto y:c[x]) if (!g[y]&&und[y]==1) ok=false;
            if (!ok) continue;
            g[x]=1;
            und[x]=0;
            //printf("%d\n",x);
            ans=(ans*n+x)%MOD;
            for(auto y:b[x]) if (!g[y]) {
                bool ok=true;
                for(auto z:c[y]) if (!g[z]&&und[z]==1) ok=false;
                if (ok) q[0].push(y),q[1].push(-y);
            }
            for(auto y:c[x]) if (!g[y]) und[y]--;
            break;
        }
        //FOR(i,0,n-1) cout<<und[i]<<" \n";
    }
    cout<<ans;
}