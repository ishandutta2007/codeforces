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
const int N=105;

int n,k,a[N];
int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",&a[i]);
    int diff=*max_element(a+1,a+n+1)-*min_element(a+1,a+n+1);
    if (diff>k){
        printf("NO");
        return 0;
    }
    printf("YES\n");
    diff=max(diff,1);
    FOR(i,1,n)
        REP(j,0,a[i]) cout<<j%diff+1<<" \n"[j==a[i]-1];
}