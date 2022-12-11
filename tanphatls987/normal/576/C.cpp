#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0,M=1e3+5;

vector <ii> g[M];
int main(){
    int n,x,y;
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%d",&x,&y);
        g[x/1000].push_back(ii(y,i));
    }
    REP(i,0,M-1){
        sort(g[i].begin(),g[i].end());
//        cout<<g[i].size()<<'\n';
        if (i&1) for(auto j:g[i]) printf("%d ",j.Y);
        else FORD(j,int(g[i].size())-1,0) printf("%d ",g[i][j].Y);
    }
}