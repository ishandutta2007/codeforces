#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=1e5+10;

int g[N][10],t[N],n;
vector <int> v[N];
void prepare(){
    scanf("%d",&n);
    int x,y;
    FOR(i,1,n-1){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
int check(int x){
    if (g[x][5]) return -1;
    if (g[x][4]){
        if (g[x][4]>1) return -1;
        FOR(i,1,3) if (g[x][i]) return -1;
        if (g[x][0]>1) return -1;
        return 4+g[x][0];
    }
    if (g[x][3]>1) return -1;
    if (g[x][3]) {
        if (g[x][2]) return -1;
        if (g[x][0]>2) return -1;
        if (g[x][0]==2) return 5;
        return 4;
    }
    if (g[x][2]){
        if (g[x][2]>2) return -1;
        if (g[x][2]==2) return 3;
        return 2;
    }
    if (g[x][1]) return 2;
    if (g[x][0]>2) return 2;
    if (g[x][0]==2) return 1;
    return 0;
}
bool DFS(int par,int x){
    for(auto y:v[x]) if (y!=par){
        if (!DFS(x,y)) return 0;
        g[x][t[y]]++;
    }
    t[x]=check(x);
    if (t[x]==-1) return 0;
    return 1;
}
string solve(){
    if (!DFS(0,1)) return "No";
    return "Yes";
}
int main(){
    prepare();
    cout<<solve();
//    FOR(i,1,n) cout<<t[i]<<" \n"[i==n];
}