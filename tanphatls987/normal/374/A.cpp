#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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
const int N=0;

int xa,ya,da,db,n,m;
int shift(int x,int y){
    if (abs(x-xa)%da||abs(y-ya)%db) return inf;
    int sx=abs(x-xa)/da,sy=abs(y-ya)/db;
    if ((sx+sy)%2) return inf;
    if (x==xa&&y==ya) return 0;
    if (xa+da>n&&xa<=da) return inf;
    if (ya+db>m&&ya<=db) return inf;
    return max(sx,sy);
}
int main(){
    cin>>n>>m>>xa>>ya>>da>>db;
    int ans=min(min(min(shift(1,1),shift(1,m)),shift(n,m)),shift(n,1));
    if (ans==inf) cout<<"Poor Inna and pony!";
    else cout<<ans;
}