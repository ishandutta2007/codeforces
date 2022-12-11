#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int N=0;
const int iden[2][2]={{1,1},{1,0}};

int MOD,a[2][2],b[2][2],tmp[2][2];
ll L,R,n;

bool check(ll sel){
    return R/sel-L/sel>=n;
}
int fibo(ll sel){
    FOR(i,0,1) a[i][i]=1;
    FOR(i,0,1)
        FOR(j,0,1) b[i][j]=iden[i][j];
    while (sel){
        if (sel&1){
            FOR(i,0,1)
                FOR(j,0,1) tmp[i][j]=a[i][j];
            memset(a,0,sizeof(a));
            FOR(i,0,1)
                FOR(j,0,1)
                    FOR(k,0,1) a[i][j]=(a[i][j]+1LL*tmp[i][k]*b[k][j])%MOD;
        }
        FOR(i,0,1)
            FOR(j,0,1) tmp[i][j]=b[i][j];
        memset(b,0,sizeof(b));
        FOR(i,0,1)
            FOR(j,0,1)
                FOR(k,0,1) b[i][j]=(b[i][j]+1LL*tmp[i][k]*tmp[k][j])%MOD;
        sel>>=1;
    }
//    FOR(i,0,1)
//        FOR(j,0,1) cout<<a[i][j]<<" \n"[j==1];
    return a[0][1];
}
int main(){
    cin>>MOD>>L>>R>>n;
    L--;
    ll sel=0;
    FOR(i,1,int(sqrt(L))) if (check(L/i)) sel=max(sel,L/i);
    FOR(i,1,int(sqrt(R))){
        if (check(i)) sel=max(sel,ll(i));
        if (check(R/i)) sel=max(sel,R/i);
    }
    cout<<fibo(sel);
}