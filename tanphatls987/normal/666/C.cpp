#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=2e5+10,M=500;

map <int,int> ma;
ll rev[N],revfac[N],fac[N];
ll pb26[2][N];
vector<vector<int>> f;
ll C(int x,int y){
    if (y<0||y>x) return 0;
    return fac[x]*revfac[y]%MOD*revfac[x-y]%MOD;
}
void prepare(){
    fac[0]=1;
    REP(i,1,N) fac[i]=fac[i-1]*i%MOD;
    rev[1]=1;
    REP(i,2,N) rev[i]=MOD-(MOD/i)*rev[MOD%i]%MOD;
    revfac[0]=1;
    REP(i,1,N) revfac[i]=revfac[i-1]*rev[i]%MOD;
    FOR(i,0,1){
        pb26[i][0]=1;
        REP(j,1,N) pb26[i][j]=pb26[i][j-1]*(26-i)%MOD;
    }
}
int solve(int n1,int n){
    static int m=0;
    if (n<n1) return 0;
    if (ma[n1])
        return f[ma[n1]-1][n-n1];
    ma[n1]=++m;
    f.push_back({});
    f[m-1].resize(100001-n1);
    f[m-1][0]=1;
    FOR(i,1,100000-n1) f[m-1][i]=(f[m-1][i-1]*26LL+C(i+n1-1,n1-1)*pb26[1][i])%MOD;
    return f[m-1][n-n1];
}
int main(){
//    freopen("input.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prepare();
    int test,type,n,n1;
    string s;
    cin>>test>>s;
    n1=s.length();
    while (test--){
        cin>>type;
        if (type==1) {
            cin>>s;
            n1=s.length();
        }else{
            cin>>n;
            cout<<solve(n1,n)<<'\n';
        }
    }
}