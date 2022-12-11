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
const int N=2e3+10;

string s;
int n,k,col[N],f[N][N]={0};
int solve(){
    f[0][0]=col[0]=1;
    FOR(i,1,n){
        int x=s[i-1]-'a';
        FORD(j,k,0){
            f[i][j]=1LL*x*col[j]%MOD;
            FOR(j1,1,i){
                if (j-j1*(n-i+1)<0) break;
                f[i][j]=(f[i][j]+1LL*(25-x)*f[i-j1][j-j1*(n-i+1)])%MOD;
            }
//            printf("%d %d %d\n",i,j,f[i][j]);
//            g[j-i]=(g[j-i]+v)%MOD;
            col[j]=(col[j]+f[i][j])%MOD;
        }
//        FOR(j,-k,0) cout<<g[j]<<" ";ENDL;
//        FOR(j,0,k) cout<<g[j]<<" ";ENDL;
//        FOR(j,0,k) cout<<col[j]<<" ";ENDL;
    }
    return col[k];
}
int main(){
//    INPUT;
    cin>>n>>k>>s;
    cout<<solve();
}