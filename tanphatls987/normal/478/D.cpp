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

const int inf=2e9;
const int MOD=1e9+7;
const int N=2e5+10;

int n,m,f[N]={0};
void solve(){
    int h=0;
    while (((h+2)*(h+1))/2<=n+m) h++;
    int block=(h*(h+1))/2;
    f[0]=1;
    FOR(i,1,h)
        FORD(j,n,i) f[j]=(f[j]+f[j-i])%MOD;
    ll ans=0;
    //cout<<block;
    //FOR(i,1,n) printf("%d ",f[i]);
    FOR(i,max(block-m,0),n) ans=(ans+f[i])%MOD;
    cout<<ans;
}
int main(){
    cin>>n>>m;
    if (n>m) swap(n,m);
    solve();
}