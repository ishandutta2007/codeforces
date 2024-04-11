#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=3e5+10;

int n,deg[N],v[N][2],mark[N];
vector <int> e[N];
queue <int> q;
void prepare(){
    int m,x,y;
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        scanf("%d%d",&x,&y);
        v[i][0]=x;v[i][1]=y;
        e[x].push_back(i);
        e[y].push_back(i);
        deg[x]++,deg[y]++;
    }
}
int solve(){
    FOR(i,1,n) if (deg[i]==1) q.push(i);
    int ans=0;
    FOR(i,1,n) if (!deg[i]) ans++;
    while (!q.empty()){
        int x=q.front();q.pop();
        if (deg[x]==0) ans++;
//        cout<<x<<" "<<deg[x]<<'\n';
        for(auto i:e[x]) if (!mark[i]){
            mark[i]=1;
            FOR(j,0,1){
                int y=v[i][j];
//                cout<<i<<"->"<<y<<'\n';
                deg[y]--;
                if (deg[y]==1) q.push(y);
            }
        }
    }
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}