#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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
const int N=0;

ll base[2][2]={{3,1},{1,3}},a[2][2]={{1,0},{0,1}},tmp[2][2];

int main(){
    ll n;
    cin>>n;
    while (n){
        if (n&1){
            FOR(i,0,1)
                FOR(j,0,1) tmp[i][j]=a[i][j];
            memset(a,0,sizeof(a));
            FOR(i,0,1)
                FOR(j,0,1)
                    FOR(k,0,1) a[i][j]=(a[i][j]+tmp[i][k]*base[k][j])%MOD;
        }
        FOR(i,0,1)
            FOR(j,0,1) tmp[i][j]=base[i][j];
        memset(base,0,sizeof(base));
        FOR(i,0,1)
            FOR(j,0,1)
                FOR(k,0,1) base[i][j]=(base[i][j]+tmp[i][k]*tmp[k][j])%MOD;
        n>>=1;
    }
    cout<<a[0][0];
}