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

int ans[N],a[N],n,p[N];
bool comp(int x,int y){
    return a[x]<a[y];
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) p[i]=i;
    a[0]=-2;
    sort(p+1,p+n+1,comp);
    int dis=(n+2)/3,rem=n-(2*dis+1);
    FOR(i,2,dis+1) ans[p[i]]=a[p[i]];
    REP(i,0,rem) ans[p[n-i]]=a[p[n-i]]-(i+1);
    printf("YES\n");
    FOR(i,1,n) printf("%d ",ans[i]);ENDL;
    FOR(i,1,n) printf("%d ",a[i]-ans[i]);
}