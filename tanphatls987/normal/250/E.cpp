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
const int N=1e2+5,M=1e4+10;

int n,m,a[N][M],g[N][M];
char s[M];
void prepare(){
    scanf("%d%d",&n,&m);
    REP(i,0,n) {
        scanf("\n%s",s);
        FOR(j,1,m) if (s[j-1]=='+') a[i][j]=1;
        else if (s[j-1]=='#') a[i][j]=-1;
        a[i][0]=a[i][m+1]=-1;
    }
    REP(i,0,n){
        ///descend point
        FOR(j,1,m) g[i][j]=(a[i][j]!=-1&&!a[i+1][j]);
    }
}
void solve(){
    ll ans=0;
    for(int lv=0,L=1,R=1,dir=1,pos=1,stuck=0;lv<n-1;){
        while (!a[lv][L]&&!g[lv][L]) L--;
        while (!a[lv][R]&&!g[lv][R]) R++;
//        printf("%lld %d %d %d %d %d %d\n",ans,lv,L,R,pos,dir,stuck);
        if (dir){
            ans+=R-pos;
            if (a[lv][R]==0){
                stuck=0;
                L=pos=R;
                lv++;
            }else if (a[lv][R]==-1){
                if (stuck) {
                    printf("Never");
                    return;
                }
                pos=R-1;
                stuck=1;
                dir^=1;
            }else{
                pos=R-1;
                stuck=0;
                dir^=1;
                a[lv][R]=0;
            }
        }else{
            ans+=pos-L;
            if (a[lv][L]==0){
                stuck=0;
                R=pos=L;
                lv++;
            }else if (a[lv][L]==-1){
                if (stuck) {
                    printf("Never");
                    return;
                }
                pos=L+1;
                stuck=1;
                dir^=1;
            }else{
                pos=L+1;
                stuck=0;
                dir^=1;
                a[lv][L]=0;
            }
        }
    }
    cout<<ans+n-1;
}
int main(){
    prepare();
    solve();
}