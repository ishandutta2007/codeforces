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
const int N=5e3+10;

int n,m,w[N],v[N][2],t[N],sub[N],q[N];
ll f[N];
vector <int> e[N];
void prepare(){
    scanf("%d",&n);
    int x,y;
    FOR(i,1,n-1) {
        scanf("%d%d%d",&x,&y,w+i);
        v[i][0]=x,v[i][1]=y;
        e[x].push_back(i);
        e[y].push_back(i);
    }
}
ll BFS(int st){
    int top=1,bot=1;
    q[1]=st;
    ll ans=0;
    while (top<=bot){
        int x=q[top++];
        sub[x]=1;
        for(auto i:e[x]){
            int y=v[i][0]+v[i][1]-x;
            if (!t[y]){
                t[y]=i;
                q[++bot]=y;
            }
        }
    }
    FORD(i,bot,2){
        int x=q[i];
        int idx=t[x],y=v[idx][0]+v[idx][1]-x;
        sub[y]+=sub[x];
        f[y]+=f[x]+1LL*sub[x]*w[idx];
    }
    FOR(i,2,bot){
        int x=q[i];
        int idx=t[x],y=v[idx][0]+v[idx][1]-x;
        f[x]=f[y]+1LL*w[idx]*(bot-2*sub[x]);
    }
    int x=st;
    FOR(i,1,bot) {
        ans+=f[q[i]];
        if (f[q[i]]<f[x]) x=q[i];
    }
    return (ans>>1)+f[x]*(n-bot);
}
ll solve(){
    ll ans=ll(1e17);
    FOR(sel,1,n-1){
        memset(t,0,sizeof(t));
        memset(f,0,sizeof(f));
        t[v[sel][0]]=t[v[sel][1]]=-1;
        ll cans=0;
        FOR(i,0,1) cans+=BFS(v[sel][i]);
//        printf("%d\n",sel);
//        FOR(i,1,n) printf("%d ",t[i]);ENDL;
//        FOR(i,1,n) printf("%lld ",f[i]);ENDL;
//        FOR(i,1,n) printf("%d ",sub[i]);ENDL;
        ans=min(ans,cans+1LL*w[sel]*sub[v[sel][0]]*sub[v[sel][1]]);
    }
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}