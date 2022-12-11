#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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

int n,m,st,v[N][2],w[N],d[N];
vector <int> e[N];
priority_queue <ii> q;
bool minimize(int &x,int y){
    if (x>y) x=y;else return 0;
    return 1;
}
void dijstra(int st){
    fill(d+1,d+n+1,inf);
    d[st]=0;
    q.push(ii(0,st));
    while (!q.empty()){
        int cw=-q.top().X,cx=q.top().Y;
        q.pop();
        if (cw>d[cx]) continue;
        for(auto i:e[cx]){
            int nx=v[i][0]+v[i][1]-cx;
            if (minimize(d[nx],d[cx]+w[i])) q.push(ii(-d[nx],nx));
        }
    }
}
void prepare(){
    scanf("%d%d%d",&n,&m,&st);
    int x,y;
    FOR(i,1,m){
        scanf("%d%d%d",&x,&y,w+i);
        v[i][0]=x;v[i][1]=y;
        e[x].push_back(i);
        e[y].push_back(i);
    }
    dijstra(st);
    int len;
    scanf("%d",&len);
    int ans=count(d+1,d+n+1,len);
//    FOR(i,1,n) cout<<d[i]<<" ";ENDL;
    FOR(i,1,m){
        if (d[v[i][0]]>d[v[i][1]]) swap(v[i][0],v[i][1]);
        int x=v[i][0],y=v[i][1];
        if (d[x]<len&&d[x]+w[i]>len){
            ans+=(d[y]+w[i]-(len-d[x]))>=len;
        }
        if (d[y]<len&&d[y]+w[i]>len){
            ans+=d[x]+w[i]-(len-d[y])>len;
        }
    }
    cout<<ans;
}
int main(){
    prepare();
}