#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("628.inp","r",stdin)
#define OUTPUT freopen("628.out","w",stdout)
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
const int N=2e3+10;

int m,spe,f[2][2][N];
string s1,s2;
bool check(int odd,int x){
    if (odd) return x!=spe;
    return x==spe;
}
int solve(string s,int type){
    int n=s.length();
    int cmod=(s[0]-'0')%m;
    bool ok=check(1,s[0]-'0');
    memset(f,0,sizeof(f));
    REP(i,1,s[0]-'0') f[1][1][i%m]+=check(1,i);
//    cout<<s<<" "<<type<<" "<<cmod<<" "<<ok<<'\n';
//    REP(i,0,m) cout<<f[1][1][i%m]<<" ";
//    ENDL;
    FOR(pha,2,n){
        int cur=pha&1,last=cur^1;
        memset(f[cur],0,sizeof(f[cur]));
        FOR(i,1,9) f[cur][1][i%m]+=check(1,i);
        if (ok){
            REP(i,0,s[pha-1]-'0') if (check(cur,i)) f[cur][cur][(cmod*10+i)%m]=(f[cur][cur][(cmod*10+i)%m]+1)%MOD;
        }
        FOR(type,0,1)
            REP(j,0,10) if (check(type,j))
                REP(i,0,m){
                    int nx=(i*10+j)%m;
                    f[cur][type][nx]=(f[cur][type][nx]+f[last][type^1][i])%MOD;
                }
        ok&=check(cur,s[pha-1]-'0');
        cmod=(cmod*10+s[pha-1]-'0')%m;
    }
    return (f[n&1][0][0]+f[n&1][1][0]+(type&&ok&&cmod==0))%MOD;
}
int main(){
    cin>>m>>spe>>s1>>s2;
    cout<<(solve(s2,1)-solve(s1,0)+MOD)%MOD;
}