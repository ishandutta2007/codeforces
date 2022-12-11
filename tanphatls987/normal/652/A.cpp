#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("mdraft.inp","r",stdin)
#define OUTPUT freopen("mdraft.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;

int h1,h2,up,down;
int solve(){
    int d=h2-h1-8*up;
    if (d<=0) return 0;
    if (down>=up) return -1;
    int inc=(up-down)*12;
    return (d+inc-1)/inc;
}
int main(){
//    freopen("input.inp","r",stdin);
    cin>>h1>>h2>>up>>down;
    cout<<solve();
}