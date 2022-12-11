#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
#include <map>

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
const int N=3e3+10;

map <ii,int> ma[N];
int n,m,k,x,y,z,t[N][N]={0};
vector <int> a[N];
void prepare(){
    scanf("%d%d%d",&n,&m,&k);
    while (m--){
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    while (k--){
        scanf("%d%d%d",&x,&y,&z);
        ma[y][ii(z,x)]=1;
    }
}
int BFS(){
    queue <ii> q;
    q.push(ii(n+1,n));
    t[n+1][n]=-1;
    while (!q.empty()){
        int cx=q.front().Y,lx=q.front().X;
        //printf("%d %d %d\n",lx,cx,t[lx][cx]);
        q.pop();
        if (cx==1) return lx;
        for(auto &nx:a[cx]) if (!ma[cx][ii(lx,nx)]&&!t[cx][nx])
            t[cx][nx]=lx,q.push(ii(cx,nx));
    }
    return 0;
}
void solve(){
    int y=BFS(),x=1;
    if (!y) {printf("-1");return;}
    //printf("%d %d\n",x,y);
    vector <int> ans;
    while (x<=n){
        //printf("%d %d\n",x,y);
        ans.push_back(x);
        int tmp=y;
        y=t[y][x];x=tmp;
    }
    printf("%d\n",ans.size()-1);
    for(auto &i:ans) printf("%d ",i);
}
int main(){
    prepare();
    solve();
}