#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
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


ll y,x,m;
ll solve(){
    if (x<m&&y<m&&x<=0&&y<=0) return -1;
    if (x<y) swap(x,y);
    if (x>=m) return 0;
    ll ans=0;
    if (y<0){
        ans=(-y+x-1)/x;
        y+=ans*x;
    }
    while (x<m){
        ans++;
        ll tmp=x;
        x+=y;y=tmp;
    }
    return ans;
}
int main(){
    cin>>x>>y>>m;
    cout<<solve();

}