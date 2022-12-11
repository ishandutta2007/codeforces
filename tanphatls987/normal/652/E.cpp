#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("mdraft.inp","r",stdin)
#define OUTPUT freopen("mdraft.out","w",stdout)
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

int n,m,st,en,w[N],v[N][2];
vector <int> e[N];
vector <ii> v2[N];
///find cut edges
int low[N],num[N],t[N],br[N];
///good group?
queue <int> q;
int good[N],t2[N];
void prepare(){
    scanf("%d%d",&n,&m);
    int x,y;
    FOR(i,1,m){
        scanf("%d%d%d",&x,&y,w+i);
        e[x].push_back(i);
        e[y].push_back(i);
        v[i][0]=x;
        v[i][1]=y;
    }
    scanf("%d%d",&st,&en);
}
void DFS(int x,int le){
    static int top=0;
    low[x]=num[x]=++top;
    for(auto i:e[x]) if (i!=le){
        int y=v[i][0]+v[i][1]-x;
        if (!num[y]){
            t[y]=i;
            DFS(y,i);
        }
        low[x]=min(low[x],low[y]);
    }
}
void BFS(int st){
    static int n1=0;
    num[st]=++n1;
    q.push(st);
    while (!q.empty()){
        int x=q.front();q.pop();
        for(auto i:e[x]) if (!br[i]){
            int y=v[i][0]+v[i][1]-x;
            if (w[i]) good[n1]=1;
            if (!num[y]){
                num[y]=n1;
                q.push(y);
            }
        }
    }
}
int solve(){
    DFS(st,0);
    FOR(i,1,n) if (low[i]>=num[i]) br[t[i]]=1;
    memset(num,0,sizeof(num));
    FOR(i,1,n) if (!num[i]) BFS(i);
    FOR(i,1,m) if (br[i]){
        int x=num[v[i][0]],y=num[v[i][1]];
        v2[x].push_back(ii(y,w[i]));
        v2[y].push_back(ii(x,w[i]));
    }
    st=num[st],en=num[en];
    q.push(st);
    memset(t2,-1,sizeof(t2));
    t2[st]=good[st];
    while (!q.empty()){
        int x=q.front();q.pop();
        for(auto i:v2[x]) if (t2[i.X]==-1){
            t2[i.X]=t2[x]|i.Y|good[i.X];
            q.push(i.X);
        }
    }
    return t2[en];
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    if (solve()) cout<<"YES";
    else cout<<"NO";
}