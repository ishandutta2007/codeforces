#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
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

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e6+10;

int n,x,y,ans[N],a[N],b[N];
int main(){
    memset(a,-1,sizeof(a));
    memset(b,-1,sizeof(b));
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%d",&x,&y);
        if (y==0) y=1000001;
        a[x]=y;
        b[y]=x;
    }
    for(int i=2,cur=a[0];i<=n;i+=2){
        ans[i]=cur;
        cur=a[cur];
    }
    int cur;
    FOR(i,1,1000000) if (b[i]==-1&&a[i]!=-1) cur=i;
    for(int i=1;i<=n;i+=2) ans[i]=cur,cur=a[cur];
    FOR(i,1,n) printf("%d ",ans[i]);
}