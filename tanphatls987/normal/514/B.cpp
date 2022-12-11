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
const int N=1e3+10;

int n,x,y,h[N]={0};
ii a[N];
bool comp(ii a,ii b){
    return ((a.Y-y)*(b.X-x)<(b.Y-y)*(a.X-x));
}
int main(){
    scanf("%d%d%d",&n,&x,&y);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    int ans=0;
    FOR(i,1,n) if (!h[i]){
        ans++;
        FOR(j,1,n) if (!h[j]&&(a[j].Y-y)*(a[i].X-x)==(a[i].Y-y)*(a[j].X-x)) h[j]=1;
    }
    cout<<ans;
}