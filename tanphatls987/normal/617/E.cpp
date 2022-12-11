#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("340.inp","r",stdin)
#define OUTPUT freopen("340.out","w",stdout)
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
const int N=1e5+10,M=1<<20,blk=int(sqrt(N));

int n,m,k,a[N],h[M];
ll ans[N];
struct query{
    int L,R,idx;
    query (int _L=0,int _R=0,int _idx=0){
        L=_L;R=_R;idx=_idx;
    }
};
bool comp(query a,query b){
    return a.R<b.R;
}
vector <query> qu[N/blk+5];
void prepare(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,m){
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        qu[x/blk].push_back(query(x,y,i));
    }
    FOR(i,1,n) {
        a[i]^=a[i-1];
        assert(a[i]<M);
    }
    FOR(i,0,n/blk) sort(qu[i].begin(),qu[i].end(),comp);
//    FOR(i,1,n) cout<<a[i]<<" \n"[i==n];
}
ll build(query cur){
    ll cans=0;
    FOR(i,cur.L,cur.R){
        cans+=h[a[i]^k];
        h[a[i]]++;
    }
    ans[cur.idx]=cans;
    return cans;
}
void modifiedL(ll &cans,int cur,int tar){
    if (cur>tar){
        FORD(i,cur-1,tar){
            cans+=h[a[i]^k];
            h[a[i]]++;
        }
        return;
    }
    REP(i,cur,tar){
        h[a[i]]--;
        cans-=h[a[i]^k];
    }
}
void modifiedR(ll &cans,int cur,int tar){
    FOR(i,cur+1,tar){
        cans+=h[a[i]^k];
        h[a[i]]++;
    }
}
void solve(){
    FOR(pha,0,n/blk) if (!qu[pha].empty()){
        ll cans=build(qu[pha][0]);
        int n1=qu[pha].size();
//        cout<<qu[pha][0].L<<" "<<qu[pha][0].R<<'\n';
//        FOR(i,0,10) cout<<h[i]<<" \n"[i==10];
        REP(i,1,n1){
            modifiedL(cans,qu[pha][i-1].L,qu[pha][i].L);
            modifiedR(cans,qu[pha][i-1].R,qu[pha][i].R);
            ans[qu[pha][i].idx]=cans;
        }
        FOR(i,qu[pha][n1-1].L,qu[pha][n1-1].R) h[a[i]]--;
    }
    FOR(i,1,m) printf("%lld\n",ans[i]);
}
int main(){
    prepare();
    solve();
}