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
const int N=10;

int h[10]={0},pr[4],c[4];
string s;
ll n;
void solve(){
    int m=s.length();
    REP(i,0,m) h[((s[i]=='B')?0:((s[i]=='C')?2:1))]++;
    m=3-count(h,h+3,0);
    ll ans=inf;
    FOR(i,0,2) if (h[i]) ans=min(ans,(1LL*c[i])/h[i]);
    FOR(i,0,2) if (h[i]) c[i]-=h[i]*ans;else c[i]=inf;
    //printf("%d %d %d\n",c[0],c[1],c[2]);
    while (1){
        int r[3],cost=0;
        FOR(i,0,2) if (h[i]) r[i]=max(h[i]-c[i],0),cost+=r[i]*pr[i];
        if (cost<=n){
            ans++;
            n-=cost;
            FOR(i,0,2) if (h[i]) c[i]+=r[i]-h[i];
        }else break;
        if (count(c,c+3,0)==m) break;
        //printf("%d %d %d\n",c[0],c[1],c[2]);
    }
    if (count(c,c+3,0)==m) ans+=n/(h[0]*pr[0]+h[1]*pr[1]+h[2]*pr[2]);
    cout<<ans;
}
int main(){
    cin>>s;
    FOR(i,0,2) cin>>c[i];
    FOR(i,0,2) cin>>pr[i];
    cin>>n;
    solve();
}