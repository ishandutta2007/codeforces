#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("50c.inp","r",stdin)
#define OUTPUT freopen("50c.out","w",stdout)
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
const int N=0,BAR=1e6,LIM=5e6;

int x,y,n;
int main(){
    scanf("%d",&n);
    int xa=inf,xb=-inf,ya=inf,yb=-inf;
    while (n--){
        scanf("%d%d",&x,&y);
        x+=BAR,y+=BAR;
        xa=min(xa,x-y-1),xb=max(xb,x+y+1);
        ya=min(ya,x-(LIM-y+1)),yb=max(yb,x+(LIM-y+1));
    }
    int ans=0;
    int rya=(LIM-(yb-ya)/2);ans+=(yb-ya)%2;
    int ryb=(xb-xa)/2;ans+=(xb-xa)%2;
    ans+=2*(ryb-rya);
    cout<<ans;
}