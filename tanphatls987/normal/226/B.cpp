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
const int N=1e5+10;

int n;
ll a[N],ans[N];
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%I64d",a+i);
    sort(a+1,a+n+1);
    FOR(i,1,n) a[i]+=a[i-1];
    REP(k,1,N){
        ll range=1,pos=n;
        while (1){
            pos-=range;
            if (pos<=0) break;
            ans[k]+=a[pos];
            range*=k;
        }
    }
    int test,x;
    scanf("%d",&test);
    while (test--){
        scanf("%d",&x);
        printf("%I64d ",ans[x]);
    }
}