#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
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
const int N=13,M=20;

ll f[1<<N][M];
int poss[1<<N][M],v[M],s[M],tmp[1<<N],LCA[N][N],n;
void prepare(){
    int m,k,x,y,z;
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,m){
        scanf("%d%d",&x,&y);
        x--;y--;
        v[x]|=1<<y;
        v[y]|=1<<x;
    }
    memset(LCA,-1,sizeof(LCA));
    REP(st,0,1<<n)
        REP(root,0,n) if (st&(1<<root)) poss[st][root]=((1<<n)-1)^st;
    while (k--){
        scanf("%d%d%d",&x,&y,&z);
        x--;y--;z--;
        if (LCA[x][y]!=-1&&LCA[x][y]!=z){
            printf("0");
            exit(0);
        }
        LCA[x][y]=z;
    }
    REP(x,0,n) if (LCA[x][x]!=-1&&LCA[x][x]!=x){
        printf("0");
        exit(0);
    }
    REP(x,0,n)
        REP(y,0,n) if (LCA[x][y]!=-1)
            REP(st,0,1<<n) {
//                cout<<st<<" "<<x<<" "<<y<<'\n';
                if ((st&(1<<x))) REP(z,0,n) if (z!=LCA[x][y]&&(poss[st][z]&(1<<y))) poss[st][z]^=1<<y;
                if ((st&(1<<y))) REP(z,0,n) if (z!=LCA[x][y]&&(poss[st][z]&(1<<x))) poss[st][z]^=1<<x;
            }
    REP(st,0,1<<n)
        REP(root,0,n) if (st&(1<<root))
            REP(y,0,n)
                REP(x,0,n) if ((poss[st][root]&(1<<y))&&x!=root&&(v[x]&(1<<y))&&(st&(1<<x))) poss[st][root]^=1<<y;
//    REP(st,0,1<<n)
//        REP(x,0,n) cout<<st<<" "<<x<<" "<<poss[st][x]<<'\n';
}

ll solve(){
    REP(i,0,n) f[1<<i][i]=1;
    REP(st,1,1<<n){
        int top=0;
        REP(i,0,n) if (st&(1<<i)) s[++top]=i;
        if (top==1) continue;
        FOR(sel,1,top){
            int root=s[sel];
            FOR(sel2,1,top) if (sel2!=sel){
                int son=s[sel2],n2=0;
                REP(i,0,n) if (st&(1<<i)&&i!=root&&i!=son){
                    tmp[1<<n2]=1<<i;
                    n2++;
                }
//            cout<<st<<" "<<root<<" "<<f[st][root]<<'\n';
                REP(j,0,1<<n2){
                    tmp[j]=tmp[j&-j]|tmp[j^(j&-j)];
                    int idx=v[root]&tmp[j],cv=__builtin_popcount(idx);
                    if (cv) continue;
                    int L=st^(tmp[j])^(1<<son),R=tmp[j]|(1<<son);
                    if ((poss[L][root]&R)!=R) continue;
                    if ((L^(1<<root))>R) continue;
//                    cout<<st<<" "<<root<<" "<<L<<" "<<son<<" "<<R<<'\n';
                    f[st][root]+=1LL*f[L][root]*f[R][son];
                }
            }
//            cout<<st<<" "<<root<<" "<<f[st][root]<<'\n';
        }
    }
    return f[(1<<n)-1][0];
}
int main(){
    prepare();
    cout<<solve();
}