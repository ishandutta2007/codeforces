#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> lli;
const ll inf=1e18;
const int MOD=1e9+7;
const int N=3e5+10;

lli a[N];
ll f[2][N];
int n,m;
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) {scanf("%I64d",&a[i].X),a[i].Y=i;}
    scanf("%d",&m);
    sort(a+1,a+n+1);
}
void solve(){
    ll sum=0;
    a[n+1].X=a[n].X;
    FOR(i,1,n){
        sum+=a[i].X;
        if (i>=m){
            f[0][i-m+1]=sum-a[i-m+1].X*m;
            sum-=a[i-m+1].X;
        }
    }
    sum=0;
    FOR(i,1,n){
        if (i>m) sum-=a[i-m].X;
        f[1][i]=min(i-1,m-1)*a[i].X-sum;
        sum+=a[i].X;
    }
    ll ans=-1;sum=0;
    int idx=0;
    FOR(i,1,n){
        sum+=f[1][i];
        if (i>=m){
            sum-=f[0][i-m];
            //printf("%lld ",sum);
            if (ans==-1||ans>sum){
                ans=sum;
                idx=i-m+1;
            }
        }
    }
    //FOR(i,1,n) printf("%lld ",f[1][i]);
    REP(i,idx,idx+m) printf("%d ",a[i].Y);
}
int main(){
    prepare();
    solve();
}