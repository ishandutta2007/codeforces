#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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

int ans[3],a[3][2],n;
int main(){
    cin>>n;
    FOR(i,0,2) cin>>a[i][0]>>a[i][1];
    FOR(i,0,2) n-=a[i][0],ans[i]=a[i][0];
    FOR(i,0,2) {
        int v=min(n,a[i][1]-a[i][0]);
        ans[i]+=v;
        n-=v;
    }
    FOR(i,0,2) printf("%d ",ans[i]);
}