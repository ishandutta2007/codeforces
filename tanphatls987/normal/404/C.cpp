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
#define wreck {printf("-1");return;}

const int inf=((1LL<<31)-1);
const int MOD=1e9+7;
const int N=1e5+10;

typedef long long ll;
typedef pair<int,int> ii;

int n,k,v;
vector <int> a[N];
vector <ii> ans;
void prepare(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",&v),a[v].push_back(i);
}
void solve(){
    if (a[0].size()!=1) wreck;
    REP(i,1,n) if (a[i].size()>0) {
        int bar=0,cap=(i>1);
        if (a[i].size()>1LL*(k-(i>1))*a[i-1].size()) wreck;
        REP(j,0,a[i].size()){
            if (cap==k) bar++,cap=(i>1);
            ans.push_back(ii(a[i-1][bar],a[i][j]));
            cap++;
        }
    }
    printf("%d\n",ans.size());
    REP(i,0,ans.size()) printf("%d %d\n",ans[i].X,ans[i].Y);
}
int main(){
    prepare();
    solve();
}