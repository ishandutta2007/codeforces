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
const int N=2e3+10;

int low[N],num[N],a[N][N],n,h[N],top;
stack <int> s;
vector <int> e[N];
void DFS(int x){
    static int c=0;
    s.push(x);
    num[x]=low[x]=++c;
    for(auto y:e[x]) if (num[y]>=0){
        if (num[y]==0) DFS(y);
        low[x]=min(low[x],low[y]);
    }
    if (low[x]>=num[x]){
        top++;
        while (s.top()!=x){
            num[s.top()]=-top;
            s.pop();
        }
        num[x]=-top;
        s.pop();
    }
}
string solve(){
    REP(i,0,n) if (!num[i]) DFS(i);
    return (top>1)?"NO":"YES";
}
int main(){
    scanf("%d",&n);
    REP(i,0,n)
        REP(j,0,n) scanf("%d",&a[i][j]);
    REP(i,0,n)
        REP(j,0,n) if (a[i][j]) e[i].push_back(j);
    cout<<solve();
}