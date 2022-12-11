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
const int N=1e5+10;

int n,x,y,v[N<<1][2],p[N],h[N],pos[N];
vector <int> e[N];
void solve(){
    FOR(i,1,n) if (e[i].size()!=4){
        printf("-1\n");
        return;
    }
    bool ok;
    if (n<=7){
        FOR(i,1,n) p[i]=i;
        ok=0;
        do{
            FOR(i,1,n) pos[p[i]]=i;
            bool cok=1;
            FOR(x,1,n)
                for(auto idx:e[x]){
                    int y=v[idx][0]+v[idx][1]-x;
                    int dis=abs(pos[x]-pos[y]);
                    if (min(dis,n-dis)>2) cok=0;
                }
            if (cok==1){
                ok=1;
                break;
            }
        }while (next_permutation(p+1,p+n+1));
    }else{
        ok=1;
        p[1]=1;
        pos[1]=1;
        REP(phase,1,n) if (ok){
            int x=p[phase];
//            printf("%d %d\n",phase,x);
            for(auto idx:e[x]) h[v[idx][0]+v[idx][1]-x]=x;
            int c=0;
            for(auto idx:e[x]){
                int y=v[idx][0]+v[idx][1]-x;
                if (pos[y]) continue;
                int c1=0;
                for(auto idx2:e[y]) c1+=(h[v[idx2][0]+v[idx2][1]-y]==x);
                if (c1==2){
                    pos[p[phase+1]]=0;
                    p[phase+1]=y;
                    pos[y]=phase+1;
                    c++;
                }
            }
            ok&=(c==1+(phase==1));
        }
    }
    if (!ok) printf("-1");
    else FOR(i,1,n) printf("%d ",p[i]);
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n<<1){
        scanf("%d%d",&x,&y);
        v[i][0]=x;v[i][1]=y;
        e[x].push_back(i);
        e[y].push_back(i);
    }
    solve();
}