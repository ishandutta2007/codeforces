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
const int he[5]={0,2,6,12,20};

int a[N],n,m;
ll b[40][N],g[10][20];
void add(int type,int x,ll v){
    while (x<=n){
        b[type][x]+=v;
        x+=x&-x;
    }
}
ll get(int type,int x){
    ll ans=0;
    while (x){
        ans+=b[type][x];
        x-=x&-x;
    }
    return ans;
}
void modified(int x,int sign){
    FOR(j,2,6)
        REP(k,0,2*(j-1))
            add(he[j-2]+k,x,g[j-2][(x-k+2*(j-1))%(2*(j-1))]*a[x]*sign);
}
int main(){
    FOR(j,2,6){
        g[j-2][0]=2;
        REP(i,1,2*(j-1)) g[j-2][i]=(i<=j)?i:(2*j-i);
//        REP(i,0,2*(j-1)) printf("%lld ",g[j-2][i]);ENDL;
    }
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) modified(i,1);
    scanf("%d",&m);
    while (m--){
        int type,x,y,v;
        scanf("%d%d%d",&type,&x,&y);
        if (type==2){
            scanf("%d",&v);
            int bl=he[v-2]+(x-1)%(2*(v-1));
            printf("%I64d\n",get(bl,y)-get(bl,x-1));
        }else{
            modified(x,-1);
            a[x]=y;
            modified(x,1);
        }
//        FOR(i,1,n) cout<<a[i]<<" \n"[i==n];
    }
}