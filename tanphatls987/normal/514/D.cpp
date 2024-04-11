#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("d.inp","r",stdin)
#define OUTPUT freopen("d.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,m,k,a[N][6],f[N][6][20],ans[6];
int query(int type,int L,int R){
    int bar=int(log2(R-L+1));
    return max(f[L][type][bar],f[R-(1<<bar)+1][type][bar]);
}
bool check(int M){
    FOR(i,1,n-M+1){
        int v=0;
        REP(j,0,m) v+=query(j,i,i+M-1);
        if (v<=k) return true;
    }
    return false;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n)
        REP(j,0,m) scanf("%d",&f[i][j][0]);
    REP(j,0,m)
        FOR(i1,1,18){
            int bar=1<<i1;
            FOR(i,1,n-bar+1) f[i][j][i1]=max(f[i][j][i1-1],f[i+bar/2][j][i1-1]);
        }
    int L=1,R=n;
    while (L<=R){
        int M=(L+R)/2;
        if (check(M)) L=M+1;
        else R=M-1;
    }
    if (R){
        FOR(i,1,n-R+1){
            int v=0;
            REP(j,0,m) ans[j]=query(j,i,i+R-1),v+=ans[j];
            if (v<=k) break;
        }
    }
    //printf("%d\n",R);
    REP(i,0,m) printf("%d ",ans[i]);
}