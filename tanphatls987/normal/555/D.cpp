#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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
const int N=2e5+10;

int n,m,x,y,a[N],p[N],pos[N];
int compidx(int x,int y){
    return a[x]<a[y];
}
int solve(int x,int v){
    x=pos[x];
    while (1){
        int v1=0;
        int y=upper_bound(a+x,a+n+1,a[x]+v)-a-1;
        v1+=a[y]-a[x];
        int z=lower_bound(a+1,a+y+1,a[y]-v+v1)-a;
        v1+=a[y]-a[z];
        if (!v1) break;
        if (z==x) {
            v%=v1;
            continue;
        }
        v-=v1;
        x=z;
    }
    return p[x];
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) p[i]=i;
    sort(p+1,p+n+1,compidx);
    FOR(i,1,n) pos[p[i]]=i;
    sort(a+1,a+n+1);
    while (m--){
        scanf("%d%d",&x,&y);
        printf("%d\n",solve(x,y));
    }
}