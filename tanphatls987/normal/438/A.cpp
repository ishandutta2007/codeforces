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
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

const int inf=((1LL<<31)-1);
const int MOD=1e9+7;
const int N=1e3+10;

typedef long long ll;

int p[N],v[N],h[N]={0},n,m,x,y;
vector <int> a[N];
bool comp(int x,int y){
    return v[x]>v[y];
}
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&v[i]);
    FOR(i,1,n) p[i]=i;
    sort(p+1,p+n+1,comp);
    FOR(i,1,m) scanf("%d%d",&x,&y),a[x].push_back(y),a[y].push_back(x);
}
void solve(){
    ll ans=0;
    FOR(i,1,n){
        REP(j,0,a[p[i]].size()) if (h[a[p[i]][j]]==0) ans+=v[a[p[i]][j]];
        h[p[i]]=1;
    }
    cout<<ans;
}
int main()
{
    prepare();
    solve();
}