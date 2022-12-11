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
const int N=23;

int n,a[N],f[2][1<<N];
vector <ii> e[N];
bool minimize(int &x,int y){
    if (x>y) x=y;else return false;
    return true;
}
int solve(){
    REP(i,0,n) if (a[i]%a[0]) return -1;
    FORD(i,n-1,0) a[i]/=a[0];
    REP(i,1,n)
        REP(j,0,i)
            REP(k,j,i) if (a[k]+a[j]==a[i]) e[i].push_back(ii(j,k));
    f[0][0]=1;
    REP(k,0,n-1){
        int next=(k&1)^1;
//        printf("%d %d\n",k&1,next);
        REP(j,0,1<<(k+1)) f[next][j]=inf;
        REP(j,0,1<<k) if (f[k&1][j]<inf){
            int idx=j+(1<<k);
//            printf("%d %d %d\n",k,idx,f[k&1][j]);
            bool ok=0;
            for(auto i:e[k+1]) if ((idx&(1<<i.X))&&(idx&(1<<i.Y))) ok=1;
            if (ok){
                FOR(i,0,k) if (idx&(1<<i)) minimize(f[next][idx^(1<<i)],f[k&1][j]);
                minimize(f[next][idx],f[k&1][j]+1);
            }
        }
    }
    return *min_element(f[(n-1)&1],f[(n-1)&1]+(1<<(n-1)));
}
int main(){
    cin>>n;
    REP(i,0,n) cin>>a[i];
    cout<<solve();
}