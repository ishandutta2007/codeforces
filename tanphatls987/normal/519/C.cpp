#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=100;

int n,m;
int main(){
    int ans=0;
    cin>>n>>m;
    FOR(x,0,(n+m)/3){
        int cn=n-x,cm=m-2*x;
        if (cn<0||cm<0) continue;
        ans=max(ans,x+min(cn/2,cm));
    }
    cout<<ans;
}