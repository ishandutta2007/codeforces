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
const int N=260,M=1e6+10;

int cord[N][2],ans[M],h[M],v[N*N][2],col[N*N],mark[N*N],n,m;
queue <int> q;
vector <int> e[N];
void prepare(){
    scanf("%d%d",&m,&n);
    FOR(i,1,n) scanf("%d%d",cord[i],cord[i]+1);
}
int BFS(int st,int scol){
    static int c1=0;
    h[st]=++c1;
    int ans=0;
    q.push(st);
    while (!q.empty()){
        int x=q.front();q.pop();
        ans++;
        for(auto i:e[x]) if (col[i]==scol){
            mark[i]=1;
            int y=v[i][0]+v[i][1]-x;
            if (h[y]==c1) continue;
            h[y]=c1;
            q.push(y);
        }
    }
    return ans;
}
int solve(){
    int m1=0;
    FOR(i,1,n)
        FOR(j,1,n) if (i!=j&&cord[i][1]>cord[j][1]){
            int cha=cord[i][1]-cord[j][1];
            if (1LL*cord[j][1]*abs(cord[j][0]-cord[i][0])%cha) continue;
            ll pos=cord[j][0]+1LL*cord[j][1]*(cord[j][0]-cord[i][0])/cha;
            if (pos>0&&pos<=m){
                ++m1;
                v[m1][0]=i;v[m1][1]=j;
                e[i].push_back(m1);
                e[j].push_back(m1);
                col[m1]=pos;
            }
        }
    FOR(i,1,m1) if (!mark[i]) ans[col[i]]=max(ans[col[i]],BFS(v[i][0],col[i]));
    int sans=0;
    FOR(i,1,m) sans+=max(ans[i],1);
    return sans;
}
int main(){
    prepare();
    cout<<solve();
}