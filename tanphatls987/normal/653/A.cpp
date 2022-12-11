#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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
const int N=1e3+10;

int n,a[N];
int main(){
//    freopen("input.inp","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    sort(a+1,a+n+1);
    n=unique(a+1,a+n+1)-a-1;
    FOR(i,1,n-2) if (a[i+2]-a[i]==2){
        printf("YES");
        return 0;
    }
    printf("NO");
}