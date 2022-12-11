#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("625.inp","r",stdin)
#define OUTPUT freopen("625.out","w",stdout)
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

int main(){
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=n*n-(n-k+1),pha=1;pha<=n;i-=n-k+1,pha++) ans+=i+1;
    printf("%d\n",ans);
    for(int pha=1,L=1,R=n*n;pha<=n;pha++){
        REP(i,1,k) printf("%d ",L++);
        R-=n-k+1;
        FOR(i,1,n-k+1) printf("%d ",R+i);
        ENDL;
    }
}