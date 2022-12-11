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
const int N=3e5+10;

int n,m,h[N];
ii a[N];
bool comp(ii a,ii b){
    return (a.X==b.X)?a.Y<b.Y:a.X<b.X;
}
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("%d%d",&a[i].X,&a[i].Y);
        if (a[i].X>a[i].Y) swap(a[i].X,a[i].Y);
        h[a[i].X]++,h[a[i].Y]++;
    }
}
ll solve(){
    ll ans=0,ans2=0;
    sort(a+1,a+n+1,comp);
    for(int i=1;i<=n;){
        int c=0;
        while (i+c<=n&&a[i+c].X==a[i].X&&a[i].Y==a[i+c].Y) c++;
        int v=h[a[i].X]+h[a[i].Y];
        if (v>=m&&v-c<m) ans2--;
        i+=c;
    }
//    FOR(i,1,n) cout<<h[i]<<" \n"[i==n];
    sort(h+1,h+n+1);
    for(int i=1,j=n;i<=n;i++){
        while (j&&h[i]+h[j]>=m) j--;
        ans+=n-j;
        if (j<i) ans--;
    }
//    cout<<ans/2<<" "<<ans2<<'\n';
    return ans/2+ans2;
}
int main(){
    prepare();
    cout<<solve();
}