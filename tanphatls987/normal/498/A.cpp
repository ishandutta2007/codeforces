#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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

int sign(ll x){
    return abs(x)/x;
}
ll cal(int a,int b,int c,int x,int y){
    return 1LL*a*x+1LL*b*y+c;
}
int main(){
    int xa,ya,xb,yb,n;
    cin>>xa>>ya>>xb>>yb;
    cin>>n;
    int ans=0;
    while (n--){
        int a,b,c;
        cin>>a>>b>>c;
        if (sign(cal(a,b,c,xa,ya))*sign(cal(a,b,c,xb,yb))<0) ans++;
    }
    cout<<ans;
}