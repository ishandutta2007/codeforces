#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=2e5+10;

int n,a[N],p[N],f[N],link[N][2];
vector <int> b[N];
void set_link(int x,int y){
    link[x][1]=y;
    link[y][0]=x;
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) p[i]=a[i];
    sort(p+1,p+n+1);
    int m=unique(p+1,p+n+1)-p-1;
    FOR(i,1,n) b[lower_bound(p+1,p+m+1,a[i])-p].push_back(i);
    int range=0;
    FOR(i,0,n) set_link(i,i+1);
    f[0]=p[m];
    FORD(i,m,0){
        for(auto x:b[i]) {
            set_link(link[x][0],link[x][1]);
            range=max(range,link[x][1]-link[x][0]-1);
        }
        if (!f[range]) f[range]=p[i];
    }
    FORD(i,n,1) if (!f[i]) f[i]=f[i+1];
    FOR(i,1,n) printf("%d ",f[i]);
}