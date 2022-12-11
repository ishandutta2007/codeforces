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
const int N=20,M=9,K=2520;

ll f[N][50][K],p10[N];
int lcm[1<<M],flag[K+10],tran[50][10];
void prepare(){
    REP(i,0,1<<M){
        lcm[i]=1;
        REP(j,0,M) if (i&(1<<j)) lcm[i]=lcm[i]*(j+1)/__gcd(lcm[i],j+1);
    }
    sort(lcm,lcm+(1<<M));
    int m=unique(lcm,lcm+(1<<M))-lcm;
    REP(i,0,m) flag[lcm[i]]=i;
    REP(i,0,m) {
        tran[i][0]=i;
        FOR(k,1,9) tran[i][k]=flag[lcm[i]*k/__gcd(lcm[i],k)];
    }
    p10[0]=1;
    FOR(i,1,18) p10[i]=10*p10[i-1];
}
int len(ll x){
    int ans=0;
    while (x) ans++,x/=10;
    return ans;
}
ll solve(ll x){
    int dig=len(x);
    ll tmp=x;
    memset(f[dig],0,sizeof(f[dig]));
    int cmod=0,cset=0;
    FORD(cur,dig-1,0){
        memset(f[cur],0,sizeof(f[cur]));
        REP(i,0,48)
            REP(j,0,K) if (f[cur+1][i][j])
                FOR(use,0,9){
                    int ni=tran[i][use],nj=(j+p10[cur]*use)%K;
                    f[cur][ni][nj]+=f[cur+1][i][j];
                }
        int cx=tmp/p10[cur];
        tmp-=cx*p10[cur];
        REP(use,0,cx){
            int ni=tran[cset][use],nj=(cmod+p10[cur]*use)%K;
            f[cur][ni][nj]++;
        }
        cmod=(cmod+p10[cur]*cx)%K;
        cset=tran[cset][cx];
    }
    ll ans=0;
    REP(i,0,48)
        for(int j=0;j<K;j+=lcm[i]) ans+=f[0][i][j];
    return ans;
}
int main(){
    prepare();
    int test;
    cin>>test;
    while (test--){
        ll x,y;
        cin>>x>>y;
        cout<<solve(y+1)-solve(x)<<'\n';
    }
}