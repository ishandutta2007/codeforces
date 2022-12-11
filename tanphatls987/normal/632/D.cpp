#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const int N=1e6+10;

int n,m,a[N],f[N];
vector <int> pos[N];
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) {
        scanf("%d",a+i);
        if (a[i]<=m) pos[a[i]].push_back(i);
    }
}
void solve(){
    FOR(i,1,m)
        for(int j=i;j<=m;j+=i) f[j]+=int(pos[i].size());
    int sel=max_element(f+1,f+m+1)-f;
    vector <int> ans;
    FOR(i,1,m) if (sel%i==0)
        for(auto j:pos[i]) ans.push_back(j);
    sort(ans.begin(),ans.end());
    printf("%d %d\n",sel,ans.size());
    for(auto i:ans) printf("%d ",i);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}