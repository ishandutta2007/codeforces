#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("F.inp","r",stdin)
#define OUTPUT freopen("F.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const ll inf=1e13;
const int MOD=1e9+7;
const int N=5e5+10;

ll f[2][N<<1],h[N],sum[N],p[N],ver[N];
int m1,m,n,k;
string s;
template <class T>
bool minimize(T &x,T y){
    if (x>y) x=y;else return 0;
    return 1;
}
void convert(int &x,int &y,char ch){
    if (ch=='R') y++;
    if (ch=='L') y--;
    if (ch=='U') x--;
    if (ch=='D') x++;
}
void prepare(){
    cin>>k>>n>>m>>s;
    FOR(i,0,1)
        fill(f[i],f[i]+N*2,inf);
    ///1st occur and full cycle move
    int fcx=0,fcy=0;
    f[0][N]=f[1][N]=0;
    REP(i,0,k){
        convert(fcx,fcy,s[i]);
        minimize(f[1][fcy+N],ll(i+1));
        minimize(f[0][fcx+N],ll(i+1));
    }

    ///minimize movement
    if (fcx>0){
        REP(i,fcx,N<<1) minimize(f[0][i],f[0][i-fcx]+k);
    }else{
        FORD(i,N*2-fcx-1,0) minimize(f[0][i],f[0][i-fcx]+k);
    }
    if (fcy>0){
        REP(i,fcy,N<<1) minimize(f[1][i],f[1][i-fcy]+k);
    }else{
        FORD(i,N*2+fcy-1,0) minimize(f[1][i],f[1][i-fcy]+k);
    }
    ///map possible state
    FOR(i,1,m) ver[i]=min(f[1][N-i],f[1][N+m-i+1]);
    FOR(i,1,m) p[i]=ver[i];
//    FOR(i,1,m) cout<<ver[i]<<" \n"[i==m];
    sort(p+1,p+m+1);
    m1=unique(p+1,p+m+1)-p-1;
    FOR(i,1,m) {
        int idx=lower_bound(p+1,p+m1+1,ver[i])-p;
        h[idx]++;
        sum[idx]=(sum[idx]+ver[i])%MOD;
    }
    FOR(i,1,m) h[i]+=h[i-1];
    FOR(i,1,m) sum[i]=(sum[i]+sum[i-1])%MOD;
}
ll solve(){
    ll ans=0;
    FOR(i,1,n){
        ll v=min(f[0][N-i],f[0][N+n-i+1]);
        if (v==inf&&p[m1]==inf) return -1;
        int cut=upper_bound(p+1,p+m1+1,v)-p-1;
        ans=(ans+(h[m1]-h[cut])*v+sum[cut])%MOD;
    }
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}