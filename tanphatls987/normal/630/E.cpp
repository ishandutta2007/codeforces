#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("630.inp","r",stdin)
#define OUTPUT freopen("630.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9+2;
const int MOD=1e9+7;
const int N=0;
const int d[5]={0,2,4,3,1};

int main(){
    ll xa,ya,xb,yb;
    cin>>xa>>ya>>xb>>yb;
    xa+=inf,xb+=inf,ya+=inf,yb+=inf;
    ll ex=(xb-xa)/2+1,ox=xb-xa+1-ex;
    ll ey=(yb-ya)/2+1,oy=yb-ya+1-ey;
    cout<<ox*oy+ex*ey;
}