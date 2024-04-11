#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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
const int N=1e6+10;

int ans[N],n;
int main(){
    cin>>n;
    for(int i=1,j=n,sel=1;i<j;i++,j--,sel+=2) ans[i]=ans[j]=sel;
    for(int i=n+1,j=2*n-1,sel=2;i<j;i++,j--,sel+=2) ans[i]=ans[j]=sel;
    FOR(i,1,n<<1) printf("%d ",ans[i]?ans[i]:n);
}