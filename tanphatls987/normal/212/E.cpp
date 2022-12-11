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
const int N=5e3+10;

int h[N][N],n,x,y,subt[N];
vector <int> v[N];
void DFS(int par,int x){
    h[0][x]=1;
    subt[x]=1;
    for(auto y:v[x]) if (y!=par){
        DFS(x,y);
        FORD(i,n,subt[y]) h[i][x]|=h[i-subt[y]][x];
        subt[x]+=subt[y];
    }
    int tmp=n-subt[x];
    FORD(i,n,tmp) h[i][x]|=h[i-tmp][x];
}
int main(){
    scanf("%d",&n);
    FOR(i,2,n) {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(0,1);
    vector <int> ans;
    FOR(i,1,n-2) if (count(h[i]+1,h[i]+n+1,1)) ans.push_back(i);
    printf("%d\n",ans.size());
    for(auto i:ans) printf("%d %d\n",i,n-i-1);
}