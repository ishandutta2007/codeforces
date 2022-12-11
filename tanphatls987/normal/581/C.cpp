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

int n,k,a[N];
bool comp(int x,int y){
    return x%10>y%10;
}
int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    sort(a+1,a+n+1,comp);
    int rem=0,ans=0;
    FOR(i,1,n){
        ans+=a[i]/10;
        int v=10-a[i]%10;
        if (k>=v) ans++,k-=v,a[i]+=v;
        rem+=(100-a[i])/10;
    }
    ans+=min(k/10,rem);
    cout<<ans;
}