#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
#include <map>

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
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,r;
ii a[N];
ll ave;
void prepare(){
    scanf("%d%d%lld",&n,&r,&ave);
    FOR(i,1,n) scanf("%d%d",&a[i].Y,&a[i].X);
    ave*=n;
    sort(a+1,a+n+1);
}
void solve(){
    ll sum=0,ans=0;
    FOR(i,1,n) sum+=a[i].Y;
    for(int i=1;sum<ave&&i<=n;i++){
        ll v=min(ave-sum,1LL*r-a[i].Y);
        sum+=v;
        ans+=v*a[i].X;
    }
    cout<<ans;
}
int main(){
    prepare();
    solve();
}