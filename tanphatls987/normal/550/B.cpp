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
const int N=18;

int n,L,R,x,d[N];
int main(){
    cin>>n>>L>>R>>x;
    REP(i,0,n) cin>>d[i];
    int ans=0;
    REP(i,1,1<<n){
        int sum=0,rL=inf,rR=0;
        REP(j,0,n) if (i&(1<<j)){
            sum+=d[j];
            rL=min(rL,d[j]);
            rR=max(rR,d[j]);
        }
        //printf("%d %d %d %d\n",i,sum,rL,rR);
        if ((i-(i&-i))&&sum>=L&&sum<=R&&rR-rL>=x) ans++;
    }
    cout<<ans;
}