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

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;

double solve(int x,int y){
    if (!y) return 1.0;
    if (x>4*y) return 1.0-(y+.0)/x;
    return (x+.0)/(y*16)+0.5;
}
int main(){
    int test,x,y;
    cin>>test;
    while (test--){
        cin>>x>>y;
        printf("%.9f\n",solve(x,y));
    }
}