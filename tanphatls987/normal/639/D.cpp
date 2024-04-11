#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const ll linf=1e18;
const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;

int n,k,c5,c1,a[N],L[5],R[5];
vector <int> v[5];
ll f[5][N];
template <class T>
bool maximize(T &x,T y){
    if (x<y) x=y;else return 0;
    return 1;
}
void prepare(){
    scanf("%d%d%d%d",&n,&k,&c5,&c1);
    c5=min(c5,c1*5);
    FOR(i,1,n) scanf("%d",a+i);
    sort(a+1,a+n+1);
    FOR(i,1,n) a[i]+=inf;
    FOR(i,1,n) v[a[i]%5].push_back(a[i]);
    FOR(i,0,4){
        int n1=v[i].size();
        FOR(j,1,n1) f[i][j]=f[i][j-1]+v[i][j-1];
    }
}

ll solve(){
    ll ans=linf;
    FOR(mod,0,4){
        int n1=0;
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        FOR(i,1,n){
            int cur=a[i]+(mod-a[i]%5+5)%5;
            FOR(pha,0,4)
                while (R[pha]<int(v[pha].size())&&v[pha][R[pha]]<=cur) R[pha]++,n1++;
            while (n1>k){
                int sel;
                ll wei=-1;
                FOR(pha,0,4) if (L[pha]<R[pha]){
                    int add=(mod-pha+5)%5;
                    ll cost=add*c1+1LL*(cur-add-v[pha][L[pha]])/5*c5;
                    if (maximize(wei,cost)) sel=pha;
                }
                L[sel]++;
                n1--;
            }
            if (n1>=k){
                ll cost=0;
                FOR(pha,0,4){
                    int add=(mod-pha+5)%5;
                    int len=R[pha]-L[pha];
                    cost+=1LL*len*add*c1+(1LL*len*(cur-add)-(f[pha][R[pha]]-f[pha][L[pha]]))/5*c5;
                }
//                cout<<cur<<" "<<cost<<" "<<n1<<'\n';
//                FOR(pha,0,4) cout<<L[pha]<<" "<<R[pha]<<'\n';
                ans=min(ans,cost);
            }
        }
    }
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}