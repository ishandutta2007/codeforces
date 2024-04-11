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
typedef pair<double,int> di;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e2+10;

int a[N],n,xa,xb,ya,yb,ans[N][N];
bool inside(int x,int y){
    if (y<=ya) return (x>0&&x<=xa);
    return (x>0&&x<=xb);
}
void build(int t1,int cur,int x,int y){
    //printf("%d %d %d %d\n",t1,cur,x,y);
    if (cur>n) return;
    if (!a[cur]) {
        build(t1,cur+1,x,y);
        return;
    }
    if (!inside(x,y)) {
        build(-t1,cur,(x==0)?1:(y<=ya?xa:xb),y+1);
        return;
    }
    ans[x][y]=cur;
    a[cur]--;
    build(t1,cur,x+t1,y);

}
int main(){
    cin>>ya>>xa>>yb>>xb>>n;
    FOR(i,1,n) cin>>a[i];
    if (ya%2) build(-1,1,xa,1);
    else build(1,1,1,1);
    printf("YES\n");
    FOR(i,1,max(xa,xb)) {
        FOR(j,1,ya+yb) printf("%c",ans[i][j]?(ans[i][j]-1+'a'):'.');
        ENDL;
    }
}