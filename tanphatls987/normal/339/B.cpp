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

int n,m,x;
int main(){
    scanf("%d%d",&n,&m);
    int cur=1;
    ll ans=0;
    while (m--){
        scanf("%d",&x);
        if (x>=cur) ans+=x-cur;
        else ans+=n-cur+x;
        cur=x;
    }
    cout<<ans;
}