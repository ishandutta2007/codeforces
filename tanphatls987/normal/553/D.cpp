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

int weak[N],deg[N],h[N],n,m,k,x,y,ans[N];
vector <int> v[N];
struct node{
    int num,den,x;
    node (int _x){
        x=_x;num=weak[x],den=deg[x];
    }
};
class comp{
    public:bool operator()(node a,node b){
        return 1LL*a.num*b.den<1LL*a.den*b.num;
    }
};
priority_queue <node,vector<node>,comp> q;
void solve(){
    FOR(i,1,n) if (h[i])
        for(auto y:v[i]) weak[y]++;
        //printf("tick");
    FOR(i,1,n) if (!h[i]) q.push(node(i));
    FOR(i,1,n-k){
        node cur=q.top();q.pop();
        //printf("%d %d\n",i,cur.x);
        if (h[cur.x]){
            i--;continue;
        }
        ans[i]=cur.x;
        h[cur.x]=1;
//        printf("%d %d %d %d\n",i,cur.x,cur.num,cur.den);
        for(auto y:v[cur.x]) if (!h[y]){
            weak[y]++;
            q.push(node(y));
        }
    }
    int sel=1;
    FOR(i,2,n-k) if (1LL*weak[ans[i]]*deg[ans[sel]]<1LL*weak[ans[sel]]*deg[ans[i]]) sel=i;
    printf("%d\n",n-k-sel+1);
    FOR(i,sel,n-k) printf("%d ",ans[i]);
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,k) {
        scanf("%d",&x);
        h[x]=1;
    }
    FOR(i,1,m){
        scanf("%d%d",&x,&y);
        deg[x]++,deg[y]++;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    solve();
}