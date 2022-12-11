#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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
const int N=2e3+10,M=5e3+10;

int n,a[N];
ll way[M],sway[M];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    sort(a+1,a+n+1);
    FOR(i,1,n)
        REP(j,1,i) way[a[i]-a[j]]++;
    REP(j,1,M) sway[j]=sway[j-1]+way[j];
}
double solve(){
    double ans=0;
    REP(win,1,M){
        ll cur=0;
        REP(r1,1,win) cur+=way[r1]*sway[win-r1-1];
        ans+=(way[win]+.0)/(1LL*n*(n-1)/2)*((cur+.0)/(1LL*n*(n-1)*n*(n-1)/4));
    }
    return ans;
}
int main(){
    prepare();
    printf("%.12f",solve());
}