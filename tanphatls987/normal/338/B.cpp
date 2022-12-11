#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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

int n,m,k,x,y,lv[2][N],h[N];
vector <int> v[N];
queue <int> q;
int BFS(int *dis,int st){
    int ans=0;
    FOR(i,1,n) dis[i]=0;
    dis[st]=1;
    q.push(st);
    while (!q.empty()){
        int x=q.front();q.pop();
        if (h[x]) ans=x;
        for(auto y:v[x]) if (!dis[y]){
//            printf("%d %d\n",x,y);
            dis[y]=dis[x]+1;
            q.push(y);
        }
    }
//    ENDL;
    return ans;
}
int solve(){
    int st=BFS(lv[0],1),en=BFS(lv[0],st);
    BFS(lv[1],en);
    int ans=0;
    FOR(i,1,n) if (lv[0][i]-1<=k&&lv[1][i]-1<=k) ans++;
    return ans;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    while (m--){
        scanf("%d",&x);
        h[x]=1;
    }
    FOR(i,2,n) {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    cout<<solve();
}