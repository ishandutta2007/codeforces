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
#define inf 1000000

const int MOD=1000000007;
const int N=100010;

typedef long long ll;
typedef pair<int,int> ii;

int n,r[2],v,h[N],f[N][2]={0};
ii a[N];
bool wrong;
void prepare(){
    scanf("%d%d%d",&n,&r[0],&r[1]);
    FOR(i,1,n) scanf("%d",&v),a[i]=ii(v,i);
    sort(a+1,a+n+1);
}
void DFS(int flag,int idx){
    if (f[idx][flag]==0) {wrong=true;return;}
    h[idx]=flag;
    FOR(i,0,1) if (f[idx][i]){
        if (h[f[idx][i]]!=-1&&h[f[idx][i]]!=flag) {wrong=true;return;}
        if (h[f[idx][i]]==-1) DFS(flag,f[idx][i]);
    }
}
void solve(){
    FOR(j,0,1){
        int L=1,R=n;
        while (L<=R){
            if (a[L].X+a[R].X==r[j]){
                f[a[L].Y][j]=a[R].Y;
                f[a[R].Y][j]=a[L].Y;
                L++;R--;
            }else if (a[L].X+a[R].X<r[j]) L++;
            else R--;
        }
    }
    memset(h,-1,sizeof(h));
    wrong=false;
    FOR(i,1,n) if (h[i]==-1&&(f[i][0]==0||f[i][1]==0))
        if (f[i][0]) DFS(0,i);else DFS(1,i);
    FOR(i,1,n) if (h[i]==-1) DFS(0,i);
    if (wrong) {printf("NO");return;}
    printf("YES\n");
    FOR(i,1,n) printf("%d ",h[i]);
}
int main(){
    prepare();
    solve();
}