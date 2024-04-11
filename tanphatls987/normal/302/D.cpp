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

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> li;

const int inf=1e16;
const int MOD=1e9+7;
const int N=1e2+10;

int n,m,w[N],d[N][N],h[N]={0},D;
ll f[N];
ii a[N];
void prepare(){
    scanf("%d%d",&n,&D);
    FOR(i,2,n-1) scanf("%d",&w[i]);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    FOR(i,1,n)
        FOR(j,1,n) d[i][j]=abs(a[i].X-a[j].X)+abs(a[i].Y-a[j].Y);
}
bool minimize(ll&a ,ll b){
    if (a>b)a=b;else return false;return true;
}
void solve(){
    priority_queue <li> q;
    q.push(li(0,1));
    FOR(i,2,n) f[i]=inf;
    while (!q.empty()){
        int x=q.top().Y;ll y=-q.top().X;
        //printf("%d %lld\n",x,y);
        q.pop();
        if (y>f[x]) continue;
        if (x==n) break;
        h[x]=1;
        FOR(i,2,n) if (h[i]==0&&minimize(f[i],y+(D*d[x][i]-w[x]))) q.push(ii(-f[i],i));
    }
    cout<<f[n];
}
int main(){
    prepare();
    solve();
}