#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("514e.inp","r",stdin)
#define OUTPUT freopen("514e.out","w",stdout)
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
const int N=1e2+1;

int n,M,x,h[N]={0},A[N][N],base[N][N],tmp[N][N],g[N]={0};
int main(){
    scanf("%d%d",&n,&M);
    while (n--){
        scanf("%d",&x);
        h[x]++;
    }
    g[0]=1;
    FOR(i,0,100)
        FOR(j,1,100-i) g[i+j]=(g[i+j]+1LL*g[i]*h[j])%MOD;
    if (M<=100){
        int ans=0;
        FOR(i,0,M) ans=(ans+g[i])%MOD;
        cout<<ans;
        return 0;
    }
    FOR(i,0,99) g[i]=g[i+1];
    //init base matrix
    g[100]=1;
    FOR(i,0,98) g[100]=(g[100]+g[i])%MOD;
    FOR(i,0,98) base[i+1][i]=1;
    FOR(i,0,99) base[i][99]=h[100-i];
    base[100][100]=base[99][100]=1;
    //----------------------------
    M-=99;
    stack <int> S;
    while (M) S.push(M%2),M>>=1;
    FOR(i,0,100)
        FOR(j,0,100) A[i][j]=base[i][j];
    while (1){
        //cur=cur*2+S.top();
        S.pop();
        if (S.empty()) break;
        if (!S.top()){
            FOR(i,0,100)
                FOR(j,0,100) tmp[i][j]=A[i][j];
            memset(A,0,sizeof(A));
            FOR(i,0,100)
                FOR(j,0,100)
                    FOR(k,0,100) A[i][j]=(A[i][j]+1LL*tmp[i][k]*tmp[k][j])%MOD;
        }else{
            memset(tmp,0,sizeof(tmp));
            FOR(i,0,100)
                FOR(j,0,100)
                    FOR(k,0,100) tmp[i][j]=(tmp[i][j]+1LL*A[i][k]*A[k][j])%MOD;
            memset(A,0,sizeof(A));
            FOR(i,0,100)
                FOR(j,0,100)
                    FOR(k,0,100) A[i][j]=(A[i][j]+1LL*tmp[i][k]*base[k][j])%MOD;
        }
    }
    //cout<<cur<<'\n';
    //FOR(i,0,100) cout<<i<<" "<<g[i]<<'\n';
    int ans=0;
    FOR(i,0,100) ans=(ans+1LL*g[i]*A[i][100])%MOD;
    cout<<ans;
    //----------------------------
}