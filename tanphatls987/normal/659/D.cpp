#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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
const int N=1e3+10;

int n;
ii a[N];
int operator %(ii a,ii b){
    return a.X*b.Y-a.Y*b.X;
}
ii operator -(ii a,ii b){
    return ii(a.X-b.X,a.Y-b.Y);
}
void prepare(){
    scanf("%d",&n);
    REP(i,0,n) scanf("%d%d",&a[i].X,&a[i].Y);
    a[n]=a[0];a[n+1]=a[1];
}
int solve(){
    int ans=0;
    FOR(i,1,n) if ((a[i]-a[i-1])%(a[i+1]-a[i-1])>0) ans++;
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}