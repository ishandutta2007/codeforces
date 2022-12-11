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
const int N=1e2+10;

ll ans[N];
int v[N*N][2],gcd[N*N],lcm[N*N],q[N],n,m,x,y;
vector <int> e[N];
void solve(){
    FOR(st,1,n) if (!ans[st]){
        if (e[st].empty()) ans[st]=1;
        else {
            //printf("tick\n");
            int idx=e[st][0];
            bool overall=0;
            FOR(stv,gcd[idx],lcm[idx]) if (stv%gcd[idx]==0){
                bool ok=1;
                ans[st]=stv;
                int top=1,bot=1;
                q[1]=st;
                while (ok&&top<=bot){
                    int x=q[top++];
                    for(auto i:e[x]){
                        int y=v[i][0]+v[i][1]-x;
                        if (ans[y]){
//                            printf("%d %d %lld %lld\n",x,y,ans[x],ans[y]);
                            int v1=__gcd(ans[x],ans[y]);
                            ll v2=1LL*v1*lcm[i];
                            if (v1!=gcd[i]||v2!=ans[x]*ans[y]) ok=0;
                        }else{
                            ll mul=1LL*gcd[i]*lcm[i];
//                            printf("%d %d %lld\n",x,y,mul);
                            if (mul%ans[x]) ok=0;
                            ans[y]=mul/ans[x];
                            q[++bot]=y;
                        }
                    }
                }
                if (ok){
                    overall=1;
                    break;
                }
                FOR(i,1,bot) ans[q[i]]=0;
            }
            if (!overall){
                printf("NO");
                return;
            }
        }
    }
    printf("YES\n");
    FOR(i,1,n) printf("%I64d ",ans[i]);
}
int main(){
    scanf("%d%d",&n,&m);
    REP(i,0,m){
        scanf("%d%d%d%d",&x,&y,&gcd[i],&lcm[i]);
        v[i][0]=x,v[i][1]=y;
        e[x].push_back(i);
        e[y].push_back(i);
    }
    solve();
}