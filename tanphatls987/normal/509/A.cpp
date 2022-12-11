#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
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
const int N=200;

int n,a[N][N];
int main(){
    cin>>n;
    FOR(i,1,n) a[1][i]=a[i][1]=1;
    FOR(i,2,n)
        FOR(j,2,n) a[i][j]=a[i-1][j]+a[i][j-1];
    int ans=0;
    FOR(i,1,n)
        FOR(j,1,n) ans=max(ans,a[i][j]);
    cout<<ans;
}