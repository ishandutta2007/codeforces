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
const int N=1e5+10;

int n,a[N],f[2][N];
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) if (a[i]>f[0][i-1]) f[0][i]=f[0][i-1]+1;
    else f[0][i]=a[i];
    FORD(i,n,1) if (a[i]>f[1][i+1]) f[1][i]=f[1][i+1]+1;
    else f[1][i]=a[i];
    int ans=0;
    FOR(i,1,n) ans=max(ans,min(f[0][i],f[1][i]));
    cout<<ans;
}