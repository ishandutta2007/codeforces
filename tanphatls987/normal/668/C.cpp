#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const int N=1e5+10;

int n;
double pmin[N],pmax[N],ans[2][N];
void prepare(){
    cin>>n;
    FOR(i,1,n) cin>>pmax[i];
    FOR(i,1,n) cin>>pmin[i];
    FOR(i,1,n) pmax[i]+=pmax[i-1];
    FOR(i,1,n) pmin[i]+=pmin[i-1];
}
double cal(double b,double c){
    double delta=max(b*b-4*c,0.0);
    return (-b+sqrt(delta))/2;
}
void solve(){
    FOR(i,1,n){
        double P=pmin[i]+pmax[i];
        double S=pmax[i];
//        cout<<i<<" "<<P<<" "<<S<<'\n';
        ans[1][i]=cal(-P,S);
        ans[0][i]=P-ans[1][i];
    }
    FOR(i,0,1)
        FOR(j,1,n) cout<<ans[i][j]-ans[i][j-1]<<" \n"[j==n];
}
int main(){
//    freopen("input.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prepare();
    solve();
}