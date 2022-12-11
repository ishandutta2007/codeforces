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
const int N=1e5+10;

int n,a[N],f[N];
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    a[n+1]=f[n+1]=-1;
    FORD(i,n,1) f[i]=max(f[i+1],a[i]);
    FOR(i,1,n) printf("%d ",max(f[i+1]+1-a[i],0));
}