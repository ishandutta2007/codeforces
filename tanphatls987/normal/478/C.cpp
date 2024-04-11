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
const int N=0;

ll a[3];
void solve(){
    ll scale=a[2]-a[1],take=min(scale/2,a[0]);
    a[0]-=take;
    a[2]-=2*take;
    ll ans=take;
    if (a[0]) ans+=(a[0]+a[1]+a[2])/3;
    else {
        if (a[1]*2<=a[2]) ans+=a[1];
        else ans+=(a[1]+a[2])/3;
    }
    cout<<ans;
}
int main(){
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    solve();
}