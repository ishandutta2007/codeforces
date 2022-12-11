#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define MOD 1000000007
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define inf 1000000000

const int N=0;

typedef long long ll;

ll n,x,y,xa,ya;
bool change(ll a,ll b){
    if (a>=x&&b>=y) {xa=a;ya=b;return true;}
    if (a>=y&&b>=x) {xa=b;ya=a;return true;}
    return false;
}
void solve()
{
    ll s=1LL*inf*10;
    if (x*y>=6*n) {printf("%lld\n%lld %lld",x*y,x,y);return;}
    FOR(i,1,ceil(sqrt(6*n))){
        ll ny=(6*n+i-1)/i;
        if (i*ny<s) if (change(i,ny)) s=i*ny;
    }
    printf("%lld\n%lld %lld",s,xa,ya);
}
int main()
{
    cin>>n>>x>>y;
    solve();
}