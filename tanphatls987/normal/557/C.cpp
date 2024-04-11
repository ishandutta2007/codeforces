#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=1e5+10,M=2e2+10;

int n,sum[N],h[M];
ii a[N];
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i].X);
    FOR(i,1,n) scanf("%d",&a[i].Y);
    sort(a+1,a+n+1);
    FORD(i,n,1) sum[i]=sum[i+1]+a[i].Y;
    int ans=inf;
    FOR(i,1,n){
        int j=i;
        while (i<n&&a[i+1].X==a[i].X) i++;
        int out=max(0,i-(i-j+1)*2+1),cur=0;
//        cout<<i<<" "<<out<<'\n';
        FOR(k,1,200){
            int v=min(out,h[k]);
            cur+=v*k;
            out-=v;
        }
        FOR(k,j,i) h[a[k].Y]++;
        ans=min(ans,sum[i+1]+cur);
    }
    cout<<ans;
}