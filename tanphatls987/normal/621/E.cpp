#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
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
const int N=1e2+5;

int n2,n,m;
ll tmp[N],a[N],base[N];
void prepare(){
    int n1,x;
    scanf("%d%d%d%d",&n1,&m,&n2,&n);
    while (n1--){
        scanf("%d",&x);
        base[x%n]++;
    }
}
int solve(){
    a[0]=1;
    for(int p10=10%n;m;m>>=1,p10=p10*p10%n){
        if (m&1){
            REP(j,0,n) tmp[j]=a[j];
            memset(a,0,sizeof(a));
            REP(j,0,n)
                REP(k,0,n){
                    int nx=(j*p10+k)%n;
                    a[nx]=(a[nx]+tmp[j]*base[k])%MOD;
                }
        }
        REP(j,0,n) tmp[j]=base[j];
        memset(base,0,sizeof(base));
        REP(j,0,n)
            REP(k,0,n){
                int nx=(j*p10+k)%n;
                base[nx]=(base[nx]+tmp[j]*tmp[k])%MOD;
            }
    }
    return a[n2];
}
int main(){
    prepare();
    cout<<solve();
}